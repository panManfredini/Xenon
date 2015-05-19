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
	cut_flow->GetXaxis()->SetBinLabel(2,"Xsignalnoise3");
	cut_flow->GetXaxis()->SetBinLabel(3,"Xsignalnoise4");
	cut_flow->GetXaxis()->SetBinLabel(4,"Xs1width0");
	cut_flow->GetXaxis()->SetBinLabel(5,"Xlownoise0_m");
	cut_flow->GetXaxis()->SetBinLabel(6,"Xentropy0");
	cut_flow->GetXaxis()->SetBinLabel(7,"Xs2top0");
	cut_flow->GetXaxis()->SetBinLabel(8,"Xs2peaks2");
	cut_flow->GetXaxis()->SetBinLabel(9,"Xs1coin2");
	cut_flow->GetXaxis()->SetBinLabel(10,"Xhighlog1");
	cut_flow->GetXaxis()->SetBinLabel(11,"Inelastic_Xs2single0");
	cut_flow->GetXaxis()->SetBinLabel(12,"Xs1single4");
	cut_flow->GetXaxis()->SetBinLabel(13,"Xveto2");
	cut_flow->GetXaxis()->SetBinLabel(14,"XPL013_97");
	cut_flow->GetXaxis()->SetBinLabel(15,"Xposrec1");
	cut_flow->GetXaxis()->SetBinLabel(16,"Xs2chisquare0");
	cut_flow->GetXaxis()->SetBinLabel(17,"Xs2peakpos0");
	cut_flow->GetXaxis()->SetBinLabel(18,"Xs2width0");
	cut_flow->GetXaxis()->SetBinLabel(19,"X34kg2");
	cut_flow->GetXaxis()->SetBinLabel(20,"NONE");
	cut_flow->GetXaxis()->SetBinLabel(21,"Livetime");
	cut_flow->GetXaxis()->SetBinLabel(22,"Rate");

    TH2D *s1_s2 = new TH2D("s1_s2","",1000,0.,1000., 1000,0.,200000.);
    s1_s2->GetXaxis()->SetTitle("cxS1sTot[0]  [PE]");
    s1_s2->GetYaxis()->SetTitle("cS2sTotBottom[0]  [PE]");
    s1_s2->Sumw2();

    TH2D *s1_s2_woSR = new TH2D("s1_s2_woSR","",1000,0.,500., 1000,0.,40000.);
    s1_s2_woSR->GetXaxis()->SetTitle("cxS1sTot[0]  [PE]");
    s1_s2_woSR->GetYaxis()->SetTitle("cS2sTotBottom[0]  [PE]");
    s1_s2_woSR->Sumw2();

    TH2D *s1_logs2 = new TH2D("s1_logs2","",1000,0.,500., 1000,0.,4.);
    TH2D *s1_logs2_roteated = new TH2D("s1_logs2_roteated","Rotated",1000,0.,500., 1000,0.,4.);
    TH2D *s1_logs2_roteated_woSR = new TH2D("s1_logs2_roteated_woSR","Rotated",1000,0.,500., 1000,0.,4.);
    TH2D *s1_logs2_flat = new TH2D("s1_logs2_flat","flatened",1000,0.,500., 1000,-4.,4.);
    TH2D *s1_logs2_flat_woSR = new TH2D("s1_logs2_flat_woSR","flatened",1000,0.,500., 1000,-4.,4.);

    s1_logs2->GetXaxis()->SetTitle("cxS1sTot[0]  [PE]");
    s1_logs2->GetYaxis()->SetTitle("log10(cS2sTotBottom[0] / cxS1sTot[0])" );
    s1_logs2->Sumw2();

    s1_logs2_roteated->GetXaxis()->SetTitle("cxS1sTot[0]  [PE]");
    s1_logs2_roteated->GetYaxis()->SetTitle("log10(cS2sTotBottom[0] / cxS1sTot[0])" );
    s1_logs2_roteated->Sumw2();

    s1_logs2_roteated_woSR->GetXaxis()->SetTitle("cxS1sTot[0]  [PE]");
    s1_logs2_roteated_woSR->GetYaxis()->SetTitle("log10(cS2sTotBottom[0] / cxS1sTot[0])" );
    s1_logs2_roteated_woSR->Sumw2();

    s1_logs2_flat->GetXaxis()->SetTitle("cxS1sTot[0]  [PE]");
    s1_logs2_flat->GetYaxis()->SetTitle("Flattened E-band" );
    s1_logs2_flat->Sumw2();

    s1_logs2_flat_woSR->GetXaxis()->SetTitle("cxS1sTot[0]  [PE]");
    s1_logs2_flat_woSR->GetYaxis()->SetTitle("Flattened E-band" );
    s1_logs2_flat_woSR->Sumw2();

   Long64_t nentries = fChain->GetEntriesFast();
   bool isFirst = true;
   int start = 0;
   int last = 0;


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



	bool isPassed = false;

	//----- Applying cuts ------//
	if(!Xsignalnoise3()) continue;
		cut_flow->Fill("Xsignalnoise3",1.);
	if(!Xsignalnoise4()) continue; 
		cut_flow->Fill("Xsignalnoise4",1.);
	if(!Xs1width0()) continue;  
		cut_flow->Fill("Xs1width0",1.);
