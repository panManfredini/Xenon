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


#ifndef AmBeTest_h
#define AmBeTest_h
class AmBeTest: public XenonDataReader 
	{

	public:
	AmBeTest(TTree *T2=0, TTree *T3=0, TTree *T1=0); 
	void Loop();

	};


#endif
