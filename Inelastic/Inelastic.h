#include "XenonDataReader.h"
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <vector>
#include <iostream>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <cmath>
using namespace std;


#ifndef Inelastic_h
#define Inelastic_h
class Inelastic: public XenonDataReader 
	{

	public:
	Inelastic(TTree *T2=0, TTree *T3=0, TTree *T1=0); 
	void Loop();

	};


#endif
