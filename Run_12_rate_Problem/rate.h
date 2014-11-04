#include "XenonDataReader.h"
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <vector>
#include <iostream>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
using namespace std;


#ifndef rate_h
#define rate_h
class rate: public XenonDataReader 
	{

	public:
	rate(TTree *T2=0, TTree *T3=0, TTree *T1=0); 
	bool 	run_12_bruno();
 	void 	Loop();	

	};


#endif
