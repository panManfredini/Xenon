#define XenonDataReader_cxx
#include "XenonDataReader.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void XenonDataReader::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L XenonDataReader.C
//      Root > XenonDataReader t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch

   if (fChain == 0) return;
   if(XeT3.fChain ==0) return;
   if(XeT1.fChain ==0) return;

  
   Initialize();

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
/*	if( Xsignalnoise5() )	 cut_flow->Fill("Xsignalnoise5", 1.) ;

	if( Xs1width0() )
		 cut_flow->Fill("Xs1width0", 1.) ;
	if( Xentropy1() ) 
		 cut_flow->Fill("Xentropy1", 1.) ;
	if( Xs2peaks2() )
		 cut_flow->Fill("Xs2peaks2", 1.) ;
	if( Xs1coin2()  )
		 cut_flow->Fill("Xs1coin2", 1.) ;
	if( Xhighlog1() )
		 cut_flow->Fill("Xhighlog1", 1.) ; 
	if( Xs2single3() ) 
		 cut_flow->Fill("Xs2single3", 1.) ;
	if( Xs1single5() )
		 cut_flow->Fill("Xs1single5", 1.) ;
	if( Xveto2()  ) 
		 cut_flow->Fill("Xveto2", 1.) ;
	if( Xs2width11()  )
		 cut_flow->Fill("Xs2width11", 1.) ;
	if( XPL013_97()  )
		 cut_flow->Fill("XPL013_97", 1.) ;
	if( Xposrec1()  )
		 cut_flow->Fill("Xposrec1", 1.) ;
	if( Xs2chisquare1()  )
		 cut_flow->Fill("Xs2chisquare1", 1.) ;
	if( Xlownoise0_m() )
		 cut_flow->Fill("Xlownoise0_m", 1.) ;
	if( Xs2peakpos0()  )
		 cut_flow->Fill("Xs2peakpos0", 1.) ;
	if( X34kg2() )
		 cut_flow->Fill("X34kg2", 1.) ;
*/
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

	isPassed = true;
//		cout << "GOOD EVENT!!!" << endl; 

   }

  for(int i=1; i < cut_flow->GetNbinsX(); i++) 
	cout << cut_flow->GetXaxis()->GetBinLabel(i) << "   " << cut_flow->GetBinContent(i)<< endl;
 
  TString dataset_name_full = XeT1.Filename;
  TString dataset_name(dataset_name_full(0,17));
	
  cut_flow->Print("all");

  TString type("");
  double livetime = DatasetLivetime(dataset_name, type);
  cout << "Corrected Live Time " <<  livetime << endl;
  TH1F *rate = new TH1F("rate","rate VS dataset time",80000,1200000000.,1500000000.); // unixtime from 208 to 2017 in bin o ~1h
  rate->GetXaxis()->SetTitle("Date");
  rate->GetYaxis()->SetTitle("Event Rate / day [day^{-1}]");
  rate->GetXaxis()->SetTimeDisplay(1);
  rate->GetXaxis()->SetTimeFormat("%b");
  
  rate->Fill( XeT1.TimeSec, (float)nuber_of_survived_event/livetime);
  rate->SetBinError(rate->FindBin( XeT1.TimeSec), sqrt((float)nuber_of_survived_event)/livetime);

  TH1F *h_livetime = new TH1F("h_livetime","livetime VS dataset time",80000,1200000000.,1500000000.); // unixtime from 208 to 2017 in bin o ~1h
  h_livetime->GetXaxis()->SetTitle("Date");
  h_livetime->GetYaxis()->SetTitle("Livetime [days]");
  h_livetime->GetXaxis()->SetTimeDisplay(1);
  h_livetime->GetXaxis()->SetTimeFormat("%b");
  h_livetime->Fill( XeT1.TimeSec, livetime);


  TFile *file = new TFile(outDir + "cutFlow_" + filename ,"RECREATE");
  file->cd();
  cut_flow->Write(dataset_name); // if same dataset has more files will be hadd correctly
  rate->Write();
  h_livetime->Write();
  file->Close();
  delete file;
}	


//----------------------------------------------------------------------//
  void 	XenonDataReader::	fillBranches(Long64_t ientry)   // fastest way I know to load branches
	{
		b_AreaTot->GetEntry(ientry);
		b_Area->GetEntry(ientry);
		b_S1s->GetEntry(ientry);
		b_S1sTot->GetEntry(ientry);
		b_AreaTot->GetEntry(ientry);
		b_Area->GetEntry(ientry);
		b_S1s->GetEntry(ientry);
		b_S1sTot->GetEntry(ientry);
		b_S1sTotOutside->GetEntry(ientry);
		b_S2s->GetEntry(ientry);
		b_S2sTot->GetEntry(ientry);
		b_S2sTotTop->GetEntry(ientry);
		b_S2sTotBottom->GetEntry(ientry);
		b_S1sCoin->GetEntry(ientry);
		b_S2sCoin->GetEntry(ientry);
		b_S2sCoinTop->GetEntry(ientry);
		b_S1sPmtCoin->GetEntry(ientry);
		b_S2sPosSvm->GetEntry(ientry);
		b_S2sPosNn->GetEntry(ientry);
		b_S2sPosChi2->GetEntry(ientry);
		XeT1.b_Filename->GetEntry(ientry);
		XeT1.b_TimeSec->GetEntry(ientry);
		XeT1.b_S1sPeak->GetEntry(ientry);
		XeT1.b_S1sLowWidth->GetEntry(ientry);
		XeT1.b_S2sPeak->GetEntry(ientry);
		XeT1.b_S2sWidth->GetEntry(ientry);
		XeT1.b_S2sLowWidth->GetEntry(ientry);
		XeT3.b_cS2sPosNn->GetEntry(ientry);
		XeT3.b_cS1sTot->GetEntry(ientry);
		XeT3.b_cS2sTot->GetEntry(ientry);
		XeT3.b_cS2sTotTop->GetEntry(ientry);
		XeT3.b_cS2sTotBottom->GetEntry(ientry);
		XeT3.b_cfS2sLowWidth->GetEntry(ientry);
		XeT3.b_S1PatternLikelihood->GetEntry(ientry);
		XeT3.b_S1sEntropy->GetEntry(ientry);
		XeT3.b_cxS1sTot->GetEntry(ientry);
	}


//------------- Analysis Variables and Cuts--------------------------//

  bool  XenonDataReader::	run_12_basic()
	{
	return ( Xsignalnoise5() && Xs1width0() && Xentropy1() && Xs2peaks2() && Xs1coin2() && Xhighlog1()
		&& Xs2single3() && Xs1single5() && Xveto2()  && Xs2width11() && XPL013_97() && Xposrec1() 
		&& Xs2chisquare1() && Xlownoise0_m() && Xs2peakpos0() && X34kg2() ) ;
	}

  int 	XenonDataReader::	noisypmts10()
	{
	// based on:
	//https://xecluster.lngs.infn.it/dokuwiki/doku.php?id=xenon:xenon100:analysis_run10:elnoise2#increasing_the_s1_coincidence_requirement
	return (
		((*S1s)[0][151] > 0.35) + ((*S1s)[0][169] > 0.35)  + 
		(TMath::Nint(0.4*( (*S1s)[0][166] > 0.35)+0.4*( (*S1s)[0][168] > 0.35)))
	       );
	}
 
 
  bool  XenonDataReader:: 	Xs1coin2()
	{
	// based on:
	//https://xecluster.lngs.infn.it/dokuwiki/doku.php?id=xenon:xenon100:analysis_run10:elnoise2#increasing_the_s1_coincidence_requirement
	if(S1sCoin->empty()) return false;

	return ((*S1sCoin)[0] > (1 + noisypmts10()) );
	}


  bool  XenonDataReader:: 	Xsignalnoise5()  // Typo corrected :)
	{

	if(S2sTot->empty() || S1sTot->empty() ) return false;

	return (
		(  log10( (*S2sTot)[0] )<2.77 
		&& log10( ((*S1sTot)[0]+ (*S2sTot)[0]) / TMath::Max(AreaTot - (*S1sTot)[0] - (*S2sTot)[0] , (float)0.00001) )>0
		&& AreaTot>0.0 )  
		|| (
		   log10( (*S2sTot)[0]) >=2.77 
		&& log10( ((*S1sTot)[0] + (*S2sTot)[0]) / TMath::Max( AreaTot - (*S1sTot)[0] - (*S2sTot)[0] , (float) 0.00001)) > 
		   TMath::Min(
			0.23436*TMath::Power(log10( (*S2sTot)[0]),3) - 2.77487*TMath::Power(log10((*S2sTot)[0]),2) 
			+ 11.2553*log10((*S2sTot)[0]) - 14.8667,  0.8)
		&& AreaTot > 0.0) 
	        ); 

	}

  
  bool  XenonDataReader:: 	Xsignalnoise3()  // Typo corrected :)
	{

	if(S2sTot->empty() || S1sTot->empty() ) return false;

 	  return(
	        (log10(( (*S1sTot)[0] + (*S2sTot)[0])/TMath::Max( double(AreaTot - (*S1sTot)[0] - (*S2sTot)[0]),0.00001 ) ) >0.00) 
		&& AreaTot > 0.0 
	  );

	}
  
