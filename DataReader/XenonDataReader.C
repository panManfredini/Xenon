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

  bool  XenonDataReader:: 	Inelastic_Xs2single0()
	{
	  if(S2sTot->size() > 1) return ((*S2sTot)[1] < 160.);
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
	//  RUN 12 DATA STD
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


	// RUN 10 DATA STD
	 if(dataset_name == "xe100_110207_1015") { livetime = 0.020963; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110210_1100") { livetime = 0.00234028; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_110210_1106") { livetime = 0.129301; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_110210_1412") { livetime = 0.0135648; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_110210_1502") { livetime = 0.0708657; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_110210_1709") { livetime = 0.0787014; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_110210_1926") { livetime = 0.114773; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_110210_2211") { livetime = 0.0583021; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_110210_2341") { livetime = 0.0361574; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_110211_0059") { livetime = 0.0936979; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_110211_0315") { livetime = 0.0936007; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_110211_0532") { livetime = 0.0263252; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_110211_0614") { livetime = 0.138917; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_110211_0935") { livetime = 0.130538; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_110211_1243") { livetime = 0.109645; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_110211_1650") { livetime = 0.0205382; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110216_1055") { livetime = 0.0220984; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110223_1107") { livetime = 0.0222257; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110228_1427") { livetime = 0.0765694; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110302_1945") { livetime = 0.459122; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110303_1040") { livetime = 0.0160961; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110303_1203") { livetime = 1.05488; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110304_1639") { livetime = 0.129881; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110304_2304") { livetime = 0.549884; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110305_1216") { livetime = 0.916273; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110306_1105") { livetime = 1.00938; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110307_1308") { livetime = 0.794212; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110308_1028") { livetime = 0.0312315; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110308_1154") { livetime = 1.05973; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110309_1431") { livetime = 0.793709; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110310_1206") { livetime = 0.119558; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110310_1558") { livetime = 0.623892; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110311_1413") { livetime = 0.108233; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110311_1806") { livetime = 0.115803; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110311_2244") { livetime = 0.0975937; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110312_0213") { livetime = 0.115248; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110312_0551") { livetime = 0.116987; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110312_1101") { livetime = 0.119267; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110312_1439") { livetime = 0.121328; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110312_1823") { livetime = 0.121568; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110312_2335") { livetime = 0.101578; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110313_0255") { livetime = 0.117199; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110313_0631") { livetime = 0.118501; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110313_1351") { livetime = 0.119501; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110313_2303") { livetime = 0.125681; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110314_0251") { livetime = 0.129194; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110314_1604") { livetime = 0.128831; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110315_0952") { livetime = 0.0959549; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110315_1246") { livetime = 0.0185174; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110315_1334") { livetime = 0.107569; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110315_1844") { livetime = 0.0784873; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110315_2142") { livetime = 0.0947315; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110316_0206") { livetime = 0.10415; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110316_0609") { livetime = 0.104582; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110316_1130") { livetime = 0.925786; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110317_1132") { livetime = 0.00945833; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110317_1226") { livetime = 0.956865; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110318_1156") { livetime = 0.857267; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110319_0948") { livetime = 0.0881319; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110319_1302") { livetime = 0.0988831; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110319_1630") { livetime = 0.10403; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110319_2016") { livetime = 0.0694491; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110319_2235") { livetime = 0.753241; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110320_1715") { livetime = 0.0875764; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110320_2040") { livetime = 0.0903785; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110321_0014") { livetime = 0.0925995; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110321_0354") { livetime = 0.0853333; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110321_0729") { livetime = 0.0841505; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110321_1058") { livetime = 0.015015; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110322_1055") { livetime = 0.938988; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110323_1114") { livetime = 0.016265; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110323_1156") { livetime = 0.0994016; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110323_1515") { livetime = 0.0977083; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110323_1924") { livetime = 0.0982882; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110323_2247") { livetime = 0.095941; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110324_0230") { livetime = 0.107038; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110324_0610") { livetime = 0.104308; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110324_0947") { livetime = 0.10381; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110324_1722") { livetime = 0.894734; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110325_1549") { livetime = 0.0215903; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110325_1631") { livetime = 0.126858; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110326_1237") { livetime = 0.131485; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110326_1642") { livetime = 0.129941; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110326_2035") { livetime = 0.129741; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110327_0031") { livetime = 0.131427; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110327_0532") { livetime = 0.140047; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110327_1003") { livetime = 0.133067; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110327_1410") { livetime = 0.132965; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110327_1814") { livetime = 0.133955; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110327_2256") { livetime = 0.133339; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110328_0307") { livetime = 0.10509; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110328_0631") { livetime = 0.135667; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110328_1143") { livetime = 0.134602; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110328_1557") { livetime = 0.136819; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110328_2032") { livetime = 1.73259; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110330_1457") { livetime = 0.00409722; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110330_1725") { livetime = 0.135054; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110331_0004") { livetime = 0.136358; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110331_0410") { livetime = 0.137089; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110331_0826") { livetime = 0.137787; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110331_1558") { livetime = 0.14276; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110331_2014") { livetime = 0.143471; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110401_0032") { livetime = 0.143583; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110401_0453") { livetime = 0.143137; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110401_1418") { livetime = 0.137984; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110401_2017") { livetime = 0.0234479; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110401_2058") { livetime = 0.984443; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110402_2120") { livetime = 1.69742; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110404_1436") { livetime = 0.119181; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110404_1954") { livetime = 0.136378; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110405_0004") { livetime = 0.136169; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110405_0415") { livetime = 0.13705; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110405_1347") { livetime = 0.135111; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110405_1757") { livetime = 0.0165347; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110405_1844") { livetime = 0.114899; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110405_2312") { livetime = 0.115685; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110406_0320") { livetime = 0.116985; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110406_0751") { livetime = 0.11594; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110406_1203") { livetime = 0.115111; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110406_1602") { livetime = 0.115142; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110406_2005") { livetime = 0.114775; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110406_2354") { livetime = 0.114681; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110407_0352") { livetime = 0.11452; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110407_0752") { livetime = 0.0575417; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110407_1555") { livetime = 0.770642; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110408_1212") { livetime = 3.01209; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110411_1530") { livetime = 0.14403; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110411_2340") { livetime = 0.145036; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110412_0857") { livetime = 0.139745; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110412_1355") { livetime = 0.146242; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110412_1847") { livetime = 0.0266238; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110412_1935") { livetime = 0.62875; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110413_1117") { livetime = 0.44359; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110414_1640") { livetime = 0.112235; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110415_0117") { livetime = 0.000217593; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110415_0130") { livetime = 0.111391; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110415_0546") { livetime = 0.113781; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110415_1009") { livetime = 0.113704; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110415_1717") { livetime = 0.034956; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110415_1949") { livetime = 0.827745; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110416_1557") { livetime = 1.03344; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110417_1919") { livetime = 0.79905; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110418_1629") { livetime = 0.0201053; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110418_1709") { livetime = 0.119354; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110418_2117") { livetime = 0.11953; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110419_0125") { livetime = 0.120388; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110419_0547") { livetime = 0.121851; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110419_1009") { livetime = 0.121931; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110419_1732") { livetime = 0.265748; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110420_1133") { livetime = 0.224552; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110420_1755") { livetime = 0.712084; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110421_1152") { livetime = 0.121713; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110421_1552") { livetime = 0.121608; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110421_2003") { livetime = 0.126334; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110422_0018") { livetime = 0.128016; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110422_0500") { livetime = 0.126602; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110422_1200") { livetime = 1.02928; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110423_1252") { livetime = 0.95733; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110424_1147") { livetime = 0.962573; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110425_1129") { livetime = 0.0208785; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110425_1210") { livetime = 0.114075; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110425_1614") { livetime = 0.114943; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110425_2018") { livetime = 0.114843; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110426_0016") { livetime = 0.114551; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110426_0429") { livetime = 0.114581; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110428_1202") { livetime = 0.99634; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110429_1154") { livetime = 0.984281; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110430_1142") { livetime = 1.04129; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110501_1237") { livetime = 1.11023; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110502_1658") { livetime = 0.0207917; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110502_1740") { livetime = 0.105289; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110502_2046") { livetime = 0.104074; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110503_1639") { livetime = 0.753022; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110505_1158") { livetime = 0.114753; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110505_1517") { livetime = 0.116351; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110505_1858") { livetime = 0.115422; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110506_0010") { livetime = 0.497986; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110506_1214") { livetime = 0.994907; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110507_1203") { livetime = 0.987262; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110508_1158") { livetime = 1.15795; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110509_1659") { livetime = 0.0209398; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110509_1741") { livetime = 0.141867; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110509_2148") { livetime = 0.144075; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110510_0200") { livetime = 0.142836; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110510_0616") { livetime = 0.0704734; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110510_1055") { livetime = 0.946738; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110511_1402") { livetime = 1.11845; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110512_1816") { livetime = 0.107755; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110512_2204") { livetime = 0.108027; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110513_0201") { livetime = 0.108757; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110513_0534") { livetime = 0.0713333; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110513_0854") { livetime = 0.312612; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110513_1741") { livetime = 0.720947; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110514_1058") { livetime = 1.01115; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110515_1330") { livetime = 1.07415; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110516_1713") { livetime = 0.0201875; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110516_1754") { livetime = 0.136625; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110516_2149") { livetime = 0.137737; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110517_0156") { livetime = 0.138245; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110517_0600") { livetime = 0.0821563; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110517_0847") { livetime = 0.245755; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110517_1511") { livetime = 0.0412188; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110517_1616") { livetime = 0.00138542; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110517_1645") { livetime = 0.00428241; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110517_1712") { livetime = 0.0805845; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110517_1911") { livetime = 0.800069; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110518_1421") { livetime = 1.1486; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110519_1854") { livetime = 0.127156; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110519_2247") { livetime = 0.127769; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110520_0240") { livetime = 0.128845; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110520_0651") { livetime = 0.0478877; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110520_0930") { livetime = 0.315368; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110520_1740") { livetime = 0.937481; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110521_1606") { livetime = 0.96736; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110522_1515") { livetime = 0.172589; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110522_2011") { livetime = 0.877557; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110523_1809") { livetime = 0.020735; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110523_2011") { livetime = 0.463862; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110524_0851") { livetime = 0.0312083; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110524_1111") { livetime = 0.388572; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110524_2049") { livetime = 0.133365; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110525_0058") { livetime = 0.145418; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110525_0519") { livetime = 0.135747; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110525_0924") { livetime = 0.00379977; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110525_0952") { livetime = 0.0510185; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110525_1146") { livetime = 1.00988; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110526_1216") { livetime = 0.310071; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110526_2007") { livetime = 0.118926; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110526_2357") { livetime = 0.120042; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110527_0344") { livetime = 0.119378; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110527_0748") { livetime = 0.0329838; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110527_0941") { livetime = 0.390856; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110527_1909") { livetime = 0.990472; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110528_1931") { livetime = 0.849814; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110529_1626") { livetime = 1.03221; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110530_1958") { livetime = 0.0209259; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110530_2047") { livetime = 0.142694; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110531_0050") { livetime = 0.143035; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110531_0500") { livetime = 0.142546; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110531_0917") { livetime = 0.00972685; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110531_1005") { livetime = 1.06124; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110601_1130") { livetime = 1.31313; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110602_1937") { livetime = 0.113801; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110602_2334") { livetime = 0.114237; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110603_0336") { livetime = 0.114535; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110603_0755") { livetime = 0.0333252; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110603_0921") { livetime = 1.16698; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110604_1400") { livetime = 0.914263; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110605_1154") { livetime = 1.25346; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110606_1927") { livetime = 0.0187951; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110606_2002") { livetime = 0.138251; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110607_0005") { livetime = 0.142681; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110607_0422") { livetime = 0.143418; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110607_0840") { livetime = 0.0287176; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110607_0944") { livetime = 0.257536; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110607_1633") { livetime = 1.05819; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110608_1818") { livetime = 1.0367; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110609_2020") { livetime = 0.132728; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110610_0025") { livetime = 0.128758; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110610_0425") { livetime = 0.131407; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110610_0836") { livetime = 0.0270972; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110610_1028") { livetime = 1.00448; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110611_1032") { livetime = 1.05622; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110612_1150") { livetime = 1.11629; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110613_1643") { livetime = 0.0106829; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110613_1723") { livetime = 0.0756042; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110613_1918") { livetime = 0.140471; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110613_2328") { livetime = 0.140206; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110614_0344") { livetime = 0.133506; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110614_0749") { livetime = 0.0365903; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110614_1026") { livetime = 0.037588; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110614_1138") { livetime = 1.13044; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110615_1504") { livetime = 1.15033; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110616_1840") { livetime = 0.0125405; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110616_1946") { livetime = 0.120161; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110616_2352") { livetime = 0.120301; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110617_0352") { livetime = 0.119628; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110617_0758") { livetime = 0.0415475; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110617_1021") { livetime = 0.984447; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110618_1204") { livetime = 0.874662; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110619_1303") { livetime = 0.86913; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110620_1035") { livetime = 0.0194826; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110620_1116") { livetime = 0.233373; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110620_1701") { livetime = 0.0925081; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110620_1917") { livetime = 0.280417; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110621_0201") { livetime = 0.280735; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110621_0844") { livetime = 0.0594711; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110621_1010") { livetime = 0.263799; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110621_1629") { livetime = 0.261684; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110621_2246") { livetime = 0.0272014; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110621_2326") { livetime = 0.231057; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110622_0459") { livetime = 0.169458; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110622_0932") { livetime = 0.0212847; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110622_1139") { livetime = 0.101413; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110622_1405") { livetime = 0.368626; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110622_2254") { livetime = 0.846067; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110623_1938") { livetime = 0.108374; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110623_2331") { livetime = 0.118469; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110624_0336") { livetime = 0.11892; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110624_0745") { livetime = 0.0740174; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110624_1210") { livetime = 0.976016; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110625_1131") { livetime = 0.956863; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110626_1024") { livetime = 0.930597; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110627_0911") { livetime = 0.220014; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110627_1836") { livetime = 0.020162; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110627_1919") { livetime = 0.671853; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110628_2015") { livetime = 0.143216; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110629_0027") { livetime = 0.143354; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110629_0444") { livetime = 0.142068; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110629_0858") { livetime = 0.141869; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110629_1519") { livetime = 0.00101389; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110629_1813") { livetime = 0.839834; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110701_1045") { livetime = 0.141297; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110701_1503") { livetime = 0.0977002; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110706_0924") { livetime = 1.01051; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110707_1015") { livetime = 0.020456; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110707_1113") { livetime = 0.936428; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110708_1016") { livetime = 0.964006; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110709_1016") { livetime = 0.835939; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110710_0628") { livetime = 1.17041; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110711_1106") { livetime = 0.024772; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110711_1253") { livetime = 0.279677; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110711_1943") { livetime = 0.140851; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110711_2347") { livetime = 0.142425; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110712_0358") { livetime = 0.142367; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110712_0813") { livetime = 0.0367859; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110712_1017") { livetime = 0.0236597; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110712_1134") { livetime = 0.975874; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110713_1153") { livetime = 0.92185; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110714_1015") { livetime = 0.288034; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110714_1720") { livetime = 0.122565; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110714_2113") { livetime = 0.123502; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110715_0112") { livetime = 0.123391; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110715_1119") { livetime = 0.99374; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110716_1115") { livetime = 0.988723; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110717_1057") { livetime = 1.0388; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110718_1317") { livetime = 0.0585451; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110718_1511") { livetime = 0.0253194; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110718_1807") { livetime = 0.141517; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110718_2224") { livetime = 0.142792; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110719_1117") { livetime = 1.00102; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110720_1126") { livetime = 1.26295; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110721_1747") { livetime = 0.0995683; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110721_2152") { livetime = 0.114921; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110722_0142") { livetime = 0.117356; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110722_1042") { livetime = 0.961685; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110723_0944") { livetime = 1.14006; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110724_1338") { livetime = 0.873028; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110725_1032") { livetime = 0.228943; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110725_1714") { livetime = 0.0220602; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110725_1755") { livetime = 0.138242; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110725_2152") { livetime = 0.140274; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110726_0156") { livetime = 0.141389; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110726_1029") { livetime = 0.983113; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110727_1000") { livetime = 0.151818; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110727_1519") { livetime = 0.818402; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110728_1736") { livetime = 0.135135; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110728_2143") { livetime = 0.145439; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110729_0155") { livetime = 0.145385; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110729_0615") { livetime = 0.140852; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110729_1126") { livetime = 1.27884; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110730_1806") { livetime = 0.718115; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110731_1137") { livetime = 1.17638; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110801_1832") { livetime = 0.0233414; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110801_1929") { livetime = 0.142979; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110801_2332") { livetime = 0.142832; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110802_0338") { livetime = 0.143611; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110802_0748") { livetime = 0.106487; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110802_1215") { livetime = 0.989493; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110803_1215") { livetime = 1.28091; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110804_2035") { livetime = 0.123785; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110805_0016") { livetime = 0.125378; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110805_0406") { livetime = 0.126058; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110805_0806") { livetime = 0.12728; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110805_1531") { livetime = 1.00642; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110806_1541") { livetime = 0.977094; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110807_1609") { livetime = 0.990321; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110808_1708") { livetime = 0.0209109; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110808_1804") { livetime = 0.138012; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110808_2156") { livetime = 0.138462; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110809_0150") { livetime = 0.139994; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110809_0550") { livetime = 0.140084; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110809_1134") { livetime = 1.21344; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110810_1637") { livetime = 1.0056; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110811_1658") { livetime = 0.110918; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110812_1115") { livetime = 1.15437; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110813_1510") { livetime = 0.908619; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110814_1312") { livetime = 0.973524; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110815_1328") { livetime = 0.0220208; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110815_1416") { livetime = 0.141337; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110815_1754") { livetime = 0.142795; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110815_2135") { livetime = 0.142094; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110816_0121") { livetime = 0.13745; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110816_1242") { livetime = 0.239786; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110818_1812") { livetime = 0.122431; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110818_2138") { livetime = 0.123192; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110819_0115") { livetime = 0.123325; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110819_0523") { livetime = 0.0697731; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110819_1137") { livetime = 1.08369; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110820_1407") { livetime = 0.885672; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110821_1120") { livetime = 1.12293; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110822_1501") { livetime = 0.0206366; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110822_1552") { livetime = 0.143014; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110822_1934") { livetime = 0.144189; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110822_2317") { livetime = 0.143243; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110823_0303") { livetime = 0.143828; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110823_1247") { livetime = 1.07428; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110825_1839") { livetime = 0.145486; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110825_2226") { livetime = 0.146726; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110826_0219") { livetime = 0.14711; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110826_0609") { livetime = 0.14394; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110826_1354") { livetime = 0.250468; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110827_0904") { livetime = 1.0155; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110828_0942") { livetime = 0.46252; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110828_2049") { livetime = 0.738191; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110829_1516") { livetime = 0.0207002; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110829_1554") { livetime = 0.144637; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110830_1057") { livetime = 0.942875; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110831_0932") { livetime = 0.493889; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110831_2122") { livetime = 0.805451; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110901_1647") { livetime = 0.129863; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110901_2040") { livetime = 0.130073; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110902_0029") { livetime = 0.130738; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110902_0430") { livetime = 0.131081; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110902_1039") { livetime = 0.942674; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110903_0914") { livetime = 0.465955; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110903_2038") { livetime = 0.93609; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110904_1933") { livetime = 0.779512; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110905_1435") { livetime = 0.0203646; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110905_1511") { livetime = 0.126523; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110905_1900") { livetime = 0.126233; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110905_2303") { livetime = 0.128032; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110906_0308") { livetime = 0.128021; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110906_1211") { livetime = 0.88695; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110907_0925") { livetime = 1.07432; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110908_1239") { livetime = 0.124501; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110908_1632") { livetime = 0.1254; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110908_2038") { livetime = 0.125569; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110909_0036") { livetime = 0.126277; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110909_0456") { livetime = 0.0775532; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110909_0831") { livetime = 0.0765058; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110909_1133") { livetime = 0.876573; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110910_0836") { livetime = 1.20988; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110911_1352") { livetime = 1.15029; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110912_1809") { livetime = 0.0253414; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110912_1856") { livetime = 0.0920394; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110912_2142") { livetime = 0.138765; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110913_0141") { livetime = 0.141882; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110913_0544") { livetime = 0.101502; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110913_0840") { livetime = 0.000547454; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110913_0916") { livetime = 0.0642951; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110913_1050") { livetime = 0.974543; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110914_1042") { livetime = 0.991331; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110915_1026") { livetime = 0.251541; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110915_1634") { livetime = 0.149722; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110916_0940") { livetime = 0.0607766; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110916_1148") { livetime = 0.979052; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110917_1114") { livetime = 0.898769; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110918_0846") { livetime = 1.02299; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110919_0932") { livetime = 0.323519; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110919_1747") { livetime = 0.023412; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_110919_1833") { livetime = 0.144907; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110919_2238") { livetime = 0.14586; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110920_0247") { livetime = 0.147142; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110920_0658") { livetime = 0.0638854; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_110920_0933") { livetime = 1.0993; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_110922_1649") { livetime = 0.0521956; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110922_1846") { livetime = 0.0445394; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110922_2038") { livetime = 0.0467963; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110922_2236") { livetime = 0.0467512; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_110927_1949") { livetime = 0.0089838; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111001_1232") { livetime = 0.020375; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111001_1313") { livetime = 0.0164826; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111001_1629") { livetime = 0.0127384; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111001_1703") { livetime = 0.0226134; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111002_1646") { livetime = 0.0207326; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111002_1728") { livetime = 0.0254259; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111002_1817") { livetime = 0.0231817; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111002_1925") { livetime = 0.0232396; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111002_2248") { livetime = 0.0232338; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111003_0918") { livetime = 0.0233495; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111003_1200") { livetime = 0.0235139; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111004_0944") { livetime = 0.0254398; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111004_1038") { livetime = 0.0468333; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111004_1152") { livetime = 0.0565903; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111004_1414") { livetime = 0.0534271; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111004_1553") { livetime = 0.0468333; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111004_1708") { livetime = 0.0561956; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111004_1835") { livetime = 0.0531435; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111004_1957") { livetime = 0.268722; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111005_1038") { livetime = 0.0544537; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111005_1157") { livetime = 0.0539132; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111005_1315") { livetime = 0.0540081; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111005_1434") { livetime = 0.0540868; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111005_1553") { livetime = 0.0536285; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111005_1756") { livetime = 0.0530116; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111005_1914") { livetime = 0.0534792; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111005_2031") { livetime = 0.0528461; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111005_2148") { livetime = 0.0532442; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111005_2306") { livetime = 0.0532778; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111006_1710") { livetime = 0.0261412; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111007_1112") { livetime = 0.0218009; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111007_1813") { livetime = 0.764491; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111008_1250") { livetime = 0.314545; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111008_2038") { livetime = 0.659713; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111009_1300") { livetime = 0.450662; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111010_0004") { livetime = 0.615337; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111010_1454") { livetime = 0.0260127; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111010_1658") { livetime = 0.145148; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_111010_2105") { livetime = 0.145883; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_111011_0119") { livetime = 0.146046; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_111011_0530") { livetime = 0.146674; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_111011_1505") { livetime = 0.419652; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111012_0109") { livetime = 0.526892; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111012_1346") { livetime = 0.830219; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111013_1001") { livetime = 0.0220729; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111013_1042") { livetime = 0.132743; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_111013_1449") { livetime = 0.124572; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_111013_1858") { livetime = 0.133522; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_111013_2317") { livetime = 0.1349; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_111014_1027") { livetime = 0.597425; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111015_0046") { livetime = 0.982162; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111016_0032") { livetime = 0.989071; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111017_0028") { livetime = 0.36059; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111017_0959") { livetime = 0.0218252; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111017_1045") { livetime = 0.15163; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_111017_1500") { livetime = 0.152733; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_111017_1917") { livetime = 0.152596; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_111017_2333") { livetime = 0.153098; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_111019_1034") { livetime = 1.04824; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111020_1226") { livetime = 0.0219826; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111020_1340") { livetime = 0.937605; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111021_1207") { livetime = 0.944326; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111022_1043") { livetime = 1.00432; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111023_1101") { livetime = 1.09249; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111024_1438") { livetime = 0.0266134; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111024_1526") { livetime = 0.154664; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_111024_1942") { livetime = 0.154318; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_111025_0004") { livetime = 0.154959; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_111025_0424") { livetime = 0.155597; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_111025_1017") { livetime = 1.05415; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111026_1152") { livetime = 0.936499; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111027_1041") { livetime = 0.160906; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_111027_1505") { livetime = 0.161081; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_111027_1933") { livetime = 0.0859375; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_111027_2203") { livetime = 0.549434; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111028_1112") { livetime = 1.00538; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111029_1131") { livetime = 1.02838; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111030_1107") { livetime = 1.15307; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111031_1535") { livetime = 0.0246632; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111031_1618") { livetime = 0.150645; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_111031_2027") { livetime = 0.0957998; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_111031_2323") { livetime = 0.152186; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_111101_0338") { livetime = 0.152707; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_111101_0759") { livetime = 0.120513; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_111101_1223") { livetime = 0.456928; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111103_1859") { livetime = 0.0243796; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111104_1512") { livetime = 0.0115787; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111106_1824") { livetime = 0.0180532; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111107_1443") { livetime = 0.0165162; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111108_0040") { livetime = 0.0165556; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111108_1215") { livetime = 0.0156794; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111109_0003") { livetime = 0.0153565; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111109_1121") { livetime = 0.0150046; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111109_2333") { livetime = 0.0151863; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111110_1127") { livetime = 0.014103; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111110_1924") { livetime = 0.0142986; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111111_0905") { livetime = 0.0117593; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111111_1111") { livetime = 0.00378356; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111112_0912") { livetime = 0.0110289; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111112_1659") { livetime = 0.0104063; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111113_0925") { livetime = 0.0110278; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111113_1710") { livetime = 0.0116065; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111114_1858") { livetime = 0.00910301; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111115_0932") { livetime = 0.0122338; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111116_1358") { livetime = 0.0212222; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111117_0939") { livetime = 0.0220104; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111117_1812") { livetime = 0.0233333; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111118_1003") { livetime = 0.00573495; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111118_1635") { livetime = 0.0045; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111119_1050") { livetime = 0.00330671; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111120_1756") { livetime = 0.00228125; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111121_1449") { livetime = 0.0209201; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111122_1202") { livetime = 0.0278356; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111123_1158") { livetime = 0.0283924; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111124_1207") { livetime = 0.0011713; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111128_1051") { livetime = 0.0252164; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111202_1029") { livetime = 0.0161736; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111205_1013") { livetime = 0.0209444; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111205_1050") { livetime = 0.023809; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111205_1130") { livetime = 0.0205231; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111205_1208") { livetime = 0.109238; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_111205_1648") { livetime = 0.138494; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_111205_2042") { livetime = 0.13477; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_111206_0035") { livetime = 0.135622; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_111206_0432") { livetime = 0.12789; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_111207_1845") { livetime = 0.926449; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111208_1737") { livetime = 0.743703; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111209_1220") { livetime = 0.93235; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111210_1053") { livetime = 0.944488; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111211_1055") { livetime = 1.16638; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111212_1533") { livetime = 0.0126389; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111212_1718") { livetime = 0.137711; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_111212_2128") { livetime = 0.139247; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_111213_0148") { livetime = 0.14048; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_111213_0616") { livetime = 0.14052; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_111213_1122") { livetime = 0.975657; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111214_1117") { livetime = 0.993963; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111215_1113") { livetime = 0.307738; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111215_1839") { livetime = 0.147517; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_111215_2253") { livetime = 0.14756; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_111216_0313") { livetime = 0.147279; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_111216_0736") { livetime = 0.140958; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_111217_1025") { livetime = 1.02077; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111218_1105") { livetime = 1.14876; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111219_1554") { livetime = 0.0225637; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111219_1634") { livetime = 0.00025463; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111219_1739") { livetime = 0.147802; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_111219_2152") { livetime = 0.147657; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_111220_0214") { livetime = 0.149082; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_111220_0634") { livetime = 0.132433; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_111220_1235") { livetime = 0.0450231; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111220_1410") { livetime = 0.870387; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111221_1116") { livetime = 1.25252; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111222_1801") { livetime = 0.642983; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_111223_0948") { livetime = 1.11546; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111224_1316") { livetime = 0.972388; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111225_1315") { livetime = 1.09796; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111226_1622") { livetime = 0.0246273; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_111226_1708") { livetime = 0.138512; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_111226_2117") { livetime = 0.148569; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_111227_0136") { livetime = 0.14859; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_111227_0559") { livetime = 0.125765; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_111227_0948") { livetime = 1.06155; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111228_1149") { livetime = 1.20479; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111229_1812") { livetime = 0.138567; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_111229_2231") { livetime = 0.13972; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_111230_0256") { livetime = 0.139984; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_111230_0723") { livetime = 0.0920579; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_111230_1059") { livetime = 1.03439; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_111231_1158") { livetime = 1.04355; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120101_1327") { livetime = 1.06686; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120102_1607") { livetime = 0.0203588; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120102_1659") { livetime = 0.152032; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120102_2113") { livetime = 0.152594; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120103_0133") { livetime = 0.153084; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120103_0556") { livetime = 0.153097; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120103_1140") { livetime = 1.02373; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120104_1226") { livetime = 0.961993; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120105_1540") { livetime = 0.163716; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120105_2015") { livetime = 0.126439; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120106_0055") { livetime = 0.166153; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120106_0527") { livetime = 0.165579; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120106_1124") { livetime = 0.971701; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120107_1113") { livetime = 0.991391; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120108_1111") { livetime = 1.04276; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120109_1300") { livetime = 0.0222465; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120109_1338") { livetime = 0.149794; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120109_1753") { livetime = 0.090713; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120109_2031") { livetime = 0.0221991; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120109_2206") { livetime = 0.523707; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120110_1704") { livetime = 0.0220891; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120110_1738") { livetime = 0.0223113; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120110_1813") { livetime = 0.0220903; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120110_1849") { livetime = 0.0221343; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120110_1925") { livetime = 0.0222176; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120110_2000") { livetime = 0.0220417; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120110_2035") { livetime = 0.0221644; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120110_2208") { livetime = 0.864719; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120111_1920") { livetime = 0.578296; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120112_1622") { livetime = 0.144839; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120112_2032") { livetime = 0.145134; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120113_0053") { livetime = 0.145841; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120113_0511") { livetime = 0.146942; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120113_0929") { livetime = 0.150234; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120113_1356") { livetime = 0.0619387; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120116_1105") { livetime = 0.0223866; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120116_1151") { livetime = 0.153157; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120116_1605") { livetime = 0.153072; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120116_2024") { livetime = 0.15334; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120117_0042") { livetime = 0.153095; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120117_0901") { livetime = 0.105913; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120117_1229") { livetime = 0.908404; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120118_1254") { livetime = 0.968475; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120119_1540") { livetime = 0.135984; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120119_1952") { livetime = 0.142591; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120120_0009") { livetime = 0.142947; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120120_0431") { livetime = 0.143748; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120120_1105") { livetime = 0.967075; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120121_1140") { livetime = 1.01522; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120122_1226") { livetime = 1.04722; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120123_1417") { livetime = 0.0221019; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120123_1456") { livetime = 0.15577; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120123_1914") { livetime = 0.155524; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120123_2332") { livetime = 0.155802; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120124_0354") { livetime = 0.144872; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120124_1025") { livetime = 1.18475; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120125_1654") { livetime = 0.169207; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120125_2132") { livetime = 0.169771; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120126_0219") { livetime = 0.169862; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120126_0701") { livetime = 0.153811; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120126_1229") { livetime = 1.08032; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120127_1419") { livetime = 0.990007; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120129_1458") { livetime = 0.0219016; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120129_1820") { livetime = 0.0160752; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120129_2125") { livetime = 0.019066; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120130_0002") { livetime = 0.00768981; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120130_0238") { livetime = 0.0203009; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120130_0540") { livetime = 0.0204884; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120130_0842") { livetime = 0.0203044; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120130_1144") { livetime = 0.0209618; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120130_1447") { livetime = 0.0204086; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120130_1711") { livetime = 0.0204363; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120130_2013") { livetime = 0.0205278; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120130_2315") { livetime = 0.0206192; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120131_0218") { livetime = 0.020691; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120131_0520") { livetime = 0.0207176; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120131_0823") { livetime = 0.0205822; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120131_1258") { livetime = 0.0210336; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120201_1333") { livetime = 0.0212072; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120202_1209") { livetime = 0.0213194; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120205_1751") { livetime = 0.0218877; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120206_1707") { livetime = 0.0219884; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120206_1836") { livetime = 0.25137; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120207_0036") { livetime = 0.251373; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120207_0636") { livetime = 0.251377; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120207_1236") { livetime = 0.245441; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120207_1830") { livetime = 0.0223426; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120207_1946") { livetime = 0.251378; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120208_0146") { livetime = 0.240483; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120208_0746") { livetime = 0.251376; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120208_1346") { livetime = 0.193538; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120208_1825") { livetime = 0.0224491; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120208_1923") { livetime = 0.251376; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120209_0123") { livetime = 0.250682; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120209_0723") { livetime = 0.251384; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120209_1323") { livetime = 0.241689; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120209_1911") { livetime = 0.0222315; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120209_2006") { livetime = 0.81; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120210_1559") { livetime = 0.251392; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120210_2159") { livetime = 0.25065; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120211_0359") { livetime = 0.251394; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120211_1000") { livetime = 0.251396; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120211_1600") { livetime = 0.240495; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120211_2200") { livetime = 0.251385; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120212_0401") { livetime = 0.251395; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120212_1001") { livetime = 0.251395; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120212_1728") { livetime = 0.240514; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120212_2328") { livetime = 0.251396; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120213_0528") { livetime = 0.251392; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120213_1128") { livetime = 0.0548345; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120213_1249") { livetime = 0.022265; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120213_1350") { livetime = 0.292176; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120213_2050") { livetime = 0.148828; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120214_0057") { livetime = 0.149269; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120214_0510") { livetime = 0.150184; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120214_0928") { livetime = 0.150792; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120214_1523") { livetime = 1.04903; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120215_1813") { livetime = 1.02137; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120216_1838") { livetime = 0.0221123; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120216_1917") { livetime = 0.139473; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120216_2331") { livetime = 0.14086; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120217_0349") { livetime = 0.141809; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120217_0811") { livetime = 0.141902; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120217_1340") { livetime = 1.01961; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120218_1401") { livetime = 1.17314; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120219_1803") { livetime = 0.969895; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120220_1730") { livetime = 0.0139294; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120220_1912") { livetime = 0.151381; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120220_2327") { livetime = 0.152987; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120221_0348") { livetime = 0.153189; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120221_0806") { livetime = 0.152221; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120221_1457") { livetime = 1.02182; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120222_1537") { livetime = 0.990764; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120223_1806") { livetime = 0.173192; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120223_2247") { livetime = 0.173169; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120224_0326") { livetime = 0.17355; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120224_0805") { livetime = 0.173829; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120224_1656") { livetime = 1.14803; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120225_2036") { livetime = 0.978781; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120226_2023") { livetime = 0.779627; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120227_1547") { livetime = 0.0226065; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120227_1647") { livetime = 0.160641; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120227_2113") { livetime = 0.158875; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120228_0136") { livetime = 0.156348; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120228_0556") { livetime = 0.155713; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120228_1440") { livetime = 1.06331; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120229_1724") { livetime = 1.01317; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120301_1823") { livetime = 0.154059; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120301_2240") { livetime = 0.15492; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120302_0305") { livetime = 0.154807; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120302_0730") { livetime = 0.15972; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120302_1307") { livetime = 0.824808; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120303_0906") { livetime = 1.18942; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120304_1347") { livetime = 1.09112; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120305_1651") { livetime = 0.022515; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120305_1818") { livetime = 0.15653; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120305_2237") { livetime = 0.157; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120306_0254") { livetime = 0.157367; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120306_0716") { livetime = 0.128951; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120306_1313") { livetime = 0.113912; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120306_1618") { livetime = 0.993819; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120307_1604") { livetime = 0.170124; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120307_2105") { livetime = 0.92388; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120308_1924") { livetime = 0.966769; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120312_1851") { livetime = 0.0228391; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120312_1953") { livetime = 0.162308; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120313_0020") { livetime = 0.162538; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120313_0452") { livetime = 0.163053; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120313_0921") { livetime = 0.00859838; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120313_1115") { livetime = 1.13096; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120314_1423") { livetime = 0.874671; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120315_1132") { livetime = 0.315406; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120315_1919") { livetime = 0.151317; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120315_2340") { livetime = 0.151397; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120316_0357") { livetime = 0.151962; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120316_0818") { livetime = 0.0279641; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120316_0913") { livetime = 0.0457396; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120316_1127") { livetime = 1.02727; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120317_1159") { livetime = 0.222023; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120317_1803") { livetime = 0.794722; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120318_1315") { livetime = 1.10446; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120319_1654") { livetime = 0.0230625; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120319_1742") { livetime = 0.165404; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120319_2204") { livetime = 0.164863; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120320_0226") { livetime = 0.162032; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120320_0654") { livetime = 0.130287; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120320_1122") { livetime = 0.992571; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120321_1108") { livetime = 1.05005; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120322_1230") { livetime = 0.243403; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120322_1852") { livetime = 0.176431; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120322_2335") { livetime = 0.177005; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120323_0425") { livetime = 0.17866; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120323_0932") { livetime = 0.983593; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120324_0903") { livetime = 0.940602; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120325_0846") { livetime = 1.04012; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120326_0952") { livetime = 0.242863; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120326_1615") { livetime = 0.0226458; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120326_1710") { livetime = 0.156295; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120326_2133") { livetime = 0.155836; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120327_0159") { livetime = 0.15662; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120327_0625") { livetime = 0.108267; isotope = "Th232"; return livetime;}
	 if(dataset_name == "xe100_120327_0944") { livetime = 0.977023; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120329_1936") { livetime = 0.150198; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120330_0004") { livetime = 0.148284; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120330_0438") { livetime = 0.149369; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120330_0908") { livetime = 0.0165532; isotope = "Co60"; return livetime;}
	 if(dataset_name == "xe100_120330_1051") { livetime = 1.06737; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120331_1627") { livetime = 0.704215; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120401_0935") { livetime = 0.429581; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120401_2014") { livetime = 0.0457431; isotope = "Cs137"; return livetime;}
	 if(dataset_name == "xe100_120401_2201") { livetime = 0.458372; isotope = "DM"; return livetime;}
	 if(dataset_name == "xe100_120402_1116") { livetime = 0.112988; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_120402_1415") { livetime = 0.13363; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_120402_1727") { livetime = 0.10456; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_120402_2000") { livetime = 0.107248; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_120402_2233") { livetime = 0.107047; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_120403_0107") { livetime = 0.107112; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_120403_0340") { livetime = 0.107922; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_120403_0615") { livetime = 0.107677; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_120403_0850") { livetime = 0.108413; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_120403_1125") { livetime = 0.107892; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_120403_1400") { livetime = 0.107815; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_120403_1634") { livetime = 0.108278; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_120403_1910") { livetime = 0.108039; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_120403_2145") { livetime = 0.108181; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_120404_0020") { livetime = 0.107976; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_120404_0255") { livetime = 0.10792; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_120404_0529") { livetime = 0.107741; isotope = "AmBe"; return livetime;}
	 if(dataset_name == "xe100_120404_0804") { livetime = 0.00976736; isotope = "AmBe"; return livetime;}

	 cout << "XenonDataReader::DatasetLivetime()  --- WARNING: dataset_name not found!  return 0. " << endl;
	return livetime;

	}
