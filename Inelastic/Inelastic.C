#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "Inelastic.h"

#ifndef Inelastic_C
#define Inelastic_C

Inelastic::Inelastic(TTree *T2,TTree *T3, TTree *T1) : XenonDataReader(T2,T3,T1) 
	{
	}

void Inelastic::Loop()

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

    TH2D *s1_s2 = new TH2D("s1_s2","",1000,0.,500., 1000,0.,4.);
    TH2D *s1_s2_roteated = new TH2D("s1_s2_roteated","Rotated",1000,0.,500., 1000,0.,4.);
    TH2D *s1_s2_roteated_woSR = new TH2D("s1_s2_roteated_woSR","Rotated",1000,0.,500., 1000,0.,4.);
    TH2D *s1_s2_flat = new TH2D("s1_s2_flat","flatened",1000,0.,500., 1000,-4.,4.);
    TH2D *s1_s2_flat_woSR = new TH2D("s1_s2_flat_woSR","flatened",1000,0.,500., 1000,-4.,4.);

    s1_s2->GetXaxis()->SetTitle("cxS1sTot[0]  [PE]");
    s1_s2->GetYaxis()->SetTitle("log10(cS2sTotBottom[0] / cxS1sTot[0])" );
    s1_s2->Sumw2();

    s1_s2_roteated->GetXaxis()->SetTitle("cxS1sTot[0]  [PE]");
    s1_s2_roteated->GetYaxis()->SetTitle("log10(cS2sTotBottom[0] / cxS1sTot[0])" );
    s1_s2_roteated->Sumw2();

    s1_s2_roteated_woSR->GetXaxis()->SetTitle("cxS1sTot[0]  [PE]");
    s1_s2_roteated_woSR->GetYaxis()->SetTitle("log10(cS2sTotBottom[0] / cxS1sTot[0])" );
    s1_s2_roteated_woSR->Sumw2();

    s1_s2_flat->GetXaxis()->SetTitle("cxS1sTot[0]  [PE]");
    s1_s2_flat->GetYaxis()->SetTitle("Flattened E-band" );
    s1_s2_flat->Sumw2();

    s1_s2_flat_woSR->GetXaxis()->SetTitle("cxS1sTot[0]  [PE]");
    s1_s2_flat_woSR->GetYaxis()->SetTitle("Flattened E-band" );
    s1_s2_flat_woSR->Sumw2();

   Long64_t nentries = fChain->GetEntriesFast();
   bool isFirst = true;
   int start = 0;
   int last = 0;

   int nuber_of_survived_event_tot = 0;
   int nuber_of_survived_event_1 = 0;
   int nuber_of_survived_event_2 = 0;
   int nuber_of_survived_event_3 = 0;

   TString dataset_name_full = "NONE";
   TString dataset_name = "NONE";
   TString type("");
   double livetime =0.;


   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;

	fillBranches(ientry); // fill branch!

	if(isFirst) {
  		dataset_name_full = XeT1.Filename;
  		dataset_name = dataset_name_full(0,17) ;
  		livetime = DatasetLivetime(dataset_name, type);
		isFirst = false;
	}

	cut_flow->Fill("Tot",1.);

//	if((*S1s)[0].empty() || (*S2s)[0].empty()) continue;
	cut_flow->Fill("minimumbias",1.);

   	nuber_of_survived_event_tot++;

	bool isPassed = false;

	if(!(X34kg2() && Xsignalnoise3() && Xsignalnoise4() && Xs1width0() && Xlownoise0_m())) continue;
	//if(!(X48kg0() && Xsignalnoise3() && Xsignalnoise4() && Xs1width0() && Xlownoise0_m())) continue;
	 nuber_of_survived_event_1++;
	if( !(Xentropy0() && Xs2top0() && Xs2peaks2() && Xs1coin2() && Xhighlog1() && Inelastic_Xs2single0())) continue;
	 nuber_of_survived_event_2++;
	if(!(Xs1single4() && Xveto2() &&  XPL013_97() && Xposrec1() && Xs2chisquare0() && Xs2peakpos0()) ) continue;
	//if(!(Xs1single4() && Xveto2() && Xs2width0() && XPL013_97() && Xposrec1() && Xs2chisquare0() && Xs2peakpos0()) ) continue;
	//To be redefined Xs2width0 !!!!!
	 nuber_of_survived_event_3++;


	double 	log_s2_over_s1 = log10(XeT3.cS2sTotBottom->at(0) / XeT3.cxS1sTot->at(0) );
	double  cxS1sTot_0 = XeT3.cxS1sTot->at(0) ;

	//Rotation of rad +5.32520966224929882e-03 
	double R_s1 = XeT3.cxS1sTot->at(0) * cos(5.32520966224929882e-03) - log_s2_over_s1*sin(5.32520966224929882e-03);
	double R_log_s2_over_s1 = XeT3.cxS1sTot->at(0)*sin(5.32520966224929882e-03) + log_s2_over_s1*cos(5.32520966224929882e-03);
	double log_in_flatten_space = log_s2_over_s1 - ( 0.851871341917*exp(-0.22757830222*cxS1sTot_0 - 0.353347482389) + 2.23830102898
					 - 0.0155751664656*cxS1sTot_0 + 0.000330774244527*pow(cxS1sTot_0,2)  - 3.3540798353e-06*pow(cxS1sTot_0,3)
  					 + 1.8403163772e-08*pow(cxS1sTot_0,4) - 5.38060987425e-11*pow(cxS1sTot_0,5)  + 6.63604860059e-14*pow(cxS1sTot_0,6) );

	// Blinding SR