bool  XenonDataReader:: 	Xsignalnoise4()  // Typo corrected :)
	{

	if(S2sTot->empty() || S1sTot->empty() ) return false;

	  return (
	          log10(((*S1sTot)[0]+(*S2sTot)[0])/TMath::Max(AreaTot-(*S1sTot)[0]-(*S2sTot)[0],0.00001)) >
		  TMath::Min(0.284*pow(log10((*S2sTot)[0]),3) -2.81*pow(log10((*S2sTot)[0]),2.) 
		  +10.1*log10((*S2sTot)[0])-12.3, 1.0) 
		  && AreaTot>0.0) ;
	}

  bool  XenonDataReader:: 	Xs1width0() 
	{
	if(XeT1.S1sLowWidth->empty()) return false;

	return ( XeT1.S1sLowWidth->at(0) > 2.6 ) ;
	}	



  int   XenonDataReader:: 	ncoin_e_1() 
	{

	int ncoin_e_1_counter =0;

	for(int i =0; i < (*S1sPmtCoin)[0].size(); i++) 
	{
		int Coin_itr = (*S1sPmtCoin)[0][i];
		float s1s_temp = (*S1s)[0][Coin_itr];
		float entropy_temp = XeT3.S1sEntropy->at(0)[Coin_itr];
		
		if( s1s_temp <0.4806 && entropy_temp < 2.66184) ncoin_e_1_counter++;

		if(0.4806<= s1s_temp && s1s_temp <= 2.08657 && 
			 entropy_temp < (3.52658 - 5.04919*s1s_temp +10.6078*TMath::Power(s1s_temp,2) -9.87844*TMath::Power(s1s_temp,3)
				+4.22897*TMath::Power(s1s_temp,4) -0.673842*TMath::Power(s1s_temp,5) ) )  ncoin_e_1_counter++;
		
		if(2.08657 < s1s_temp && s1s_temp < 15 && entropy_temp < 2.94477 ) ncoin_e_1_counter++;

		if(s1s_temp >=15 && entropy_temp < (0.79527*log10(s1s_temp) + 2.0094598 ) ) ncoin_e_1_counter++;
	
  	} 

	return ncoin_e_1_counter;
	}


  int   XenonDataReader:: 	ncoin_e_0() 
	{
	  int ncoin_e_0_counter =0;

	  for(int i =0; i < (*S1sPmtCoin)[0].size(); i++) 
	  {

		int Coin_itr = (*S1sPmtCoin)[0][i];
		float s1s_temp = (*S1s)[0][Coin_itr];
		float entropy_temp = XeT3.S1sEntropy->at(0)[Coin_itr];
		
		if(s1s_temp > 2.) ncoin_e_0_counter++;
		if(s1s_temp <= 2. && s1s_temp >1. && (entropy_temp < s1s_temp + 1.5) )  ncoin_e_0_counter++;
		if(s1s_temp <= 1. && entropy_temp < 2.5 )  ncoin_e_0_counter++;
	  }

	  return ncoin_e_0_counter;
  	}


  bool  XenonDataReader:: 	Xentropy1() 
	{

	if(S1s->empty()) return false;

	return (ncoin_e_1() > 1 );
	}

  bool  XenonDataReader:: 	Xentropy0() 
	{

	if(S1s->empty()) return false;

	return (ncoin_e_0() > 1 );
	}
  

bool  XenonDataReader:: 	Xs2top0() 
	{
	   if(S2sTotTop->empty()) return false;

	   return ((*S2sTotTop)[0] > 0.); 

	}

  bool  XenonDataReader:: 	Xs2peaks2()
	{
	if(S2sTot->empty()) return false;

	return ( (*S2sTot)[0] > 150. ) ;
	}

  bool  XenonDataReader::  	Xhighlog1()	
	{
	if(XeT3.cS2sTotBottom->empty() || XeT3.cS1sTot->empty()) return false;
	
 	 return ( log10( XeT3.cS2sTotBottom->at(0) / XeT3.cS1sTot->at(0) ) < 3.1 ) ;	
	}
  
  bool  XenonDataReader::  	Xs2single3()
	{
	 float S2sTot_temp = 0.;
	 if(S2sTot->size() > 1 )  S2sTot_temp = (*S2sTot)[1];

	 return (  S2sTot_temp < (70. + ( (*S2sTot)[0]-300.) / 100.) );
	}	

//(  Alt$(S2sTot[1],0) < (70+(S2sTot[0]-300)/100.)  )

  double XenonDataReader:: 	AltC(double nbpeak, int pos, double prim, double sec)
	{
   	  return ( nbpeak - pos > 0. ? prim : sec );
	}	


  bool  XenonDataReader:: 	Xs2single0()
	{
	  if(S2sTot->size() > 1) return ((*S2sTot)[1] < 300.);
	  return true;
	}
  
  bool  XenonDataReader:: 	Xs2width0()
	{
	   if(XeT1.S2sPeak->empty() || XeT1.S1sPeak->empty() || XeT1.S2sWidth->empty() ) return false;

	   double zeta = -1.8*(XeT1.S2sPeak->at(0)-XeT1.S1sPeak->at(0))/100.; 
	   
	   return (XeT1.S2sWidth->at(0) < -0.2167*(zeta + 4.) + 75.) ;	  
	}


  bool  XenonDataReader:: 	Xs1single4()
	{
	  return ( 
		( AltC(XeT1.S1sPeak->size(), 1, (*S1sCoin)[1], 1) < 2. || 
		  ( XeT1.S2sPeak->at(0) - AltC(XeT1.S1sPeak->size(), 1, XeT1.S1sPeak->at(1), -18500) ) > 18500 
		  || log10( XeT3.cS2sTot->at(0)/ AltC(XeT1.S1sPeak->size(), 1, XeT3.cS1sTot->at(1), 1.e-4) ) > 3.2) 
		&& ( AltC(XeT1.S1sPeak->size(), 2, (*S1sCoin)[2], 1) < 2 
		  || ( XeT1.S2sPeak->at(0) - AltC(XeT1.S1sPeak->size(), 2, XeT1.S1sPeak->at(2), -18500) ) > 18500 
		  || log10( XeT3.cS2sTot->at(0)/ AltC(XeT1.S1sPeak->size(), 2, XeT3.cS1sTot->at(2), 1.e-4) ) > 3.2) 
		&& ( AltC(XeT1.S1sPeak->size(), 3, (*S1sCoin)[3], 1) < 2 
		  || ( XeT1.S2sPeak->at(0) - AltC(XeT1.S1sPeak->size(), 3, XeT1.S1sPeak->at(3), -18500) ) > 18500 
		  || log10( XeT3.cS2sTot->at(0)/ AltC(XeT1.S1sPeak->size(), 3, XeT3.cS1sTot->at(3), 1.e-4) ) > 3.2) 
		&& ( AltC(XeT1.S1sPeak->size(), 4, (*S1sCoin)[4], 1) < 2.)  ) ;
	}

  bool  XenonDataReader:: 	Xs1single5()
	{
	if(XeT1.S2sPeak->empty()) return false;

	if( XeT1.S1sPeak->size() > 4)
		return ( 
		(ncoin_e_s1(1) < 2 || (XeT1.S2sPeak->at(0) - XeT1.S1sPeak->at(1) ) > 18500 ||  log10(XeT3.cS2sTot->at(0) / XeT3.cS1sTot->at(1)) > 3.2)
	        && (ncoin_e_s1(2) < 2 || (XeT1.S2sPeak->at(0) -XeT1.S1sPeak->at(2)) > 18500 || log10(XeT3.cS2sTot->at(0)/XeT3.cS1sTot->at(2)) > 3.2)
		&& (ncoin_e_s1(3) < 2 || (XeT1.S2sPeak->at(0) -XeT1.S1sPeak->at(3) ) > 18500 || log10(XeT3.cS2sTot->at(0) / XeT3.cS1sTot->at(3)) > 3.2)
		&& ncoin_e_s1(4) < 2 );

	else if(XeT1.S1sPeak->size() > 3) 
		return ( 
		(ncoin_e_s1(1) < 2 || (XeT1.S2sPeak->at(0) -XeT1.S1sPeak->at(1) ) > 18500 ||  log10(XeT3.cS2sTot->at(0) / XeT3.cS1sTot->at(1)) > 3.2)
	        && (ncoin_e_s1(2) < 2 || (XeT1.S2sPeak->at(0) -XeT1.S1sPeak->at(2)) > 18500 || log10(XeT3.cS2sTot->at(0)/XeT3.cS1sTot->at(2)) > 3.2)
		&& (ncoin_e_s1(3) < 2 || (XeT1.S2sPeak->at(0)- XeT1.S1sPeak->at(3)) > 18500 || log10(XeT3.cS2sTot->at(0) / XeT3.cS1sTot->at(3)) > 3.2));

	else if(XeT1.S1sPeak->size() > 2) 
		return ( 
		(ncoin_e_s1(1) < 2 || (XeT1.S2sPeak->at(0) - XeT1.S1sPeak->at(1)) > 18500 ||  log10(XeT3.cS2sTot->at(0) / XeT3.cS1sTot->at(1)) > 3.2)
	        && (ncoin_e_s1(2) < 2 || (XeT1.S2sPeak->at(0) -XeT1.S1sPeak->at(2)) > 18500 || log10(XeT3.cS2sTot->at(0)/XeT3.cS1sTot->at(2)) > 3.2));

	else if(XeT1.S1sPeak->size() > 1) 
		return ((ncoin_e_s1(1) < 2 || (XeT1.S2sPeak->at(0) - XeT1.S1sPeak->at(1) ) > 18500 ||  log10(XeT3.cS2sTot->at(0) / XeT3.cS1sTot->at(1)) > 3.2));
	
	return true ;
	}

