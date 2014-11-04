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

  
   Initialize();

   TH1F *cut_flow = new TH1F("cut_flow","",50, -0.5, 49.5);
	cut_flow->GetXaxis()->SetBinLabel(1,"Tot");
	cut_flow->GetXaxis()->SetBinLabel(2,"bruno_basic");
	cut_flow->GetXaxis()->SetBinLabel(3,"X48kg0");
	cut_flow->GetXaxis()->SetBinLabel(4,"S1Tot_3_20");
	cut_flow->GetXaxis()->SetBinLabel(5,"Xs2peakpos0");
	cut_flow->GetXaxis()->SetBinLabel(6,"X34kg2");
	cut_flow->GetXaxis()->SetBinLabel(7,"Livetime");
       cut_flow->Sumw2();


   TH1F *rate_r = new TH1F("rate_r","rate in volume integrating in Z",1000, 0., 200.);
   TH1F *rate_z = new TH1F("rate_z","rate in volume integrating in R",1000, -400., 0.);

   TH2F *rate_S1_S2 = new TH2F("rate_S1_S2","rate in volume for S1 VS S2",50, 0., 50.,500, 0.,10000.);
   rate_S1_S2->Sumw2();
   rate_S1_S2->GetXaxis()->SetTitle("cxS1s[0]  [PE]");
   rate_S1_S2->GetYaxis()->SetTitle("cS2s[0]  [PE]");
   
   
   TH2F *rate_2d = new TH2F("rate_2d","rate in Z and R",200, -5.,195.,40, -395., 5. );
   rate_2d->Sumw2();

   TH1F *total_livetime = new TH1F("total_livetime","integral of livetime",1, -0.5, 0.5);

   rate_r->Sumw2();
   rate_z->Sumw2();
   
   Long64_t nentries = fChain->GetEntriesFast();
   bool isFirst = true;
   int start = 0;
   int last = 0;

   int counter = 0;

   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;

	fillBranches(ientry); // fill branch!

	cut_flow->Fill("Tot",1.);
	
	if(!run_12_bruno()) continue;
		cut_flow->Fill("bruno_basic",1.);

//	if(!X48kg0()) continue;
		cut_flow->Fill("X48kg0",1.);

//	if( XeT3.cxS1sTot->at(0) >= 20. || XeT3.cxS1sTot->at(0) <= 3. ) continue;
		cut_flow->Fill("S1Tot_3_20",1.);

	if(!Xs2peakpos0()) continue;
		cut_flow->Fill("Xs2peakpos0",1.);
		counter++;
	for(int i=1; i < rate_r->GetNbinsX(); i++)
		{
		if(R() < rate_r->GetBinLowEdge(i) ) rate_r->Fill(rate_r->GetBinCenter(i));
		if(Z() < rate_z->GetBinLowEdge(i) ) rate_z->Fill(rate_z->GetBinCenter(i));
		}

	rate_2d->Fill(R(), Z());	
   	rate_S1_S2->Fill(XeT3.cxS1sTot->at(0), XeT3.cS2sTot->at(0));

	if(!X34kg2()) continue;
		cut_flow->Fill("X34kg2",1.);
	
   }


 
  TString dataset_name_full = XeT1.Filename;
  TString dataset_name(dataset_name_full(0,17));

  TString type("");

  double livetime = DatasetLivetime(dataset_name, type);
  cout << "Corrected Live Time " <<  livetime << " days  =  " << livetime * 24. * 3600. << " sec" << endl;

  total_livetime->Fill(0., livetime);

  cut_flow->Fill("Livetime",livetime);

  //rate_r->Scale(1./livetime);
  ///rate_z->Scale(1./livetime);

  for(int i=1; i < 7; i++) 
	cout << cut_flow->GetXaxis()->GetBinLabel(i) << "   " << cut_flow->GetBinContent(i) << "  --> Rate = " << 
		cut_flow->GetBinContent(i) / livetime << endl;

