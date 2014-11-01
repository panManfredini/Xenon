#include "XenonDataReader.h"
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <vector>
#include <iostream>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
using namespace std;


#ifndef std_h
#define std_h

class std_class: public XenonDataReader 
	{

	public:
	std_class(TTree *T1=0, TTree *T3=0); 
	void Initialize();
	void Loop();

	};
#endif

std_class::std_class(TTree *T1,TTree *T3) : XenonDataReader(T1,T3) 
	{
	}
void std_class::Initialize(){
	cout << "New Print" << endl;
}

void std_class::Loop()

{
   if (fChain == 0) return;

   //INITIALIZE HISTOS
   TH1F *test = new TH1F("test","",1000,0.0,2500.);
   TH1F *test2 = new TH1F("test2","",1000,0,2500.);

   Initialize();

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      XeT3.GetEntry(jentry);

      // if (Cut(ientry) < 0) continue;

	test->Fill(S1Tot);	
	test2->Fill(XeT3.cS2Tot);	
   }


	test->Draw();
	//test2->Draw();

}
