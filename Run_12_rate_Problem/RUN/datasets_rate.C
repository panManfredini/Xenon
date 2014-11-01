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
#include <stdlib.h>     /* atof */
#include <TFile.h>
using namespace std;
 
void run(){
   TSQLServer *sqlServer = TSQLServer::Connect("mysql://localhost:3306/runs","runs_reader", "1q0p2w9o");
 
   if (!sqlServer) exit(1);
   cout<<"connected to "<<sqlServer->ServerInfo()<<" server on "<<sqlServer->GetHost()<<endl;
 
   TSQLRow *row;
   TSQLResult *result;
 
   // e.g. http://dev.mysql.com/doc/refman/5.0/en/select.html

  //const char* query = "SELECT dataset_name, isotope, UNIX_TIMESTAMP(dataset_date), livetime FROM dataset INNER JOIN source USING (source_id) WHERE dataset_date > \'2009-11-01 00:00:00\' AND shield_status LIKE 'closed' AND anode_voltage = 4.5 AND cathode_voltage = 16 ORDER BY dataset_name;";
  const char* query = "SELECT dataset_name, isotope, UNIX_TIMESTAMP(dataset_date), livetime FROM dataset INNER JOIN source USING (source_id) WHERE run_id = 12  AND shield_status LIKE 'closed' AND category LIKE 'standard' ORDER BY dataset_name;";
   
   result = sqlServer->Query(query);
   const int nrows = result->GetRowCount();
   const int nfields = result->GetFieldCount();
   cout<<" resulted in "<<nfields<<" columns and "<<nrows<<" rows."<<endl;
 
//   TGraph g(nrows);
 //  TGraph g_exposure(nrows);
 
//   double exposure = 0;
   float livetime[nrows];
   float time[nrows];
  
   
   for (int i = 0; i < nrows; i++) {
	livetime[i]=0.;
	time[i]=0.;
        row = result->Next();
      TString isotope = row->GetField(1);
         if (isotope=="Dark Matter"){ 
	    const char *dataset = row->GetField(0);
	    livetime[i] = (float)(atof(row->GetField(3)) /3600./24.);
 	    time[i] = (float)(atof(row->GetField(2)) );
	   // exposure =+livetime;
	   // g.SetPoint(i+1, time, livetime);
	   // g_exposure.SetPoint(i+1, time, exposure);
//	   cout << dataset << "\t" << livetime[i] << endl; 
	   printf("%10s \t %10f \n", dataset, livetime[i]);
	}
   }      
/*
 TGraph *g = new TGraph(nrows, time, livetime);
TFile *pippo = new TFile("pippo.root","recreate");

pippo->cd();
 g->Write();
pippo->Close();
   g->GetXaxis()->SetTimeDisplay(1);
   g->GetXaxis()->SetTimeFormat("%b/%d");
g->Draw("A*");

//   TCanvas *c = new TCanvas("c", "if that were my stock values...", 0, 0, 600, 400);
  // g.GetXaxis()->SetTimeDisplay(1);
  // g.GetXaxis()->SetTimeFormat("%b/%d");
  // g.GetYaxis()->SetRangeUser(0., 30.);
///   g.Draw("a*");
//   g_exposure.SetMarkerColor(2);
 //  g_exposure.Draw("sameP");
  // c->Modified();
  // c->Update();
 
   cout<<"done :-)"<<endl;
*/

}
