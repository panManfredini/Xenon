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
 
void print_dataset_for_reader(){
   TSQLServer *sqlServer = TSQLServer::Connect("mysql://localhost:3306/runs","runs_reader", "1q0p2w9o");
 
   if (!sqlServer) exit(1);
   cout<<"connected to "<<sqlServer->ServerInfo()<<" server on "<<sqlServer->GetHost()<<endl;
 
   TSQLRow *row;
   TSQLResult *result;
 
   // e.g. http://dev.mysql.com/doc/refman/5.0/en/select.html

  //const char* query = "SELECT dataset_name, isotope, UNIX_TIMESTAMP(dataset_date), livetime FROM dataset INNER JOIN source USING (source_id) WHERE dataset_date > \'2009-11-01 00:00:00\' AND shield_status LIKE 'closed' AND anode_voltage = 4.5 AND cathode_voltage = 16 ORDER BY dataset_name;";
  const char* query = "SELECT dataset_name, isotope, UNIX_TIMESTAMP(dataset_date), corrected_livetime FROM dataset INNER JOIN source USING (source_id) WHERE run_id = 12  AND shield_status LIKE 'closed' AND category LIKE 'standard' ORDER BY dataset_name;";
   
   result = sqlServer->Query(query);
   const int nrows = result->GetRowCount();
   const int nfields = result->GetFieldCount();
   cout<<" resulted in "<<nfields<<" columns and "<<nrows<<" rows."<<endl;
 
  
   
   for (int i = 0; i < nrows; i++) {
        row = result->Next();
        const char *isotope = row->GetField(1);
	const char *dataset = row->GetField(0);
	double livetime = atof(row->GetField(3)) /3600./24.;
	//---Print dataset name for RUN ------//
		cout << "mb_" << dataset << ".root"<<endl;
	//---Print Syntax for DataReader ------------//
	//cout << "\t if(dataset_name == \"" << dataset << "\") { livetime = "<<livetime <<"; isotope = \""<<isotope<<"\"; return livetime;}"<<endl;
   }      

}