// ((ncoin_e_s1_1 < 2 || (S2sPeak[0]-Alt$(S1sPeak[1],-18500)) > 18500 || log10(cS2sTot[0]/Alt$(cS1sTot[1],1.e-4)) > 3.2) && (ncoin_e_s1_2 < 2 || (S2sPeak[0]-Alt$(S1sPeak[2],-18500)) > 18500 || log10(cS2sTot[0]/Alt$(cS1sTot[2],1.e-4)) > 3.2) && (ncoin_e_s1_3 < 2 || (S2sPeak[0]-Alt$(S1sPeak[3],-18500)) > 18500 || log10(cS2sTot[0]/Alt$(cS1sTot[3],1.e-4)) > 3.2) && (ncoin_e_s1_4 < 2)) 

  int  XenonDataReader:: 	ncoin_e_s1(int peak_itr) 
	{
	 int value = 0;
	 if( S1s->size() > peak_itr ) // S1sPmtCoin[1] exist
	  	{
		for(int i=0; i < (*S1sPmtCoin)[peak_itr].size(); i++)
			{
			int pmt_itr = (*S1sPmtCoin)[peak_itr][i];
			float S1s_pmt = (*S1s)[peak_itr][ (*S1sPmtCoin)[peak_itr][i] ];

			if( (S1s_pmt > 2.)  || 
			    (S1s_pmt <=2. && S1s_pmt >1. && XeT3.S1sEntropy->at(peak_itr)[pmt_itr] < S1s_pmt + 1.5) ||
			    (S1s_pmt <=1. && XeT3.S1sEntropy->at(peak_itr)[pmt_itr] < 2.5 ) ) 
			    	value++;
			}
		
		}	
	  
	 return value;

	}

//Alt$(Sum$((S1s[1][S1sPmtCoin[1][]]>2)+((S1s[1][S1sPmtCoin[1][]]<=2.&&S1s[1][S1sPmtCoin[1][]]>1)*(S1sEntropy[1][S1sPmtCoin[1][]]<S1s[1][S1sPmtCoin[1][]]+1.5))+((S1s[1][S1sPmtCoin[1][]]<=1.)*(S1sEntropy[1][S1sPmtCoin[1][]]<2.5))),0) 

  bool  XenonDataReader:: 	Xveto2()
	{
	if(S1sTotOutside->empty() ) return false;

	return (  ((*S1sTotOutside)[0]<0.35) ? true : false );
	}


  float  XenonDataReader:: 	sigma_flattened_width_11 ()
	{
	 float S2 = 5000.;
	 if( (*S2sTot)[0] < 5000.)  S2 =  (*S2sTot)[0] ;

	 return (
		67.7404 - 10.1215*log(S2)+0.297558*sqrt(S2)-10.8131*(1./exp(0.00129359*S2)) + 
		(0.0382098 + 0.0963804*exp( -5.15204e-04*S2))*DriftTime()
		);
	}


  float  XenonDataReader:: 	DriftTime(int peak_itr)
	{
	 if(XeT1.S2sPeak->size() > peak_itr )
		return ( (XeT1.S2sPeak->at(peak_itr) - XeT1.S1sPeak->at(0) )/100. ); 
	 else cout << "WARNING --->XenonDataReader::DriftTime -- \t PEAK number  " << peak_itr << "   do NOT exist, returning -999." << endl;
	 return -999.;
	}


  bool  XenonDataReader::	Xs2width11()
	{
	if(S2sTot->empty() || XeT3.cfS2sLowWidth->empty() || XeT1.S1sPeak->empty() ) return false;

	return (XeT3.cfS2sLowWidth->at(0) > -2. * sigma_flattened_width_11() && XeT3.cfS2sLowWidth->at(0) < 2.*sigma_flattened_width_11());	
	}

 

  float  XenonDataReader:: 	PL013()
	{
	return (-2.*(XeT3.S1PatternLikelihood->at(0) + XeT3.S1PatternLikelihood->at(1) +XeT3.S1PatternLikelihood->at(3)));
	}	

  bool  XenonDataReader::	XPL013_97()
	{
	 if(XeT3.S1PatternLikelihood->empty()) return false;

	 return (PL013() < 
		-16.9181 + 27.3756 * pow((*S1sTot)[0],0.5) + -1.73185 * (*S1sTot)[0] + 0.041431 * pow((*S1sTot)[0],1.5) ) ;	
	}     

  bool  XenonDataReader::	Xposrec1()
	{
	 if(S2sTot->empty()) return false;

	 return ( 
		 sqrt((pow(( (*S2sPosNn)[0][0]- (*S2sPosSvm)[0][0]),2)+pow(((*S2sPosNn)[0][1]-(*S2sPosSvm)[0][1]),2)) + 
		 (pow(((*S2sPosNn)[0][0]-(*S2sPosChi2)[0][0]),2)+pow(((*S2sPosNn)[0][1]-(*S2sPosChi2)[0][1]),2))) < 7. ) ;
	}


  bool  XenonDataReader::	Xs2chisquare1()
	{
//	 if( (*S2sCoinTop)[0] <= 1) return false;  // don't cut cut if Xsquare is not well defined
	 if(S2sTot->empty()) return false;

	 return ( (*S2sCoinTop)[0] > 1 && ( (*S2sPosNn)[0][3]/ ( (*S2sCoinTop)[0] - 1 )) < 6. );
	}
 
  bool  XenonDataReader::	Xs2chisquare0()
	{
	  if(S2sTot->empty()) return false;
	  return ( ((*S2sPosNn)[0][3]/((*S2sCoinTop)[0] - 1 )) < 7. );

	}

  bool  XenonDataReader::	Xlownoise0_m()
	{
	 if(XeT3.cS2sTot->empty()) return false;

	return (  cs2asym() <0.25 && cs2asym() >-0.2 ) ;
	}


  float XenonDataReader::	cs2asym()
	{
	return ( ( XeT3.cS2sTotTop->at(0) - XeT3.cS2sTotBottom->at(0) ) / XeT3.cS2sTot->at(0) );
	}


  bool  XenonDataReader::	Xs2peakpos0()
	{

	if(S2sTot->empty()) return false;

	return ( XeT1.S2sPeak->at(0)/100.  > 178. );
	}

  bool  XenonDataReader::	X34kg2()
	{

	if(XeT3.cS2sPosNn->empty() || XeT3.cS2sPosNn->at(0).empty()) return false;

	float Z = XeT3.cS2sPosNn->at(0)[2];
	float X = XeT3.cS2sPosNn->at(0)[0];
	float Y = XeT3.cS2sPosNn->at(0)[1];

	return (  (TMath::Power(TMath::Abs(-Z-152.)/126.8,2.7)+TMath::Power((X*X+Y*Y)/17500.,2.7) < 1.) ? true : false );

  	}
 
   float XenonDataReader::	X(const int peak_index)
	{
	 if(XeT3.cS2sPosNn->at(peak_index).empty()) return -999.;
	 return XeT3.cS2sPosNn->at(peak_index)[0];
	}
 
  float XenonDataReader::	Y(const int peak_index)
	{
	 if(XeT3.cS2sPosNn->at(peak_index).empty()) return -999.;
	 return XeT3.cS2sPosNn->at(peak_index)[1];
	}

   float XenonDataReader::	Z(const int peak_index)
	{
	 if(XeT3.cS2sPosNn->at(peak_index).empty()) return -999.;
	 return XeT3.cS2sPosNn->at(peak_index)[2];
	}
 
   float XenonDataReader::	R(const int peak_index)
	{
	 return sqrt(pow(X(peak_index),2.) + pow(Y(peak_index),2.));
	}

   bool  XenonDataReader::	X48kg0()
	{

	 return ( (pow(TMath::Abs((Z()+150.)/146.),4.) + pow(TMath::Abs(R()*R()/20000.),4)) < 1.); 
	}


