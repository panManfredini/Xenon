//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sun Oct 12 13:42:45 2014 by ROOT version 5.32/00
// from TTree T2/Level2 Quantities
// found on file: /mnt/Lustre/xenon/manfredi/run_12_repro/xe100_131015_0354.root
//////////////////////////////////////////////////////////

#ifndef XenonDataReader_h
#define XenonDataReader_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include "XenonDataReaderT3.h"
#include "XenonDataReaderT1.h"
#include <iostream>
// Header file for the classes stored in the TTree if any.
#include <vector>
#include <TMath.h>
#include <TString.h>

// Fixed size dimensions of array or collections stored in the TTree if any.
using namespace std;
using namespace TMath;



class XenonDataReader {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Char_t          PmtCalibrationFiles;
   Float_t         AreaTot;
   Float_t         AreaTotVeto;
   vector<float>   *Area;
   Float_t         AbsAreaTot;
   vector<float>   *AbsArea;
   Float_t         S1Tot;
   Float_t         S1TotTop;
   Float_t         S1TotBottom;
   vector<vector<float> > *S1s;
   vector<float>   *S1sTot;
   vector<float>   *S1sTotTop;
   vector<float>   *S1sTotBottom;
   vector<float>   *S1sTotOutside;
   Float_t         S2Tot;
   Float_t         S2TotTop;
   Float_t         S2TotBottom;
   Float_t         S2TotAfter;
   vector<vector<float> > *S2s;
   vector<float>   *S2sTot;
   vector<float>   *S2sTotTop;
   vector<float>   *S2sTotBottom;
   Float_t         S1TotVeto;
   vector<vector<float> > *S1sVeto;
   vector<float>   *S1sTotVeto;
   vector<int>     *S1sCoin;
   vector<int>     *S1sCoinTop;
   vector<int>     *S1sCoinBottom;
   vector<int>     *S2sCoin;
   vector<int>     *S2sCoinTop;
   vector<int>     *S2sCoinBottom;
   vector<int>     *S1sCoinVeto;
   vector<vector<int> > *S1sPmtCoin;
   vector<vector<int> > *S1sPmtOrder;
   vector<vector<int> > *S2sPmtOrder;
   vector<vector<float> > *S2sPosMaxPmt;
   vector<vector<float> > *S2sPosSvm;
   vector<vector<float> > *S2sPosNn;
   vector<vector<float> > *S2sPosChi2;
   vector<vector<float> > *S2sTopClustersE;
   vector<vector<float> > *S2sTopClustersX;
   vector<vector<float> > *S2sTopClustersY;
   vector<vector<vector<int> > > *S2sTopClustersHits;

   // List of branches
   TBranch        *b_PmtCalibrationFiles;   //!
   TBranch        *b_AreaTot;   //!
   TBranch        *b_AreaTotVeto;   //!
   TBranch        *b_Area;   //!
   TBranch        *b_AbsAreaTot;   //!
   TBranch        *b_AbsArea;   //!
   TBranch        *b_S1Tot;   //!
   TBranch        *b_S1TotTop;   //!
   TBranch        *b_S1TotBottom;   //!
   TBranch        *b_S1s;   //!
   TBranch        *b_S1sTot;   //!
   TBranch        *b_S1sTotTop;   //!
   TBranch        *b_S1sTotBottom;   //!
   TBranch        *b_S1sTotOutside;   //!
   TBranch        *b_S2Tot;   //!
   TBranch        *b_S2TotTop;   //!
   TBranch        *b_S2TotBottom;   //!
   TBranch        *b_S2TotAfter;   //!
   TBranch        *b_S2s;   //!
   TBranch        *b_S2sTot;   //!
   TBranch        *b_S2sTotTop;   //!
   TBranch        *b_S2sTotBottom;   //!
   TBranch        *b_S1TotVeto;   //!
   TBranch        *b_S1sVeto;   //!
   TBranch        *b_S1sTotVeto;   //!
   TBranch        *b_S1sCoin;   //!
   TBranch        *b_S1sCoinTop;   //!
   TBranch        *b_S1sCoinBottom;   //!
   TBranch        *b_S2sCoin;   //!
   TBranch        *b_S2sCoinTop;   //!
   TBranch        *b_S2sCoinBottom;   //!
   TBranch        *b_S1sCoinVeto;   //!
   TBranch        *b_S1sPmtCoin;   //!
   TBranch        *b_S1sPmtOrder;   //!
   TBranch        *b_S2sPmtOrder;   //!
   TBranch        *b_S2sPosMaxPmt;   //!
   TBranch        *b_S2sPosSvm;   //!
   TBranch        *b_S2sPosNn;   //!
   TBranch        *b_S2sPosChi2;   //!
   TBranch        *b_S2sTopClustersE;   //!
   TBranch        *b_S2sTopClustersX;   //!
   TBranch        *b_S2sTopClustersY;   //!
   TBranch        *b_S2sTopClustersHits;   //!

