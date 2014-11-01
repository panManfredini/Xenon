#include "XenonDataReader.h"
#include "TFile.h"
#include "TChain.h"

int main(){

	TFile *f = new TFile("/mnt/Lustre/xenon/manfredi/run_12_repro/xe100_131015_0354.root");
	TTree *t1 = (TTree*)f->Get("T1");
	TTree *t2 = (TTree*)f->Get("T2");
	TTree *t3 = (TTree*)f->Get("T3");

	XenonDataReader x(t2, t3, t1);
	x.setFilename("xe100_131015_0354.root");
	x.setOutDir("HISTO/");
	x.Loop();
	return 0;
}
