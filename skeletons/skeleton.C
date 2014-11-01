#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "skeleton.h"

#ifndef skeleton_C
#define skeleton_C

skeleton::skeleton(TTree *T2,TTree *T3, TTree *T1) : XenonDataReader(T2,T3,T1) 
	{
	}

void skeleton::Loop()

{

   if (fChain == 0) return;
   if(XeT3.fChain ==0) return;
   if(XeT1.fChain ==0) return;


   TH1F *cut_flow = new TH1F("cut_flow","",50, -0.5, 49.5);
	cut_flow->GetXaxis()->SetBinLabel(1,"Tot");
	cut_flow->GetXaxis()->SetBinLabel(2,"minimumbias");
	cut_flow->GetXaxis()->SetBinLabel(3,"Xsignalnoise5");
	cut_flow->GetXaxis()->SetBinLabel(4,"Xs1width0");
	cut_flow->GetXaxis()->SetBinLabel(5,"Xentropy1");
	cut_flow->GetXaxis()->SetBinLabel(6,"Xs2peaks2");
	cut_flow->GetXaxis()->SetBinLabel(7,"Xs1coin2");
	cut_flow->GetXaxis()->SetBinLabel(8,"Xhighlog1");
	cut_flow->GetXaxis()->SetBinLabel(9,"Xs2single3");
	cut_flow->GetXaxis()->SetBinLabel(10,"Xs1single5");
	cut_flow->GetXaxis()->SetBinLabel(11,"Xveto2");
	cut_flow->GetXaxis()->SetBinLabel(12,"Xs2width11");
	cut_flow->GetXaxis()->SetBinLabel(13,"XPL013_97");
	cut_flow->GetXaxis()->SetBinLabel(14,"Xposrec1");
	cut_flow->GetXaxis()->SetBinLabel(15,"Xs2chisquare1");
	cut_flow->GetXaxis()->SetBinLabel(16,"Xlownoise0_m");
	cut_flow->GetXaxis()->SetBinLabel(17,"Xs2peakpos0");
	cut_flow->GetXaxis()->SetBinLabel(18,"X34kg2");
	cut_flow->GetXaxis()->SetBinLabel(19,"ncoin_e_s1_1");
	cut_flow->GetXaxis()->SetBinLabel(20,"ncoin_e_s1_2");
	cut_flow->GetXaxis()->SetBinLabel(21,"ncoin_e_s1_3");
	cut_flow->GetXaxis()->SetBinLabel(22,"ncoin_e_s1_4");


   Long64_t nentries = fChain->GetEntriesFast();
   bool isFirst = true;
   int start = 0;
   int last = 0;

   int nuber_of_survived_event = 0;

   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;

	fillBranches(ientry); // fill branch!

	cut_flow->Fill("Tot",1.);

//	if((*S1s)[0].empty() || (*S2s)[0].empty()) continue;
		cut_flow->Fill("minimumbias",1.);

	bool isPassed = false;
	if( !Xsignalnoise5() ) continue;
		 cut_flow->Fill("Xsignalnoise5", 1.) ;
	if( !Xs1width0() ) continue;
		 cut_flow->Fill("Xs1width0", 1.) ;
	if( !Xentropy1() ) continue;
		 cut_flow->Fill("Xentropy1", 1.) ;
	if( !Xs2peaks2() ) continue;
		 cut_flow->Fill("Xs2peaks2", 1.) ;
	if( !Xs1coin2()  ) continue;
		 cut_flow->Fill("Xs1coin2", 1.) ;
	if( !Xhighlog1() ) continue;
		 cut_flow->Fill("Xhighlog1", 1.) ; 
	if( !Xs2single3() ) continue;
		 cut_flow->Fill("Xs2single3", 1.) ;
	if( !Xs1single5() ) continue;
		 cut_flow->Fill("Xs1single5", 1.) ;
	if( !Xveto2()  ) continue;
		 cut_flow->Fill("Xveto2", 1.) ;
	if( !Xs2width11()  ) continue;
		 cut_flow->Fill("Xs2width11", 1.) ;
	if( !XPL013_97()  ) continue;
		 cut_flow->Fill("XPL013_97", 1.) ;
	if( !Xposrec1()  ) continue;
		 cut_flow->Fill("Xposrec1", 1.) ;
	if( !Xs2chisquare1()  ) continue;
		 cut_flow->Fill("Xs2chisquare1", 1.) ;
	if( !Xlownoise0_m() ) continue;
		 cut_flow->Fill("Xlownoise0_m", 1.) ;
	if( !Xs2peakpos0()  ) continue;
		 cut_flow->Fill("Xs2peakpos0", 1.) ;
	if( !X34kg2() ) continue;
		 cut_flow->Fill("X34kg2", 1.) ;

	nuber_of_survived_event++;


   }

  for(int i=1; i < cut_flow->GetNbinsX(); i++) 
	cout << cut_flow->GetXaxis()->GetBinLabel(i) << "   " << cut_flow->GetBinContent(i)<< endl;
 
  TString dataset_name_full = XeT1.Filename;
  TString dataset_name(dataset_name_full(0,17));
	
  cut_flow->Print("all");

  TString type("");
  double livetime = DatasetLivetime(dataset_name, type);
  cout << "Corrected Live Time " <<  livetime << endl;
  TH1F *skeleton = new TH1F("skeleton","skeleton VS dataset time",80000,1200000000.,1500000000.); // unixtime from 208 to 2017 in bin o ~1h
  skeleton->GetXaxis()->SetTitle("Date");
  skeleton->GetYaxis()->SetTitle("Event Rate / day [day^{-1}]");
  skeleton->GetXaxis()->SetTimeDisplay(1);
  skeleton->GetXaxis()->SetTimeFormat("%b");
  
  skeleton->Fill( XeT1.TimeSec, (float)nuber_of_survived_event/livetime);
  skeleton->SetBinError(skeleton->FindBin( XeT1.TimeSec), sqrt((float)nuber_of_survived_event)/livetime);

  TH1F *h_livetime = new TH1F("h_livetime","livetime VS dataset time",80000,1200000000.,1500000000.); // unixtime from 208 to 2017 in bin o ~1h
  h_livetime->GetXaxis()->SetTitle("Date");
  h_livetime->GetYaxis()->SetTitle("Livetime [days]");
  h_livetime->GetXaxis()->SetTimeDisplay(1);
  h_livetime->GetXaxis()->SetTimeFormat("%b");
  h_livetime->Fill( XeT1.TimeSec, livetime);


  TFile *file = new TFile(outDir + "cutFlow_" + filename ,"RECREATE");
  file->cd();
  cut_flow->Write(dataset_name); // if same dataset has more files will be hadd correctly
  skeleton->Write();
  h_livetime->Write();
  file->Close();
  delete file;
}	

#endif