   XenonDataReader(TTree *tree=0, TTree *tree3=0, TTree *tree1=0);
   virtual ~XenonDataReader();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);

   //------------- From here modified Ale -------------//
   XenonDataReaderT3 XeT3;
   XenonDataReaderT1 XeT1;
 //===========================================================//
 //-------------- ANALISYS VARIABLES AND CUTS ----------------//
 //===========================================================//
   //--- System Methods   ---//
   void 	    Initialize();  // initialize a
   void 	    fillBranches(Long64_t ientry);
   TString	    filename;  // name of the file you are opening ... can be usefull
   TString	    outDir;  // name of the directory for outputs
   void		    setFilename(TString name);
   void		    setOutDir(TString name);
   
   //--- Analysis cuts 
   bool  	    Xsignalnoise5();
   bool  	    Xsignalnoise3();
   bool  	    Xsignalnoise4();
   bool 	    Xs1width0() ;
   bool		    Xs1coin2();
   bool 	    Xentropy1(); 
   bool 	    Xentropy0(); 
   bool 	    Xs2peaks2(); 
   bool 	    Xhighlog1();
   bool		    Xs2single3();
   bool		    Xs1single5();
   bool		    Xveto2();
   bool		    Xs2width11();		
   bool		    XPL013_97();
   bool		    Xposrec1();
   bool 	    Xs2chisquare1();
   bool		    Xlownoise0_m();
   bool		    Xs2peakpos0();	
   bool		    X34kg2();
   bool		    X48kg0();
   bool		    Xs2top0();
   bool		    Xs1single4();
   bool		    Xs2single0();
   bool		    Xs2width0();
   bool		    Xs2chisquare0();
   

   //--- Auxiliary variables (Aliases)
   int   	    ncoin_e_1() ;
   int   	    ncoin_e_0() ;
   int 		    noisypmts10();
   int	 	    ncoin_e_s1(int peak_itr =1);
   float	    sigma_flattened_width_11();	
   float  	    DriftTime(int peak_itr=0);
   float 	    PL013();
   float	    cs2asym();
   double 	    AltC(double nbpeak, int pos, double prim, double sec);
   
   float	    X(int peak_index =0);
   float	    Y(int peak_index =0);
   float	    Z(int peak_index =0);
   float	    R(int peak_index =0);
   
   double 	    DatasetLivetime(const TString dataset_name, TString &isotope) ;
   bool 	    run_12_basic() ;
 //-----------------------------------------------------------//

};

#endif

#ifdef XenonDataReader_cxx
void XenonDataReader::Initialize()
	{
	cout << "Old  Print"<<endl;
	}
//XenonDataReader::XenonDataReader(TTree *tree, TTree *tree3) : fChain(0)
XenonDataReader::XenonDataReader(TTree *tree, TTree *tree3, TTree *tree1) : fChain(0), XeT3(tree3), XeT1(tree1), filename("dummyfilename.root"), outDir("") 
{

//------------- to here Ale modified -----//

// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/mnt/Lustre/xenon/manfredi/run_12_repro/xe100_131015_0354.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/mnt/Lustre/xenon/manfredi/run_12_repro/xe100_131015_0354.root");
      }
      f->GetObject("T2",tree);

   }
   Init(tree);
}

XenonDataReader::~XenonDataReader()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t XenonDataReader::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t XenonDataReader::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}


void XenonDataReader::setFilename(TString name)
	{
	 filename = name;
	}

void XenonDataReader::setOutDir(TString name)
	{
	 outDir = name;
	}