//        if(type == "DM" && R_s1> 60. && R_s1 < 200. && R_log_s2_over_s1 > 2.3 && R_log_s2_over_s1 < 2.7)  continue;

	s1_s2->Fill(XeT3.cxS1sTot->at(0) , log_s2_over_s1); 
	s1_s2_roteated->Fill(R_s1,R_log_s2_over_s1);
	s1_s2_flat->Fill(cxS1sTot_0 , log_in_flatten_space);

        if(!(R_s1> 60. && R_s1 < 200. && R_log_s2_over_s1 > 2.3 && R_log_s2_over_s1 < 2.7))
	  {
		s1_s2_roteated_woSR->Fill(R_s1,R_log_s2_over_s1);
		s1_s2_flat_woSR->Fill(cxS1sTot_0 , log_in_flatten_space);
 	  }
	
   }

	cout << "CutFlow for " << dataset_name << endl;
  	cout << "Type " <<  type << endl;
  	cout << "Corrected Live Time " <<  livetime << endl;
	cout <<"TOT " <<  nuber_of_survived_event_tot << endl;
	cout << "Set 1  " << nuber_of_survived_event_1 << endl;
	cout << "Set 2  "<< nuber_of_survived_event_2 << endl;
	cout << "Set 3  " << nuber_of_survived_event_3 << endl;
	
/*
  for(int i=1; i < cut_flow->GetNbinsX(); i++) 
	cout << cut_flow->GetXaxis()->GetBinLabel(i) << "   " << cut_flow->GetBinContent(i)<< endl;
 
	
  cut_flow->Print("all");

  TH1F *Inelastic = new TH1F("Inelastic","Inelastic VS dataset time",80000,1200000000.,1500000000.); // unixtime from 208 to 2017 in bin o ~1h
  Inelastic->GetXaxis()->SetTitle("Date");
  Inelastic->GetYaxis()->SetTitle("Event Rate / day [day^{-1}]");
  Inelastic->GetXaxis()->SetTimeDisplay(1);
  Inelastic->GetXaxis()->SetTimeFormat("%b");
  
  Inelastic->Fill( XeT1.TimeSec, (float)nuber_of_survived_event/livetime);
  Inelastic->SetBinError(Inelastic->FindBin( XeT1.TimeSec), sqrt((float)nuber_of_survived_event)/livetime);

  TH1F *h_livetime = new TH1F("h_livetime","livetime VS dataset time",80000,1200000000.,1500000000.); // unixtime from 208 to 2017 in bin o ~1h
  h_livetime->GetXaxis()->SetTitle("Date");
  h_livetime->GetYaxis()->SetTitle("Livetime [days]");
  h_livetime->GetXaxis()->SetTimeDisplay(1);
  h_livetime->GetXaxis()->SetTimeFormat("%b");
  h_livetime->Fill( XeT1.TimeSec, livetime);

*/
  TFile *file = new TFile(outDir + "cutFlow_" + filename ,"RECREATE");
  file->cd();
  file->mkdir("cuflows");
  cut_flow->Write("cuflows/"+ dataset_name+"_"+type); // if same dataset has more files will be hadd correctly
  s1_s2->Write("log_s2_s1_"+type);
  s1_s2_roteated->Write("log_s2_s1_Rot_"+type);
  s1_s2_roteated_woSR->Write("log_s2_s1_Rot_noSR_"+type);
  s1_s2_flat_woSR->Write("log_s2_s1_flat_noSR_"+type);
  s1_s2_flat->Write("log_s2_s1_flat_"+type);
  file->Close();
  delete file;


}	

#endif
