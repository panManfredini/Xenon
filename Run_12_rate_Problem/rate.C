#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "rate.h"

#ifndef rate_C
#define rate_C

rate::rate(TTree *T2,TTree *T3, TTree *T1) : XenonDataReader(T2,T3,T1) 
	{
	}

void rate::Loop()
{

   if (fChain == 0) return;
   if(XeT3.fChain ==0) return;
   if(XeT1.fChain ==0) return;

  
//------------------------HISTOS---------------------------------------------//
   TH1F *cut_flow = new TH1F("cut_flow","",50, -0.5, 49.5);
	cut_flow->GetXaxis()->SetBinLabel(1,"Tot");
	cut_flow->GetXaxis()->SetBinLabel(2,"bruno_basic");
	cut_flow->GetXaxis()->SetBinLabel(3,"X48kg0");
	cut_flow->GetXaxis()->SetBinLabel(4,"S1Tot_3_20");
	cut_flow->GetXaxis()->SetBinLabel(5,"X34kg2");
	cut_flow->GetXaxis()->SetBinLabel(6,"Livetime");
	cut_flow->GetXaxis()->SetBinLabel(7,"timeStart");
	cut_flow->GetXaxis()->SetBinLabel(8,"timeStop");
        cut_flow->Sumw2();


   TH1F *rate_r = new TH1F("rate_r","rate in volume integrating in Z",1000, 0., 200.);
   TH1F *rate_z = new TH1F("rate_z","rate in volume integrating in R",1000, -400., 0.);

   TH2F *rate_S1_S2 = new TH2F("rate_S1_S2","rate in volume for S1 VS S2",50, 0., 50.,500, 0.,10000.);
   rate_S1_S2->Sumw2();
   rate_S1_S2->GetXaxis()->SetTitle("cxS1s[0]  [PE]");
   rate_S1_S2->GetYaxis()->SetTitle("cS2s[0]  [PE]");
   
   
   TH2F *rate_2d_SR = new TH2F("rate_2d_SR","rate in Z and R",200, -5.,195.,40, -395., 5. );
   rate_2d_SR->Sumw2();
   rate_2d_SR->GetXaxis()->SetTitle("R [mm]");
   rate_2d_SR->GetYaxis()->SetTitle("Z [mm]");

   TH2F *rate_2d_48kg = new TH2F("rate_2d_48kg","rate in Z and R",200, -5.,195.,40, -395., 5. );
   rate_2d_48kg->Sumw2();
   rate_2d_48kg->GetXaxis()->SetTitle("R [mm]");
   rate_2d_48kg->GetYaxis()->SetTitle("Z [mm]");

   TH1F *total_livetime = new TH1F("total_livetime","integral of livetime",1, -0.5, 0.5);

   rate_r->Sumw2();
   rate_z->Sumw2();

  // unixtime from 2008 to 2017 in bin of 10min
    TH1F *rate_bruno = new TH1F("rate_bruno","rate VS dataset time",500000,1200000000.,1500000000.); 
    TH1F *rate_48kg = new TH1F("rate_48kg","rate VS dataset time",500000,1200000000.,1500000000.);
    TH1F *rate_SR = new TH1F("rate_SR","rate VS dataset time",500000,1200000000.,1500000000.); 
    TH1F *h_livetime = new TH1F("h_livetime","livetime VS dataset time",500000,1200000000.,1500000000.); 
    TH1F *time_start = new TH1F("time_start","start time of dataset",500000,1200000000.,1500000000.);
    TH1F *time_end = new TH1F("time_end","start time of dataset",500000,1200000000.,1500000000.);

    TH1F *event_time_bruno = new TH1F("event_time_bruno","Events per 10 min",144,0.,86400.);
    TH1F *event_time_48kg = new TH1F("event_time_48kg","Events per 10 min",144,0.,86400.);
    TH1F *event_time_SR = new TH1F("event_time_SR","Events per 10 min",144,0.,86400.);

    event_time_SR->Sumw2();
    event_time_48kg->Sumw2();
    event_time_bruno->Sumw2();

    h_livetime->GetXaxis()->SetTitle("Date");
    h_livetime->GetYaxis()->SetTitle("Livetime [days]");
    h_livetime->GetXaxis()->SetTimeDisplay(1);
    h_livetime->GetXaxis()->SetTimeFormat("%b");

    time_start->GetXaxis()->SetTitle("Date");
    time_start->GetYaxis()->SetTitle("Livetime [days]");
    time_start->GetXaxis()->SetTimeDisplay(1);
    time_start->GetXaxis()->SetTimeFormat("%b");

    time_end->GetXaxis()->SetTitle("Date");
    time_end->GetYaxis()->SetTitle("Livetime [days]");
    time_end->GetXaxis()->SetTimeDisplay(1);
    time_end->GetXaxis()->SetTimeFormat("%b");

    rate_bruno->GetXaxis()->SetTitle("Date");
    rate_bruno->GetYaxis()->SetTitle("Event Rate / day [day^{-1}]");
    rate_bruno->GetXaxis()->SetTimeDisplay(1);
    rate_bruno->GetXaxis()->SetTimeFormat("%b");
  
    rate_48kg->GetXaxis()->SetTitle("Date");
    rate_48kg->GetYaxis()->SetTitle("Event Rate / day [day^{-1}]");
    rate_48kg->GetXaxis()->SetTimeDisplay(1);
    rate_48kg->GetXaxis()->SetTimeFormat("%b");
  
    rate_SR->GetXaxis()->SetTitle("Date");
    rate_SR->GetYaxis()->SetTitle("Event Rate / day [day^{-1}]");
    rate_SR->GetXaxis()->SetTimeDisplay(1);
    rate_SR->GetXaxis()->SetTimeFormat("%b");
  //---------------------------------------------//

  TH1F *rate_all = new TH1F("rate_all","rate",1000,-0.01,19.99); 
  TH1F *event_reduced = new TH1F("event_reduced","",1000,-5.005,4.995); 


//---------------------------------------------------------------------------------//


//------------------LOOP-------------------------------------------------------//   
   Long64_t nentries = fChain->GetEntriesFast();
   
   bool isFirst = true;
   int start = 0;
   int end = 0;

   int counter = 0;

   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;

	fillBranches(ientry); // fill branch!

	if(isFirst) { start = XeT1.TimeSec ;  isFirst=false;} // time of first measure s

	cut_flow->Fill("Tot",1.);
	
	if(!run_12_bruno()) continue;
		cut_flow->Fill("bruno_basic",1.);
		event_time_bruno->Fill(XeT1.TimeSec - start);

	if(!X48kg0()) continue;
		cut_flow->Fill("X48kg0",1.);
		event_time_48kg->Fill(XeT1.TimeSec - start );
   	
		rate_S1_S2->Fill(XeT3.cxS1sTot->at(0), XeT3.cS2sTot->at(0));
		rate_2d_48kg->Fill(R(), Z());	

	if( XeT3.cxS1sTot->at(0) >= 20. || XeT3.cxS1sTot->at(0) <= 3. ) continue;
		cut_flow->Fill("S1Tot_3_20",1.);
		event_time_SR->Fill(XeT1.TimeSec - start );

	for(int i=1; i < rate_r->GetNbinsX(); i++)
		{
		if(R() < rate_r->GetBinLowEdge(i) ) rate_r->Fill(rate_r->GetBinCenter(i));
		if(Z() < rate_z->GetBinLowEdge(i) ) rate_z->Fill(rate_z->GetBinCenter(i));
		}

		rate_2d_SR->Fill(R(), Z());	

        counter++;

	if(!X34kg2()) continue;
		cut_flow->Fill("X34kg2",1.);
	
   }