double XenonDataReader::DatasetLivetime(const TString dataset_name, TString &isotope)
	{
	 double livetime = 0.;

	 if(dataset_name == "xe100_121209_0832") { livetime = 0.0202211; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_121209_1430") { livetime = 0.021588; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_121209_2101") { livetime = 0.0225336; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_121210_0334") { livetime = 0.0227292; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_121210_1006") { livetime = 0.0228356; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_121211_1055") { livetime = 0.0229838; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_121212_1136") { livetime = 0.0226759; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_121212_1243") { livetime = 0.0234595; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_121212_1512") { livetime = 0; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_121212_1633") { livetime = 0.0241238; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_121212_1710") { livetime = 0.0478056; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_121212_2132") { livetime = 0.047184; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_121212_2248") { livetime = 0.0471493; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_121213_0645") { livetime = 0.0478681; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_121213_0910") { livetime = 0.0473507; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_121213_1400") { livetime = 0.0474549; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_121213_1520") { livetime = 0.0484549; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_121213_1632") { livetime = 0.0484132; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_121213_1743") { livetime = 0.0470984; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_121213_2214") { livetime = 0.0473958; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_121213_2328") { livetime = 0.0489838; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_121214_0453") { livetime = 0.0477141; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_121214_0708") { livetime = 0.0467836; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_121214_1210") { livetime = 0.0483403; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_121214_1325") { livetime = 0.050213; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_121214_1441") { livetime = 0.0487199; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_121214_1557") { livetime = 0.0466875; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_121217_1947") { livetime = 0.0240313; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_121221_1147") { livetime = 0.0247407; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_121222_1044") { livetime = 0.0243438; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_121224_1203") { livetime = 0.0266493; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_121225_1140") { livetime = 0.026228; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_121226_1151") { livetime = 0.0274502; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_121227_1016") { livetime = 0.0265926; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_121228_0955") { livetime = 0.027294; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_121231_1011") { livetime = 0.0267396; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130101_1007") { livetime = 0.0266192; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130102_1015") { livetime = 0.0259016; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130104_1047") { livetime = 0.0257211; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130106_1444") { livetime = 0.0257419; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130107_1119") { livetime = 0.0258414; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130109_1121") { livetime = 0.0273715; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130111_1715") { livetime = 0.0265648; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130114_1526") { livetime = 0.0266736; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130115_1458") { livetime = 0.0278252; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130116_1801") { livetime = 0.0120752; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130121_1743") { livetime = 0.0142431; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130124_1125") { livetime = 0.0285845; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130125_1516") { livetime = 0.0255602; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130128_1025") { livetime = 0.025809; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130130_1517") { livetime = 0.027919; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130201_1424") { livetime = 0.0277477; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130204_1105") { livetime = 0.0286366; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130204_1800") { livetime = 0.0264525; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130206_1431") { livetime = 0.0275984; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130208_1215") { livetime = 0.0284387; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130211_1856") { livetime = 0.0283692; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130218_1847") { livetime = 0.0275822; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130223_1313") { livetime = 0.027265; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130225_1907") { livetime = 0.0250278; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130301_1730") { livetime = 0.0274988; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130302_1318") { livetime = 0.0258831; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130304_1050") { livetime = 0.0276354; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130307_1625") { livetime = 0.0276181; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130308_1346") { livetime = 0.0261597; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130309_1337") { livetime = 0.026441; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130310_1039") { livetime = 0.0266609; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130311_0847") { livetime = 0.0259086; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130311_1836") { livetime = 0.0286713; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130312_1158") { livetime = 0.0279977; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130313_0829") { livetime = 0.0280347; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130314_1608") { livetime = 0.028603; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130315_1602") { livetime = 0.0213368; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130316_1409") { livetime = 0.0215556; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130318_1024") { livetime = 0.0225833; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130319_1219") { livetime = 0.0231713; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130321_1141") { livetime = 0.0116111; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130321_1204") { livetime = 0.0241956; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130322_1540") { livetime = 0.0243819; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130325_1131") { livetime = 0.0249063; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130327_1129") { livetime = 0.0201563; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130329_1712") { livetime = 0.025147; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130401_1739") { livetime = 0.0218356; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130403_1631") { livetime = 0.0201447; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130405_1209") { livetime = 0.0250694; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130408_1520") { livetime = 0.0221609; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130410_1753") { livetime = 0.0205058; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130412_1441") { livetime = 0.0249549; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130415_1643") { livetime = 0.0228657; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130416_1100") { livetime = 0.102759; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130416_1449") { livetime = 0.105569; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130416_1837") { livetime = 0.10737; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130416_2231") { livetime = 0.108444; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130417_0242") { livetime = 0.109498; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130417_0656") { livetime = 0.110734; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130417_1122") { livetime = 0.111288; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130417_1519") { livetime = 0.0639815; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130418_1322") { livetime = 0.0209028; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130420_1659") { livetime = 0.127873; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130420_2127") { livetime = 0.128944; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130421_0158") { livetime = 0.130779; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130421_0630") { livetime = 0.131466; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130421_1112") { livetime = 0.13245; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130421_1550") { livetime = 0.0678102; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130421_1809") { livetime = 0.000721065; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130421_1823") { livetime = 0.0261887; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130422_1834") { livetime = 0.883477; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130423_1542") { livetime = 1.13449; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130424_1850") { livetime = 1.01476; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130425_1918") { livetime = 0.0224549; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130425_2035") { livetime = 0.885196; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130426_1858") { livetime = 0.956884; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130427_1752") { livetime = 1.0192; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130428_1814") { livetime = 0.934267; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130429_1711") { livetime = 0.0210197; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130429_1750") { livetime = 0.00365972; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130429_1801") { livetime = 0.101497; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130429_2155") { livetime = 0.102579; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130430_0142") { livetime = 0.10325; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130430_0536") { livetime = 0.00979861; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130430_1040") { livetime = 0.0967477; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130430_1432") { livetime = 0.103703; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130430_1812") { livetime = 0.0198912; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130430_1854") { livetime = 3.47222e-05; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130430_1855") { livetime = 1.73611e-05; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130430_1944") { livetime = 0.113858; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130430_2345") { livetime = 0.122748; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130501_0342") { livetime = 0.122894; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130501_0808") { livetime = 0.12422; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130501_1221") { livetime = 0.124142; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130501_1944") { livetime = 0.973575; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130502_2121") { livetime = 0.847462; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130503_2043") { livetime = 0.899851; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130504_1854") { livetime = 0.969111; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130505_1849") { livetime = 1.58292; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130507_0848") { livetime = 0.256927; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130507_1543") { livetime = 0.0211053; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130507_1655") { livetime = 0.103014; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130508_1447") { livetime = 0.105847; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130508_1843") { livetime = 0.105899; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130508_2246") { livetime = 0.106296; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130509_0257") { livetime = 0.101889; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130509_0709") { livetime = 0.106144; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130509_1115") { livetime = 0.106582; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130509_1653") { livetime = 0.118078; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130509_2115") { livetime = 0.119148; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130510_0141") { livetime = 0.119014; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130510_0601") { livetime = 0.119642; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130510_1028") { livetime = 0.120134; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130510_1453") { livetime = 0.120308; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130510_1928") { livetime = 0.0182361; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130510_2009") { livetime = 7.63889e-05; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130510_2333") { livetime = 0.642049; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130511_1511") { livetime = 0.0230428; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130511_1631") { livetime = 1.35138; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130513_0051") { livetime = 0.762847; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130513_1935") { livetime = 0.0236227; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130513_2016") { livetime = 0.105201; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130514_0008") { livetime = 0.105677; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130514_0407") { livetime = 0.106035; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130514_0816") { livetime = 0.10624; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130514_1225") { livetime = 0.107211; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130514_1626") { livetime = 0.107216; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130514_2028") { livetime = 0.0227662; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130515_1643") { livetime = 0.0219317; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130515_1828") { livetime = 0.637397; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130516_1119") { livetime = 0.0208137; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130516_1209") { livetime = 0.0774884; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130516_1400") { livetime = 0.0776296; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130516_1552") { livetime = 0.0786701; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130516_1746") { livetime = 0.0781574; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130516_1939") { livetime = 0.0775683; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130516_2131") { livetime = 0.0784201; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130516_2324") { livetime = 0.07764; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130517_0116") { livetime = 0.0785868; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130517_0309") { livetime = 0.0780417; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130517_0502") { livetime = 0.0781435; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130517_0655") { livetime = 0.0777963; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130517_0847") { livetime = 0.0781192; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130517_1040") { livetime = 0.0774826; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130517_1232") { livetime = 0.0773264; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130517_1429") { livetime = 0.0757211; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130517_1618") { livetime = 0.0757975; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130517_1808") { livetime = 0.0757558; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130517_1957") { livetime = 0.0750509; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130517_2146") { livetime = 0.0746262; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130517_2334") { livetime = 0.074831; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130518_0122") { livetime = 0.0747442; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130518_0312") { livetime = 0.074537; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130518_0459") { livetime = 0.0745613; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130518_0648") { livetime = 0.0745394; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130518_0836") { livetime = 0.073897; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130518_1023") { livetime = 0.0743218; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130518_1210") { livetime = 0.0744583; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130518_1358") { livetime = 0.0742512; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130518_1546") { livetime = 0.0738264; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130518_1732") { livetime = 0.0747662; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130518_1921") { livetime = 0.019088; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130518_1951") { livetime = 0.0758681; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130518_2141") { livetime = 0.0762836; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130518_2331") { livetime = 0.0759769; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130519_0121") { livetime = 0.0757153; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130519_0311") { livetime = 0.0763669; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130519_0501") { livetime = 0.0759155; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130519_0650") { livetime = 0.0753218; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130519_0839") { livetime = 0.0754456; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130519_1028") { livetime = 0.076022; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130519_1218") { livetime = 0.0758542; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130519_1408") { livetime = 0.0758484; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130519_1557") { livetime = 0.0756076; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130519_1747") { livetime = 0.0150428; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130519_1811") { livetime = 0.0754248; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130519_2000") { livetime = 0.0741863; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130519_2148") { livetime = 0.0748704; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130519_2336") { livetime = 0.0749236; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130520_0125") { livetime = 0.0748762; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130520_0313") { livetime = 0.0747824; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130520_0501") { livetime = 0.0750799; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130520_0649") { livetime = 0.0743773; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130520_0837") { livetime = 0.074463; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130520_1025") { livetime = 0.0746516; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130520_1212") { livetime = 0.0746146; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130520_1400") { livetime = 0.0746157; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130520_2301") { livetime = 0.0755671; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130521_0052") { livetime = 0.075912; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130521_0241") { livetime = 0.0756551; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130521_0431") { livetime = 0.0756285; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130521_0620") { livetime = 0.0752836; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130521_0809") { livetime = 0.0534757; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_130521_1202") { livetime = 0.0263993; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130523_1634") { livetime = 0.0289815; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130525_1235") { livetime = 0.0289398; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130527_1120") { livetime = 0.0291285; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130530_1523") { livetime = 0.0285949; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130604_1104") { livetime = 0.028956; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130606_1519") { livetime = 0.0214097; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130610_1350") { livetime = 0.021059; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130613_1155") { livetime = 0.109328; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130613_1732") { livetime = 0.110919; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130613_2113") { livetime = 0.111918; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130614_0100") { livetime = 0.112844; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130614_0449") { livetime = 0.112977; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130615_1110") { livetime = 0.0183495; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130617_1517") { livetime = 0.019015; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130619_1704") { livetime = 0.020228; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130619_1818") { livetime = 0.0897025; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130620_0016") { livetime = 0.0908877; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130620_0349") { livetime = 0.09275; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130620_0738") { livetime = 0.0940382; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130620_1121") { livetime = 0.0949086; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130620_1529") { livetime = 0.0417859; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130620_1906") { livetime = 0.0470023; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130620_2122") { livetime = 0.133551; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130621_0140") { livetime = 0.121955; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130621_1431") { livetime = 0.0260903; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130624_1516") { livetime = 0.0215417; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130626_1915") { livetime = 0.10052; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130626_2314") { livetime = 0.101531; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130627_0319") { livetime = 0.102078; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130627_0724") { livetime = 0.101589; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130627_1454") { livetime = 0.102223; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130627_1839") { livetime = 0.0368924; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130627_2004") { livetime = 0.115122; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130628_0001") { livetime = 0.116209; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130628_0332") { livetime = 0.11628; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130628_0727") { livetime = 0.0386019; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130628_1046") { livetime = 0.117809; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130628_1511") { livetime = 0.118032; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130628_1912") { livetime = 0.0216481; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130628_2034") { livetime = 0.9181; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130629_1843") { livetime = 1.04108; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130630_1938") { livetime = 0.783377; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130701_1507") { livetime = 0.0212153; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130701_1627") { livetime = 0.103648; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130701_2012") { livetime = 0.105213; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130702_0006") { livetime = 0.105495; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130702_0357") { livetime = 0.104872; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130702_0857") { livetime = 0.105135; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130702_1314") { livetime = 0.0639456; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130702_1916") { livetime = 0.901236; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130703_1727") { livetime = 0.976753; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130704_1736") { livetime = 0.116336; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130704_2157") { livetime = 0.124646; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130705_0229") { livetime = 0.125803; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130705_0657") { livetime = 0.125678; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130705_1120") { livetime = 0.126043; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130705_1551") { livetime = 0.06764; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130705_1907") { livetime = 0.948873; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130706_1752") { livetime = 1.05773; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130707_1924") { livetime = 0.804692; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130708_1528") { livetime = 0.0213773; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130708_1620") { livetime = 0.106272; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130708_2030") { livetime = 0.10744; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130709_0051") { livetime = 0.10865; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130709_0522") { livetime = 0.108174; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130709_0944") { livetime = 0.108947; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130709_1356") { livetime = 0.10967; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130709_2010") { livetime = 0.907826; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130710_1756") { livetime = 0.0217963; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130710_1919") { livetime = 0.946723; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130711_1808") { livetime = 0.133043; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130711_2212") { livetime = 0.136115; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130712_0239") { livetime = 0.135713; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130712_0721") { livetime = 0.135962; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130712_1158") { livetime = 0.138728; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130712_1629") { livetime = 0.137919; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130712_2125") { livetime = 0.910406; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130713_1943") { livetime = 0.639205; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130714_1121") { livetime = 1.13114; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130715_1620") { livetime = 0.0259734; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130715_1858") { livetime = 0.109361; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130715_2308") { livetime = 0.110116; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130716_0337") { livetime = 0.110263; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130716_0758") { livetime = 0.110894; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130716_1226") { livetime = 0.115802; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130716_1654") { livetime = 0.0237569; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130716_1928") { livetime = 0.0223796; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130716_2042") { livetime = 0.935662; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130717_1908") { livetime = 0.7508; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130718_1646") { livetime = 0.128191; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130718_2046") { livetime = 0.128075; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130719_0052") { livetime = 0.128346; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130719_0451") { livetime = 0.129078; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130719_0850") { livetime = 0.0347465; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130719_1132") { livetime = 0.12891; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130719_1617") { livetime = 0.0219745; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130719_1746") { livetime = 0.721361; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130720_1151") { livetime = 0.930226; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130721_1007") { livetime = 0.985455; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130722_1116") { livetime = 0.0217245; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130722_1200") { livetime = 0.108825; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130722_1558") { livetime = 0.110514; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130722_2006") { livetime = 0.111539; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130723_0032") { livetime = 0.112148; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130723_0450") { livetime = 0.112162; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130723_0906") { livetime = 0.112508; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130723_1718") { livetime = 0.986076; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130724_1655") { livetime = 0.756361; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130725_1206") { livetime = 0.121985; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130725_1624") { livetime = 0.105116; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130725_1957") { livetime = 0.160666; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130726_0101") { livetime = 0.161125; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130726_0603") { livetime = 0.161328; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130726_1112") { livetime = 0.159291; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130726_1938") { livetime = 0.884524; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130727_1649") { livetime = 0.994478; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130728_1716") { livetime = 0.848529; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130729_1440") { livetime = 0.0222106; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130729_1522") { livetime = 0.117273; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130729_1943") { livetime = 0.117877; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130730_0012") { livetime = 0.118367; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130730_0459") { livetime = 0.111345; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130730_0922") { livetime = 0.118243; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130730_1354") { livetime = 0.100787; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130730_1854") { livetime = 0.850302; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130731_1519") { livetime = 0.960051; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130801_1429") { livetime = 0.138704; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130802_1246") { livetime = 0.0709387; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130802_1453") { livetime = 0.070941; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130802_1704") { livetime = 0.0536562; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130802_1924") { livetime = 0.913803; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130803_1717") { livetime = 1.03364; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130804_1802") { livetime = 0.849525; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130805_1450") { livetime = 0.0224213; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130805_1534") { livetime = 0.059772; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130805_1743") { livetime = 0.060191; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130805_2001") { livetime = 0.0602095; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130805_2219") { livetime = 0.0602269; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130806_0037") { livetime = 0.0604988; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130806_0253") { livetime = 0.0605313; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130806_0507") { livetime = 0.0605046; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130806_0731") { livetime = 0.0605394; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130806_0949") { livetime = 0.0607431; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130806_1158") { livetime = 0.0608009; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130806_1404") { livetime = 0.0606134; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130806_1617") { livetime = 0.0225729; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130806_1807") { livetime = 0.976132; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130807_1925") { livetime = 0.710105; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130808_1240") { livetime = 0.0682211; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130808_1456") { livetime = 0.069294; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130808_1720") { livetime = 0.069456; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130808_1942") { livetime = 0.069397; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130808_2208") { livetime = 0.0696852; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130809_0033") { livetime = 0.0697847; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130809_0303") { livetime = 0.0684271; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130809_0529") { livetime = 0.0697407; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130809_0800") { livetime = 0.070353; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130809_1030") { livetime = 0.0689583; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130809_1249") { livetime = 0.0446273; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130809_1550") { livetime = 0.954617; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130810_1443") { livetime = 1.08652; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130811_1645") { livetime = 0.779819; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130812_1223") { livetime = 0.02239; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130812_1313") { livetime = 0.0570984; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130812_1510") { livetime = 0.0572407; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130812_1712") { livetime = 0.0578137; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130812_1928") { livetime = 0.0578808; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130812_2137") { livetime = 0.0578981; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130812_2348") { livetime = 0.0578935; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130813_0156") { livetime = 0.0575139; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130813_0413") { livetime = 0.0580694; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130813_0619") { livetime = 0.0583854; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130813_0827") { livetime = 0.0585139; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130813_1034") { livetime = 0.0584549; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130813_1242") { livetime = 0.0368646; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130813_1505") { livetime = 0.968888; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130814_1430") { livetime = 0.842715; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130815_1048") { livetime = 0.0839711; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130815_1319") { livetime = 0.0843877; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130815_1553") { livetime = 0.0845764; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130815_1826") { livetime = 0.0843715; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130815_2102") { livetime = 0.0847118; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130815_2338") { livetime = 0.0849132; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130816_0214") { livetime = 0.0846597; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130816_0454") { livetime = 0.0854213; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130816_0729") { livetime = 0.0854468; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130816_1010") { livetime = 0.0409282; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130816_1141") { livetime = 0.995457; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130817_1132") { livetime = 0.973043; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130818_1118") { livetime = 0.958763; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130819_1052") { livetime = 0.0190139; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130819_1137") { livetime = 0.0590243; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130819_1340") { livetime = 0.059235; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130819_1548") { livetime = 0.0592431; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130819_1752") { livetime = 0.0590301; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130819_2005") { livetime = 0.0594919; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130819_2213") { livetime = 0.0593148; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130820_0019") { livetime = 0.059713; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130820_0227") { livetime = 0.0596019; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130820_0437") { livetime = 0.0599097; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130820_0641") { livetime = 0.0599618; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130820_0847") { livetime = 0.0600949; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130820_1148") { livetime = 0.957037; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130821_1047") { livetime = 0.958979; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130822_0959") { livetime = 0.0706215; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130822_1207") { livetime = 0.0710498; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130822_1419") { livetime = 0.0711736; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130822_1632") { livetime = 0.0717153; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130822_1848") { livetime = 0.0719583; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130822_2100") { livetime = 0.0715498; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130822_2318") { livetime = 0.0716065; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130823_0134") { livetime = 0.0717905; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130823_0351") { livetime = 0.0719433; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130823_0606") { livetime = 0.0724734; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130823_0825") { livetime = 0.0423403; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130823_1041") { livetime = 0.956659; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130824_0937") { livetime = 1.00043; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130825_0936") { livetime = 1.05005; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130826_1144") { livetime = 0.0221817; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130826_1233") { livetime = 0.0577245; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130826_1434") { livetime = 0.0582361; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130826_1646") { livetime = 0.0584722; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130826_1851") { livetime = 0.0585532; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130826_2106") { livetime = 0.0585463; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130826_2313") { livetime = 0.0587442; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130827_0130") { livetime = 0.0590891; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130827_0337") { livetime = 0.0593773; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130827_0548") { livetime = 0.058963; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130827_0806") { livetime = 0.0588403; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130827_1122") { livetime = 1.2689; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130828_1746") { livetime = 0.736388; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130829_1151") { livetime = 0.0689421; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130829_1407") { livetime = 0.0696829; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130829_1627") { livetime = 0.0697292; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130829_1849") { livetime = 0.0693819; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130829_2109") { livetime = 0.0695752; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130829_2331") { livetime = 0.0695891; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130830_0152") { livetime = 0.0700463; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130830_0416") { livetime = 0.0707049; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130830_0639") { livetime = 0.0701725; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130830_0905") { livetime = 0.0708275; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130830_1128") { livetime = 0.0420394; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130830_1438") { livetime = 1.0507; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130831_1550") { livetime = 0.994484; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130901_1541") { livetime = 0.789152; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130903_1133") { livetime = 0.0225289; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130903_1454") { livetime = 1.02674; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130904_1530") { livetime = 0.916086; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130905_1349") { livetime = 0.0899676; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130905_1622") { livetime = 0.0895914; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130905_1859") { livetime = 0.0902535; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130905_2134") { livetime = 0.0911366; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130906_0016") { livetime = 0.091213; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130906_0252") { livetime = 0.0901481; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130906_0528") { livetime = 0.0897419; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130906_0805") { livetime = 0.0896227; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130906_1046") { livetime = 0.0886516; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130906_1320") { livetime = 0.0898785; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130906_1557") { livetime = 0.0186875; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130906_1737") { livetime = 0.820911; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130907_1316") { livetime = 0.968903; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130908_1231") { livetime = 1.13315; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130909_1641") { livetime = 0.0224942; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130909_1757") { livetime = 0.0613021; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130909_2221") { livetime = 0.061669; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130910_0023") { livetime = 0.0617917; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130910_0234") { livetime = 0.0618958; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130910_0442") { livetime = 0.0620127; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130910_0655") { livetime = 0.0620648; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130910_0901") { livetime = 0.0625127; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130910_1112") { livetime = 0.054228; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130910_1304") { livetime = 0.0618819; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130910_1513") { livetime = 0.0616539; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130910_1723") { livetime = 0.0415197; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130910_2019") { livetime = 0.787565; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130911_1514") { livetime = 1.07365; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130912_1718") { livetime = 0.0747292; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130912_1922") { livetime = 0.0757303; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130912_2128") { livetime = 0.0754039; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130912_2336") { livetime = 0.0758831; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130913_0144") { livetime = 0.0760185; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130913_0358") { livetime = 0.0762708; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130913_0619") { livetime = 0.076022; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130913_0827") { livetime = 0.0764155; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130913_1047") { livetime = 0.0768507; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130913_1303") { livetime = 0.0765718; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130913_1524") { livetime = 0.0260799; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130913_1729") { livetime = 0.855722; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130914_1400") { livetime = 1.10016; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130915_1622") { livetime = 1.01527; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130916_1741") { livetime = 0.0226435; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130916_1823") { livetime = 0.0612095; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130916_2018") { livetime = 0.0616192; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130916_2227") { livetime = 0.0618009; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130917_0022") { livetime = 0.0620995; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130917_0224") { livetime = 0.0624294; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130917_0426") { livetime = 0.0622731; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130917_0637") { livetime = 0.0622882; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130917_0843") { livetime = 0.0623299; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130917_1043") { livetime = 0.0622199; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130917_1241") { livetime = 0.062537; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130917_1434") { livetime = 0.0623009; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130917_1643") { livetime = 0.0625544; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130917_1954") { livetime = 0.777049; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130918_1432") { livetime = 0.859731; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130919_1133") { livetime = 0.0729722; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130919_1350") { livetime = 0.0736111; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130919_1609") { livetime = 0.073669; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130919_1838") { livetime = 0.0739155; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130919_2103") { livetime = 0.0741563; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130919_2319") { livetime = 0.0742419; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130920_0141") { livetime = 0.0740741; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130920_0410") { livetime = 0.0744039; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130920_0639") { livetime = 0.0744491; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130920_0900") { livetime = 0.0554641; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130921_1333") { livetime = 0.964521; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130922_1239") { livetime = 1.13366; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130923_1612") { livetime = 0.0225868; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130923_1652") { livetime = 0.0609491; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130923_1844") { livetime = 0.0611516; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130923_2046") { livetime = 0.0613148; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130923_2246") { livetime = 0.0614734; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130924_0049") { livetime = 0.0614294; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130924_0253") { livetime = 0.061522; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130924_0500") { livetime = 0.0615463; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130924_0705") { livetime = 0.0618808; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130924_0910") { livetime = 0.0616586; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130924_1117") { livetime = 0.0616053; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130924_1319") { livetime = 0.0619537; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130924_1551") { livetime = 0.815245; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130925_1122") { livetime = 1.02988; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130926_1208") { livetime = 0.0909722; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130926_1442") { livetime = 0.0910718; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130926_1723") { livetime = 0.0911447; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130926_1956") { livetime = 0.0912396; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130926_2230") { livetime = 0.0915833; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130927_0108") { livetime = 0.0918553; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130927_0350") { livetime = 0.0920231; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130927_0626") { livetime = 0.0915093; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130927_0905") { livetime = 0.092162; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130927_1144") { livetime = 0.0921574; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130927_1425") { livetime = 0.0920764; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_130927_2036") { livetime = 0.686324; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130928_1339") { livetime = 0.966565; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130929_1306") { livetime = 0.947042; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_130930_1247") { livetime = 0.0271597; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_130930_1343") { livetime = 0.0628495; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130930_1554") { livetime = 0.0631007; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130930_1802") { livetime = 0.063037; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130930_2010") { livetime = 0.0633356; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_130930_2221") { livetime = 0.0633715; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131001_0035") { livetime = 0.0632535; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131001_0244") { livetime = 0.0635243; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131001_0455") { livetime = 0.063419; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131001_0708") { livetime = 0.0634433; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131001_0917") { livetime = 0.0633762; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131001_1123") { livetime = 0.063456; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131001_1722") { livetime = 1.01216; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131002_1857") { livetime = 0.84292; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131003_2355") { livetime = 0.076088; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131004_0211") { livetime = 0.0761412; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131004_0431") { livetime = 0.0765903; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131004_0651") { livetime = 0.0770822; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131004_0910") { livetime = 0.077037; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131004_1136") { livetime = 0.0770613; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131004_1419") { livetime = 0.0763333; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131004_1716") { livetime = 1.06301; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131005_1855") { livetime = 0.836753; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131006_1521") { livetime = 0.875096; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131007_1249") { livetime = 0.0216829; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_131007_1339") { livetime = 0.0604456; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131007_1536") { livetime = 0.0606343; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131007_1740") { livetime = 0.0609525; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131007_1948") { livetime = 0.0609074; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131007_2159") { livetime = 0.0610718; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131008_0008") { livetime = 0.0614132; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131008_0223") { livetime = 0.0614757; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131008_0438") { livetime = 0.0615613; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131008_0658") { livetime = 0.0615868; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131008_0910") { livetime = 0.0614769; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131008_1124") { livetime = 0.0615845; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131008_1339") { livetime = 0.0609722; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131008_1726") { livetime = 0.900836; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131009_1517") { livetime = 0.838997; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131010_1130") { livetime = 0.0739248; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131010_1347") { livetime = 0.0746354; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131010_1606") { livetime = 0.0749433; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131010_1823") { livetime = 0.0752465; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131010_2042") { livetime = 0.0753218; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131010_2311") { livetime = 0.0752685; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131011_0136") { livetime = 0.0753958; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131011_0407") { livetime = 0.0754132; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131011_0631") { livetime = 0.0756007; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131011_0853") { livetime = 0.0254132; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131011_0959") { livetime = 1.00542; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131012_1005") { livetime = 1.00575; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131013_1011") { livetime = 1.05345; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131014_1155") { livetime = 0.0223102; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_131014_1237") { livetime = 0.059728; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131014_1442") { livetime = 0.0600938; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131014_1652") { livetime = 0.060213; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131014_1852") { livetime = 0.0601273; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131014_2108") { livetime = 0.06014; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131014_2320") { livetime = 0.0602523; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131015_0139") { livetime = 0.0603877; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131015_0354") { livetime = 0.06064; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131015_0559") { livetime = 0.0603252; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131015_0804") { livetime = 0.0603634; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131015_1018") { livetime = 0.0347384; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131015_1141") { livetime = 0.915791; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131016_0937") { livetime = 1.00413; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131017_1035") { livetime = 0.948515; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131018_0918") { livetime = 1.05001; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131019_1027") { livetime = 1.08332; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131020_1224") { livetime = 1.13276; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131021_1554") { livetime = 0.0223391; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_131021_1700") { livetime = 0.764589; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131022_1118") { livetime = 1.08634; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131023_1320") { livetime = 0.956029; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131024_1231") { livetime = 0.920647; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131025_1035") { livetime = 1.10652; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131026_1304") { livetime = 1.19387; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131027_1655") { livetime = 0.771273; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131028_1200") { livetime = 0.0226354; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_131028_1238") { livetime = 0.901786; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131029_1015") { livetime = 1.1876; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131030_1443") { livetime = 1.05364; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131031_1829") { livetime = 0.802968; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131101_1344") { livetime = 1.35432; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131102_2209") { livetime = 0.905125; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131103_1950") { livetime = 0.662237; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131104_1215") { livetime = 0.0226192; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_131104_1301") { livetime = 1.0865; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131105_1525") { livetime = 1.02367; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131106_1556") { livetime = 1.12665; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131107_1855") { livetime = 0.822848; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131108_1439") { livetime = 1.17667; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131109_1849") { livetime = 1.04863; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131110_2003") { livetime = 0.980353; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131111_2017") { livetime = 0.0221806; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_131111_2129") { livetime = 0.0586111; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131111_2324") { livetime = 0.0591019; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131112_0124") { livetime = 0.0592037; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131112_0327") { livetime = 0.0592025; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131112_0528") { livetime = 0.0594676; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131112_0735") { livetime = 0.0596528; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131112_0940") { livetime = 0.0598681; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131112_1143") { livetime = 0.0599259; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131112_1351") { livetime = 0.05989; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131112_1558") { livetime = 0.0600046; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131112_1803") { livetime = 0.0598912; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131112_2154") { livetime = 0.738179; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131113_1756") { livetime = 1.09655; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131114_2043") { livetime = 0.0931354; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131114_2316") { livetime = 0.0932396; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131115_0154") { livetime = 0.0925093; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131115_0429") { livetime = 0.0920266; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131115_0706") { livetime = 0.091566; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131115_0941") { livetime = 0.0911065; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131115_1218") { livetime = 0.0913032; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131115_1458") { livetime = 0.0910069; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131115_1739") { livetime = 0.00373032; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131115_1951") { livetime = 1.04373; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131116_2103") { livetime = 0.0227766; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_131116_2143") { livetime = 0.85878; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131117_1819") { livetime = 0.630394; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131118_0939") { livetime = 0.457642; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131118_2124") { livetime = 0.707067; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131119_1824") { livetime = 0.0613889; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131119_2021") { livetime = 0.0619444; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131119_2223") { livetime = 0.0617604; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131120_0021") { livetime = 0.0619132; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131120_0221") { livetime = 0.0624595; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131120_0755") { livetime = 0.0617882; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131120_0956") { livetime = 0.0499132; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131120_1141") { livetime = 0.027603; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_131120_1241") { livetime = 0.858595; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131121_0926") { livetime = 0.37489; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131121_1833") { livetime = 0.0795775; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131121_2048") { livetime = 0.0802396; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131121_2309") { livetime = 0.0805417; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131122_0130") { livetime = 0.0805046; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131122_0349") { livetime = 0.0804317; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131122_0613") { livetime = 0.0807454; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131122_1006") { livetime = 1.27711; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131123_1641") { livetime = 0.975656; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131124_1603") { livetime = 0.756082; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131125_1046") { livetime = 0.025265; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_131125_1209") { livetime = 0.935927; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131126_1033") { livetime = 1.20937; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131127_1552") { livetime = 0.0608287; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131127_1801") { livetime = 0.0610046; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131127_2017") { livetime = 0.060963; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131127_2234") { livetime = 0.0613646; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131128_0049") { livetime = 0.0613472; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131128_0307") { livetime = 0.0612847; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131128_0521") { livetime = 0.0611586; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131128_0737") { livetime = 0.0612581; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131128_0951") { livetime = 0.0614722; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131128_1209") { livetime = 0.0612755; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131128_1404") { livetime = 0.0245382; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131128_1504") { livetime = 0.841802; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131129_1123") { livetime = 0.0681354; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131129_1326") { livetime = 0.0886632; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131129_1554") { livetime = 0.0886586; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131129_1831") { livetime = 0.089169; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131129_2114") { livetime = 0.0892384; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131130_0001") { livetime = 0.089125; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131130_0251") { livetime = 0.0893877; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131130_0538") { livetime = 0.0895775; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131130_0826") { livetime = 0.0901319; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131130_1108") { livetime = 0.090603; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131130_1351") { livetime = 0.0122118; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131130_1415") { livetime = 1.14909; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131201_1903") { livetime = 0.679956; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131202_1148") { livetime = 0.022235; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_131202_1225") { livetime = 0.0592535; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131202_1425") { livetime = 0.0596412; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131202_1630") { livetime = 0.059772; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131202_1836") { livetime = 0.0592512; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131202_2042") { livetime = 0.0595498; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131202_2250") { livetime = 0.0594722; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131203_0103") { livetime = 0.0594456; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131203_0309") { livetime = 0.0597442; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131203_0515") { livetime = 0.0593507; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131203_0725") { livetime = 0.0597581; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131203_0938") { livetime = 0.0577639; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131203_1148") { livetime = 0.983581; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131204_1255") { livetime = 0.925404; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131205_1227") { livetime = 0.0745602; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131205_1446") { livetime = 0.0750764; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131205_1711") { livetime = 0.0753681; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131205_1938") { livetime = 0.0756343; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131205_2209") { livetime = 0.0756806; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131206_0041") { livetime = 0.0760463; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131206_0309") { livetime = 0.078919; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131206_0533") { livetime = 0.0782153; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131206_0757") { livetime = 0.078662; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131206_1019") { livetime = 0.0790475; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131206_1337") { livetime = 0.920941; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131207_1303") { livetime = 0.924023; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131208_1210") { livetime = 0.939891; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131209_1453") { livetime = 0.0226343; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_131209_1541") { livetime = 0.0602199; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131209_1745") { livetime = 0.0606817; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131209_1954") { livetime = 0.0609375; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131209_2207") { livetime = 0.0608785; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131210_0014") { livetime = 0.0606782; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131210_0228") { livetime = 0.060566; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131210_0436") { livetime = 0.0605741; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131210_0649") { livetime = 0.0604606; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131210_0855") { livetime = 0.0606111; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131210_1102") { livetime = 0.0608854; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131210_1308") { livetime = 0.0606458; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131210_1653") { livetime = 0.771206; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131211_1728") { livetime = 0.899765; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131212_1714") { livetime = 0.0805243; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131212_1938") { livetime = 0.0809306; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131212_2204") { livetime = 0.0810868; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131213_0029") { livetime = 0.0815162; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131213_0258") { livetime = 0.0812083; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131213_0523") { livetime = 0.0814444; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131213_0749") { livetime = 0.0818171; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131213_1018") { livetime = 0.0816157; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131213_1244") { livetime = 0.0819595; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131213_1512") { livetime = 0.0321956; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131213_1727") { livetime = 0.962353; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131214_1705") { livetime = 0.988916; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131215_1703") { livetime = 0.625907; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131216_1128") { livetime = 0.0226771; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_131216_1214") { livetime = 0.0626481; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131216_1409") { livetime = 0.0642269; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131216_1610") { livetime = 0.0634329; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131216_1819") { livetime = 0.0631968; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131216_2026") { livetime = 0.0625613; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131216_2233") { livetime = 0.0628113; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131217_0043") { livetime = 0.0627419; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131217_0252") { livetime = 0.0630139; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131217_0502") { livetime = 0.0627905; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131217_0711") { livetime = 0.0625752; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131217_0924") { livetime = 0.0627951; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131217_1131") { livetime = 0.0631667; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131217_1435") { livetime = 0.0230301; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_131217_1607") { livetime = 0.960245; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131218_1616") { livetime = 0.784677; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131219_1252") { livetime = 0.0896979; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131219_1524") { livetime = 0.090213; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131219_1756") { livetime = 0.0893715; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131219_2027") { livetime = 0.0892778; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131219_2300") { livetime = 0.0884988; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131220_0134") { livetime = 0.0887454; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131220_0407") { livetime = 0.0882049; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131220_0640") { livetime = 0.0882951; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131220_0911") { livetime = 0.0887176; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131220_1146") { livetime = 0.0895347; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131220_1421") { livetime = 0.011412; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131220_1448") { livetime = 0.0227975; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_131220_1626") { livetime = 0.682396; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131221_0937") { livetime = 1.22269; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131222_1503") { livetime = 0.762289; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131223_1523") { livetime = 0.0228426; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_131223_1612") { livetime = 0.0602373; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131223_1810") { livetime = 0.0605035; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131223_2013") { livetime = 0.0610613; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131223_2217") { livetime = 0.0612002; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131224_0022") { livetime = 0.0613553; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131224_0231") { livetime = 0.0618449; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131224_0447") { livetime = 0.0616065; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131224_0701") { livetime = 0.0619387; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131224_0908") { livetime = 0.0615856; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131224_1114") { livetime = 0.0622303; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131224_1324") { livetime = 0.0127303; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131224_1535") { livetime = 1.01646; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131225_1557") { livetime = 0.977353; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131226_1536") { livetime = 0.076897; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_131227_1607") { livetime = 1.04703; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131228_1712") { livetime = 1.02661; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131229_1745") { livetime = 0.889998; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_131230_1543") { livetime = 0.0135081; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_131230_1623") { livetime = 0.061088; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131230_1820") { livetime = 0.0611076; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131230_2023") { livetime = 0.0614248; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131230_2225") { livetime = 0.0614861; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131231_0031") { livetime = 0.0614444; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131231_0234") { livetime = 0.0616366; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131231_0441") { livetime = 0.0615475; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131231_0648") { livetime = 0.0618229; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131231_0851") { livetime = 0.0619722; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131231_1058") { livetime = 0.062338; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131231_1303") { livetime = 0.0368796; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_131231_1548") { livetime = 0.9917; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_140101_1531") { livetime = 1.10645; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_140102_1818") { livetime = 0.0788507; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_140102_2035") { livetime = 0.0792836; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_140102_2259") { livetime = 0.0795058; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_140103_0124") { livetime = 0.0794688; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_140103_0347") { livetime = 0.0800185; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_140103_0611") { livetime = 0.0800185; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_140103_0837") { livetime = 0.0804919; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_140103_1101") { livetime = 0.0802141; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_140103_1331") { livetime = 0.0808634; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_140103_1559") { livetime = 0.01675; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_140103_1701") { livetime = 1.02528; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_140104_1734") { livetime = 1.00491; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_140105_1736") { livetime = 0.873596; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_140106_1451") { livetime = 0.0226701; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_140106_1532") { livetime = 0.0608692; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_140106_1729") { livetime = 0.0614514; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_140106_1930") { livetime = 0.0614734; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_140106_2136") { livetime = 0.0617512; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_140106_2344") { livetime = 0.0621354; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_140107_0148") { livetime = 0.0616343; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_140107_0357") { livetime = 0.0621204; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_140107_0604") { livetime = 0.0619421; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_140107_0808") { livetime = 0.0619051; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_140107_1020") { livetime = 0.037956; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_140107_1251") { livetime = 1.06232; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_140108_1432") { livetime = 0.149675; isotope = "DM"; return livetime;}
	 
	 cout << "XenonDataReader::DatasetLivetime()  --- WARNING: dataset_name not found!  return 0. " << endl;
	return livetime;

	}