//  cut_flow->Scale(1./livetime);

  TH1F *rate_bruno = new TH1F("rate_bruno","rate VS dataset time",80000,1200000000.,1500000000.); // unixtime from 208 to 2017 in bin o ~1h
  TH1F *rate_peakpos = new TH1F("rate_peakpos","rate VS dataset time",80000,1200000000.,1500000000.); // unixtime from 208 to 2017 in bin o ~1h
  TH1F *rate_34kg = new TH1F("rate_34kg","rate VS dataset time",80000,1200000000.,1500000000.); // unixtime from 208 to 2017 in bin o ~1h

  TH1F *rate_all = new TH1F("rate_all","rate",1000,-0.01,19.99); // unixtime from 208 to 2017 in bin o ~1h
  TH1F *event_reduced = new TH1F("event_reduced","",1000,-5.005,4.995); // unixtime from 208 to 2017 in bin o ~1h

  rate_bruno->GetXaxis()->SetTitle("Date");
  rate_bruno->GetYaxis()->SetTitle("Event Rate / day [day^{-1}]");
  rate_bruno->GetXaxis()->SetTimeDisplay(1);
  rate_bruno->GetXaxis()->SetTimeFormat("%b");
  
  rate_peakpos->GetXaxis()->SetTitle("Date");
  rate_peakpos->GetYaxis()->SetTitle("Event Rate / day [day^{-1}]");
  rate_peakpos->GetXaxis()->SetTimeDisplay(1);
  rate_peakpos->GetXaxis()->SetTimeFormat("%b");
  
  rate_34kg->GetXaxis()->SetTitle("Date");
  rate_34kg->GetYaxis()->SetTitle("Event Rate / day [day^{-1}]");
  rate_34kg->GetXaxis()->SetTimeDisplay(1);
  rate_34kg->GetXaxis()->SetTimeFormat("%b");
  
  rate_bruno->Fill( XeT1.TimeSec, cut_flow->GetBinContent(4) / livetime);
  rate_bruno->SetBinError(rate_bruno->FindBin( XeT1.TimeSec), cut_flow->GetBinError(4) /livetime);

  rate_peakpos->Fill( XeT1.TimeSec, cut_flow->GetBinContent(5) / livetime);
  rate_peakpos->SetBinError(rate_peakpos->FindBin( XeT1.TimeSec), cut_flow->GetBinError(5) /livetime);

  rate_34kg->Fill( XeT1.TimeSec, cut_flow->GetBinContent(6) / livetime);
  rate_34kg->SetBinError(rate_34kg->FindBin( XeT1.TimeSec), cut_flow->GetBinError(6) /livetime);

  event_reduced->Fill( ((float)counter - 2.409 * livetime )/sqrt(2.409*livetime));

  TH1F *h_livetime = new TH1F("h_livetime","livetime VS dataset time",80000,1200000000.,1500000000.); // unixtime from 208 to 2017 in bin o ~1h
  TH1F *h_test = new TH1F("h_test","livetime VS dataset time",80000,1200000000.,1500000000.); // unixtime from 208 to 2017 in bin o ~1h

  h_livetime->GetXaxis()->SetTitle("Date");
  h_livetime->GetYaxis()->SetTitle("Livetime [days]");
  h_livetime->GetXaxis()->SetTimeDisplay(1);
  h_livetime->GetXaxis()->SetTimeFormat("%b");
  h_livetime->Fill( XeT1.TimeSec, livetime);
  h_test->Fill( XeT1.TimeSec, 1.);

  rate_all->Fill( (float)counter / livetime );

  TFile *file = new TFile(outDir + "cutFlow_" + filename ,"RECREATE");
  file->cd();

  cut_flow->Write(dataset_name); // if same dataset has more files will be hadd correctly
  rate_bruno->Write();
  rate_peakpos->Write();
  rate_34kg->Write();
  h_livetime->Write();
  total_livetime->Write();
  rate_z->Write();
  rate_r->Write();
  rate_all->Write();
  event_reduced->Write();
  h_test->Write();
  rate_2d->Write("rate_2d_"+dataset_name);
  rate_S1_S2->Write("rate_SS_"+dataset_name);

  file->Close();
  delete file;
}

  bool  rate::		run_12_bruno()
	{
	return ( Xsignalnoise5() && Xs1width0() && Xentropy1() && Xs2peaks2() && Xs1coin2() && Xhighlog1()
		&& Xs2single3() && Xs1single5() && Xveto2()  && Xs2width11() && XPL013_97() && Xposrec1() 
		&& Xs2chisquare1() && Xlownoise0_m() ) ;
	}

#endif
