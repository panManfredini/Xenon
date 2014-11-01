// sample script to play with the XENON100 run and slow control SQL databases
// includes quite some verbosity to demonstrate some commands
// Rafael, February 2010
//
// you can run this script on xecluster with
//   $ root
//   root [0] .x sqlselect.cxx
// or, better (because more reliably: CINT sucks) and faster, compiled:
//   $ root
//   root [0] gROOT->LoadMacro("sqlselect.cxx+");
//   root [1] sqlselect();
//
// if you have root with the SQL libraries installed locally, you can also 
// run it on your local machine. build an ssh tunnel from your port 3307
// to port 3306 on xecluster:
//   $ ssh -f -L 3307:xecluster01:3306 -N rlang@xecluster.lngs.infn.it
// and modify the TSQLServer constructor below accordingly
// to use your local port 3307, e.g.
// TSQLServer *sqlServer = TSQLServer::Connect("mysql://localhost:3307/runs","runs_reader", "1q0p2w9o");
//
#include <TAxis.h>
#include <TCanvas.h>
#include <TGraph.h>
#include <TIterator.h>
#include <TList.h>
#include <TMultiGraph.h>
#include <TSQLServer.h>
#include <TSQLResult.h>
#include <TSQLRow.h>
#include <fstream>
#include <iostream>
using namespace std;
 
void sqlselect() {      
   // do not fear. with the _reader users, you can only SELECT, not DESTROY anything ;-)
   // the run database:
   TSQLServer *sqlServer = TSQLServer::Connect("mysql://localhost:3306/runs","runs_reader", "1q0p2w9o");
//   TSQLServer *sqlServer = TSQLServer::Connect("mysql://xecluster01:3306/scs", "scs_reader",  "fr45ju76"); //xecluster
   // the slow control database:
   // TSQLServer *sqlServer = TSQLServer::Connect("mysql://localhost:3306/scs", "scs_reader",  "fr45ju76");
 
   if (!sqlServer) exit(1);
   cout<<"connected to "<<sqlServer->ServerInfo()<<" server on "<<sqlServer->GetHost()<<endl;
 
   // objects to hold the information
   TSQLRow *row;
   TSQLResult *result;
 
   // get a list of stuff in the runs database
 
   TList* lst = sqlServer->GetTablesList();
   TIter next(lst);
   TObject* object;
   while ((object = next())) {
     TString tableName = object->GetName();
     cout<<"table '"<< tableName << "' contains the columns " << endl;
     // for the runs database:
     result = sqlServer->GetColumns("runs", tableName);
     // or, for the slow control database:
     //result = sqlServer->GetColumns("scs", tableName);
     while ((row = result->Next())) {
        cout<<"   "<<row->GetField(0)<<endl;
        delete row;
     }
     delete result;
     }
   delete lst;
 
   // example: make a plot with collected lifetimes of various data sets
   const int datasets = 4;
   TString isotopes[datasets] = {"Dark Matter", "Background", "Co60", "AmBe"};
   int isotopes_colors[datasets] = {602, 604, 418, 632};
   int isotopes_scaling[datasets] = {1, 1, 1, 1}; // {1, 1, 120, 400} is the [0;100]PE rate equivalent
   TGraph* graph[datasets];
 
   TMultiGraph* gLiveTimes = new TMultiGraph("gLiveTimes", "XENON100 Data Taking;Date;Live Days");
   for (int d = 0; d<datasets; d++) {
      graph[d] = new TGraph();
      graph[d]->SetName(isotopes[d]);
      graph[d]->SetLineColor(isotopes_colors[d]);
      graph[d]->SetPoint(0, 1257000000, 0);
      gLiveTimes->Add(graph[d], "l");
   }
 
   // etc. probably you want to look at some 
   // help for the SQL SELECT syntax, 
   // e.g. http://dev.mysql.com/doc/refman/5.0/en/select.html
   const char* query = "SELECT dataset_name, isotope, UNIX_TIMESTAMP(dataset_date), livetime FROM dataset INNER JOIN source USING (source_id) WHERE dataset_date > \'2009-11-01 00:00:00\' AND shield_status LIKE 'closed' AND anode_voltage = 4.5 AND cathode_voltage = 16 ORDER BY dataset_name;";
   // const char* query = "SELECT dataset_name, isotope, UNIX_TIMESTAMP(dataset_date), livetime FROM dataset INNER JOIN source USING (source_id) WHERE dataset_date > \'2009-11-01 00:00:00\' AND shield_status LIKE 'closed' AND anode_voltage = 4.5 AND cathode_voltage = 16 AND isotope LIKE 'Dark Matter' ORDER BY dataset_name;";
   cout<<"querying..."; cout.flush();
   result = sqlServer->Query(query);
   const int nrows = result->GetRowCount();
   const int nfields = result->GetFieldCount();
   cout<<" resulted in "<<nfields<<" columns and "<<nrows<<" rows."<<endl;
 
   // if you can be bothered to know...
   /*
   for (int i = 0; i < nfields; i++) cout<<result->GetFieldName(i)<<"\t";
   cout<<endl;
   */
 
   double lastTimeStamp = 0;
   for (int i = 0; i < nrows; i++) {
      row = result->Next();
 
      // if you can be boethered to know...
      /*
      for (int j = 0; j < nfields; j++) {
         if (row->GetFieldLength(j) && ((j<2)||(j==3)) ) cout<<row->GetField(j)<<"\t\t";
      }
      cout<<endl;
      // */
 
      // in case you want to output field information like here, 
      // make sure you check that the fields are actually filled
      /*
      if (row->GetFieldLength(0) && row->GetFieldLength(3)) 
	cout<<"    AddFile(path+\""<<row->GetField(0)<<".root\"); lifetime+="<<row->GetField(3)<<";"<<endl;
      // */
 
      TString isotope = row->GetField(1);
      for (int d = 0; d<datasets; d++) {
         if (isotope==isotopes[d]) {
	    int n = graph[d]->GetN();
	    double time = 0;
	    double exposure = 0;
	    double livetime = atof(row->GetField(3));
	    graph[d]->GetPoint(n-1, time, exposure);
	    graph[d]->SetPoint(n,   atof(row->GetField(2)), exposure);
	    lastTimeStamp = atof(row->GetField(2))+livetime;
	    graph[d]->SetPoint(n+1, lastTimeStamp, exposure + livetime/3600./24.*isotopes_scaling[d]  );
	 }
      }      
      delete row;
   }
   delete result;
   delete sqlServer;
 
   for (int d = 0; d<datasets; d++) {
      int n = graph[d]->GetN();
      double time, exposure;
      graph[d]->GetPoint(n-1, time, exposure);
      graph[d]->SetPoint(n, lastTimeStamp, exposure);
   }
 
   TCanvas *c = new TCanvas("c", "if that were my stock values...", 0, 0, 600, 400);
   gLiveTimes->Draw("a");
   gLiveTimes->GetXaxis()->SetTimeDisplay(1);
   gLiveTimes->GetXaxis()->SetTimeFormat("%b/%d");
   gLiveTimes->GetYaxis()->SetRangeUser(0., 30.);
   c->Modified();
   c->Update();
 
   cout<<"done :-)"<<endl;
}