void XenonDataReader::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   Area = 0;
   AbsArea = 0;
   S1s = 0;
   S1sTot = 0;
   S1sTotTop = 0;
   S1sTotBottom = 0;
   S1sTotOutside = 0;
   S2s = 0;
   S2sTot = 0;
   S2sTotTop = 0;
   S2sTotBottom = 0;
   S1sVeto = 0;
   S1sTotVeto = 0;
   S1sCoin = 0;
   S1sCoinTop = 0;
   S1sCoinBottom = 0;
   S2sCoin = 0;
   S2sCoinTop = 0;
   S2sCoinBottom = 0;
   S1sCoinVeto = 0;
   S1sPmtCoin = 0;
   S1sPmtOrder = 0;
   S2sPmtOrder = 0;
   S2sPosMaxPmt = 0;
   S2sPosSvm = 0;
   S2sPosNn = 0;
   S2sPosChi2 = 0;
   S2sTopClustersE = 0;
   S2sTopClustersX = 0;
   S2sTopClustersY = 0;
   S2sTopClustersHits = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("PmtCalibrationFiles", &PmtCalibrationFiles, &b_PmtCalibrationFiles);
   fChain->SetBranchAddress("AreaTot", &AreaTot, &b_AreaTot);
   fChain->SetBranchAddress("AreaTotVeto", &AreaTotVeto, &b_AreaTotVeto);
   fChain->SetBranchAddress("Area", &Area, &b_Area);
   fChain->SetBranchAddress("AbsAreaTot", &AbsAreaTot, &b_AbsAreaTot);
   fChain->SetBranchAddress("AbsArea", &AbsArea, &b_AbsArea);
   fChain->SetBranchAddress("S1Tot", &S1Tot, &b_S1Tot);
   fChain->SetBranchAddress("S1TotTop", &S1TotTop, &b_S1TotTop);
   fChain->SetBranchAddress("S1TotBottom", &S1TotBottom, &b_S1TotBottom);
   fChain->SetBranchAddress("S1s", &S1s, &b_S1s);
   fChain->SetBranchAddress("S1sTot", &S1sTot, &b_S1sTot);
   fChain->SetBranchAddress("S1sTotTop", &S1sTotTop, &b_S1sTotTop);
   fChain->SetBranchAddress("S1sTotBottom", &S1sTotBottom, &b_S1sTotBottom);
   fChain->SetBranchAddress("S1sTotOutside", &S1sTotOutside, &b_S1sTotOutside);
   fChain->SetBranchAddress("S2Tot", &S2Tot, &b_S2Tot);
   fChain->SetBranchAddress("S2TotTop", &S2TotTop, &b_S2TotTop);
   fChain->SetBranchAddress("S2TotBottom", &S2TotBottom, &b_S2TotBottom);
   fChain->SetBranchAddress("S2TotAfter", &S2TotAfter, &b_S2TotAfter);
   fChain->SetBranchAddress("S2s", &S2s, &b_S2s);
   fChain->SetBranchAddress("S2sTot", &S2sTot, &b_S2sTot);
   fChain->SetBranchAddress("S2sTotTop", &S2sTotTop, &b_S2sTotTop);
   fChain->SetBranchAddress("S2sTotBottom", &S2sTotBottom, &b_S2sTotBottom);
   fChain->SetBranchAddress("S1TotVeto", &S1TotVeto, &b_S1TotVeto);
   fChain->SetBranchAddress("S1sVeto", &S1sVeto, &b_S1sVeto);
   fChain->SetBranchAddress("S1sTotVeto", &S1sTotVeto, &b_S1sTotVeto);
   fChain->SetBranchAddress("S1sCoin", &S1sCoin, &b_S1sCoin);
   fChain->SetBranchAddress("S1sCoinTop", &S1sCoinTop, &b_S1sCoinTop);
   fChain->SetBranchAddress("S1sCoinBottom", &S1sCoinBottom, &b_S1sCoinBottom);
   fChain->SetBranchAddress("S2sCoin", &S2sCoin, &b_S2sCoin);
   fChain->SetBranchAddress("S2sCoinTop", &S2sCoinTop, &b_S2sCoinTop);
   fChain->SetBranchAddress("S2sCoinBottom", &S2sCoinBottom, &b_S2sCoinBottom);
   fChain->SetBranchAddress("S1sCoinVeto", &S1sCoinVeto, &b_S1sCoinVeto);
   fChain->SetBranchAddress("S1sPmtCoin", &S1sPmtCoin, &b_S1sPmtCoin);
   fChain->SetBranchAddress("S1sPmtOrder", &S1sPmtOrder, &b_S1sPmtOrder);
   fChain->SetBranchAddress("S2sPmtOrder", &S2sPmtOrder, &b_S2sPmtOrder);
   fChain->SetBranchAddress("S2sPosMaxPmt", &S2sPosMaxPmt, &b_S2sPosMaxPmt);
   fChain->SetBranchAddress("S2sPosSvm", &S2sPosSvm, &b_S2sPosSvm);
   fChain->SetBranchAddress("S2sPosNn", &S2sPosNn, &b_S2sPosNn);
   fChain->SetBranchAddress("S2sPosChi2", &S2sPosChi2, &b_S2sPosChi2);
   fChain->SetBranchAddress("S2sTopClustersE", &S2sTopClustersE, &b_S2sTopClustersE);
   fChain->SetBranchAddress("S2sTopClustersX", &S2sTopClustersX, &b_S2sTopClustersX);
   fChain->SetBranchAddress("S2sTopClustersY", &S2sTopClustersY, &b_S2sTopClustersY);
   fChain->SetBranchAddress("S2sTopClustersHits", &S2sTopClustersHits, &b_S2sTopClustersHits);
   Notify();
}

Bool_t XenonDataReader::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void XenonDataReader::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t XenonDataReader::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef XenonDataReader_cxx