//--------------------------------------------------------------//

//---------------------FINALISE---------------------------------------------------//
   
  end = XeT1.TimeSec;  //time of last measure in s

  TString dataset_name_full = XeT1.Filename;
  TString dataset_name(dataset_name_full(0,17));

  TString type("NONE");
  double livetime = DatasetLivetime(dataset_name, type);
  cout << "\nDataset Type:  " << type << endl;
  cout << "Corrected Live Time " <<  livetime << " days  =  " << livetime * 24. * 3600. << " sec" << endl;

  total_livetime->Fill(0., livetime);

  cut_flow->Fill("Livetime",livetime);
  cut_flow->Fill("timeStart",start);
  cut_flow->Fill("timeStop",end);

  cout << "\n--------------------------------------\n-----------------CUTFLOW--------------\n--------------------------------------" << endl;
  for(int i=1; i < 7; i++) 
	cout << cut_flow->GetXaxis()->GetBinLabel(i) << "   " << cut_flow->GetBinContent(i) << "  --> Rate = " << 
		cut_flow->GetBinContent(i) / livetime << endl;


  time_start->Fill(start, 1.);
  time_end->Fill(end, 1.);
  h_livetime->Fill( start, livetime);

  rate_bruno->Fill( start, cut_flow->GetBinContent(2) / livetime);
  rate_bruno->SetBinError(rate_bruno->FindBin( start), cut_flow->GetBinError(2) /livetime);

  rate_48kg->Fill( start, cut_flow->GetBinContent(3) / livetime);
  rate_48kg->SetBinError(rate_48kg->FindBin( start), cut_flow->GetBinError(3) /livetime);

  rate_SR->Fill( start, cut_flow->GetBinContent(4) / livetime);
  rate_SR->SetBinError(rate_SR->FindBin(start), cut_flow->GetBinError(4) /livetime);

  event_reduced->Fill( ((float)counter - 2.409 * livetime )/sqrt(2.409*livetime));

  rate_all->Fill( (float)counter / livetime );


  TFile *file = new TFile(outDir + "rate_" + filename ,"RECREATE");
  file->cd();

  cut_flow->Write(dataset_name+"_"+type); // if same dataset has more files will be hadd correctly
  rate_bruno->Write("rate_bruno_"+type);
  rate_48kg->Write("rate_48kg_"+type);
  rate_SR->Write("rate_SR_"+type);
  event_time_bruno->Write("event_time_bruno_"+dataset_name+"_"+type);
  event_time_48kg->Write("event_time_48kg_"+dataset_name+"_"+type);
  event_time_SR->Write("event_time_SR_"+dataset_name+"_"+type);
  h_livetime->Write("livetime_"+type);
  total_livetime->Write("total_livetime_"+type);
  rate_z->Write("rate_z_"+type);
  rate_r->Write("rate_r_"+type);
  rate_all->Write("rate_all_"+type);
  event_reduced->Write("event_reduced_"+type);
  time_start->Write("time_start_"+type);
  time_end->Write("time_end_"+type);
  rate_2d_SR->Write("rate_2d_SR_"+dataset_name+"_"+type);
  rate_2d_48kg->Write("rate_2d_48kg_"+dataset_name+"_"+type);
  rate_S1_S2->Write("rate_SS_"+dataset_name+"_"+type);

  file->Close();
  delete file;

//-----------------------------------------//
}

  bool  rate::		run_12_bruno()
	{
	return ( Xsignalnoise5() && Xs1width0() && Xentropy1() && Xs2peaks2() && Xs1coin2() && Xhighlog1()
		&& Xs2single3() && Xs1single5() && Xveto2()  && Xs2width11() && XPL013_97() && Xposrec1() 
		&& Xs2chisquare1() && Xlownoise0_m() && Xs2peakpos0()) ;
	}

#endif
