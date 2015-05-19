#include "XenonDataReader.h"
#include "AmBeTest.h"
#include "TFile.h"
#include "TChain.h"
#include "TString.h"

using namespace std;

int main( int argc, char* argv[] ){

	if(argc != 3) 
	{
	  cout << "ERROR::XenonDataReader::main()  too many or too less arguments, quit..." << endl;
	  cout << "USAGE: ./run_AmBeTest DIRNAME FILENAME" << endl;
	  return 0;
	}

	TString dir_name(argv[1]);
	TString file_name(argv[2]);

	cout << "Running on Sample ---> " << dir_name+file_name << endl;

	TFile *f = new TFile(dir_name+file_name);

	TTree *t1 = (TTree*)f->Get("T1");
	TTree *t2 = (TTree*)f->Get("T2");
	TTree *t3 = (TTree*)f->Get("T3");

	AmBeTest x(t2, t3, t1);
	x.setFilename(file_name);
	x.setOutDir("HISTO/");
	x.Loop();

	return 0;

}