//	if(!Xlownoise0_m()) continue;	 		 ///-----comment for amBe study
		cut_flow->Fill("Xlownoise0_m",1.);
	if(!Xentropy0()) continue; 
		cut_flow->Fill("Xentropy0",1.);
	if(!Xs2top0()) continue; 
		cut_flow->Fill("Xs2top0",1.);
	if(!Xs2peaks2()) continue; 
		cut_flow->Fill("Xs2peaks2",1.);
	if(!Xs1coin2()) continue; 
		cut_flow->Fill("Xs1coin2",1.);
//	if(!Xhighlog1()) continue;	 		 ///-----comment for amBe study
		cut_flow->Fill("Xhighlog1",1.);
	if(!Inelastic_Xs2single0()) continue; 
		cut_flow->Fill("Inelastic_Xs2single0",1.);
	if(!Xs1single4()) continue; 
		cut_flow->Fill("Xs1single4",1.);
//	if(!Xveto2()) continue;	 			 ///-----comment for amBe study
		cut_flow->Fill("Xveto2",1.);
//	if(!XPL013_97()) continue;	 		 ///-----comment for amBe study
		cut_flow->Fill("XPL013_97",1.);
//	if(!Xposrec1()) continue;	 		 ///-----comment for amBe study
		cut_flow->Fill("Xposrec1",1.);
//	if(!Xs2chisquare0()) continue;	 		 ///-----comment for amBe study
		cut_flow->Fill("Xs2chisquare0",1.);
//	if(!Xs2peakpos0()) continue;	 		 ///-----comment for amBe study
		cut_flow->Fill("Xs2peakpos0",1.);
	if(!Xinelastic_analysis_S2width0()) continue;
		cut_flow->Fill("Xs2width0",1.);

	//---- Fiducial Volume ----//
	if(!X34kg2()) continue;
		cut_flow->Fill("X34kg2",1.);

        //cut for AmBe study ------------remove me
           float X = XeT3.cS2sPosNn->at(0)[0];
	   float Y = XeT3.cS2sPosNn->at(0)[1];

	   if( X*X + Y*Y > 10000.) continue; // R < 100
           if(	XeT3.cS2sTot->at(0) < 8000.) continue;  // only inelastic
        //------------------------------ remove me 


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
	s1_s2->Fill(XeT3.cxS1sTot->at(0), XeT3.cS2sTotBottom->at(0));
	s1_logs2->Fill(XeT3.cxS1sTot->at(0) , log_s2_over_s1); 
	s1_logs2_roteated->Fill(R_s1,R_log_s2_over_s1);
	s1_logs2_flat->Fill(cxS1sTot_0 , log_in_flatten_space);

        if(!(R_s1> 60. && R_s1 < 200. && R_log_s2_over_s1 > 2.3 && R_log_s2_over_s1 < 2.7))
	  {
		s1_s2_woSR->Fill(XeT3.cxS1sTot->at(0), XeT3.cS2sTotBottom->at(0));
		s1_logs2_roteated_woSR->Fill(R_s1,R_log_s2_over_s1);
		s1_logs2_flat_woSR->Fill(cxS1sTot_0 , log_in_flatten_space);
 	  }
	
   }

	cut_flow->Fill("Livetime",livetime);
	cut_flow->Fill("Rate",cut_flow->GetBinContent(19)/livetime);

	cout << "CutFlow for " << dataset_name << endl;
  	cout << "Type " <<  type << endl;
  	cout << "Corrected Live Time " <<  livetime << endl;

  for(int i=1; i < cut_flow->GetNbinsX(); i++){ 
	cout << cut_flow->GetXaxis()->GetBinLabel(i) << "   " << cut_flow->GetBinContent(i)<< endl;
  }

  TH1F *h_livetime = new TH1F("h_livetime","livetime VS dataset time",80000,1200000000.,1500000000.); // unixtime from 208 to 2017 in bin o ~1h
  h_livetime->GetXaxis()->SetTitle("Date");
  h_livetime->GetYaxis()->SetTitle("Livetime [day]");
  h_livetime->GetXaxis()->SetTimeDisplay(1);
  h_livetime->GetXaxis()->SetTimeFormat("%b");
  h_livetime->Fill( XeT1.TimeSec, livetime);
  h_livetime->SetBinError(h_livetime->FindBin( XeT1.TimeSec), sqrt(livetime));



  TFile *file = new TFile(outDir + "cutFlow_" + filename ,"RECREATE");
  file->cd();
  s1_s2->Write("s1_s2_"+type);
  s1_s2_woSR->Write("s1_s2_noSR_"+type);
  s1_logs2->Write("log_s2_s1_"+type);
  s1_logs2_roteated->Write("log_s2_s1_Rot_"+type);
  s1_logs2_roteated_woSR->Write("log_s2_s1_Rot_noSR_"+type);
  s1_logs2_flat_woSR->Write("log_s2_s1_flat_noSR_"+type);
  s1_logs2_flat->Write("log_s2_s1_flat_"+type);
  h_livetime->Write("livetime_"+type);
  file->mkdir("cutflows");
  file->cd("cutflows");
  cut_flow->Write(dataset_name+"_"+type); // if same dataset has more files will be hadd correctly
  file->Close();

  delete file;


}	

#endif
