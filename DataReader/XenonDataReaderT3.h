//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sun Oct 12 13:42:45 2014 by ROOT version 5.32/00
// from TTree T3/Level3 Quantities
// found on file: /mnt/Lustre/xenon/manfredi/run_12_repro/xe100_131015_0354.root
//////////////////////////////////////////////////////////

#ifndef XenonDataReaderT3_h
#define XenonDataReaderT3_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>

using namespace std;

// Fixed size dimensions of array or collections stored in the TTree if any.

class XenonDataReaderT3 {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   vector<vector<float> > *cS2sPosSvm;
   vector<vector<float> > *cS2sPosNn;
   vector<vector<float> > *cS2sPosChi2;
   Float_t         cS1Tot;
   vector<float>   *cS1sTot;
   Float_t         cxS1Tot;
   vector<float>   *cxS1sTot;
   Float_t         cS2Tot;
   Float_t         cS2TotTop;
   Float_t         cS2TotBottom;
   vector<float>   *cS2sTot;
   vector<float>   *cS2sTotTop;
   vector<float>   *cS2sTotBottom;
   vector<float>   *cS2sLowWidth;
   vector<float>   *cfS2sLowWidth;
   vector<float>   *S1PatternLikelihood;
   vector<vector<float> > *S1sPmtMaxHeight;
   vector<vector<float> > *S1sBeforeMaximum;
   vector<vector<float> > *S1sAfterMaximum;
   vector<vector<float> > *S1sEntropy;

   // List of branches
   TBranch        *b_cS2sPosSvm;   //!
   TBranch        *b_cS2sPosNn;   //!
   TBranch        *b_cS2sPosChi2;   //!
   TBranch        *b_cS1Tot;   //!
   TBranch        *b_cS1sTot;   //!
   TBranch        *b_cxS1Tot;   //!
   TBranch        *b_cxS1sTot;   //!
   TBranch        *b_cS2Tot;   //!
   TBranch        *b_cS2TotTop;   //!
   TBranch        *b_cS2TotBottom;   //!
   TBranch        *b_cS2sTot;   //!
   TBranch        *b_cS2sTotTop;   //!
   TBranch        *b_cS2sTotBottom;   //!
   TBranch        *b_cS2sLowWidth;   //!
   TBranch        *b_cfS2sLowWidth;   //!
   TBranch        *b_S1PatternLikelihood;   //!
   TBranch        *b_S1sPmtMaxHeight;   //!
   TBranch        *b_S1sBeforeMaximum;   //!
   TBranch        *b_S1sAfterMaximum;   //!
   TBranch        *b_S1sEntropy;   //!

   XenonDataReaderT3(TTree *tree=0);
   virtual ~XenonDataReaderT3();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef XenonDataReaderT3_cxx
XenonDataReaderT3::XenonDataReaderT3(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/mnt/Lustre/xenon/manfredi/run_12_repro/xe100_131015_0354.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/mnt/Lustre/xenon/manfredi/run_12_repro/xe100_131015_0354.root");
      }
      f->GetObject("T3",tree);

   }
   Init(tree);
}

XenonDataReaderT3::~XenonDataReaderT3()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t XenonDataReaderT3::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t XenonDataReaderT3::LoadTree(Long64_t entry)
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

void XenonDataReaderT3::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   cS2sPosSvm = 0;
   cS2sPosNn = 0;
   cS2sPosChi2 = 0;
   cS1sTot = 0;
   cxS1sTot = 0;
   cS2sTot = 0;
   cS2sTotTop = 0;
   cS2sTotBottom = 0;
   cS2sLowWidth = 0;
   cfS2sLowWidth = 0;
   S1PatternLikelihood = 0;
   S1sPmtMaxHeight = 0;
   S1sBeforeMaximum = 0;
   S1sAfterMaximum = 0;
   S1sEntropy = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("cS2sPosSvm", &cS2sPosSvm, &b_cS2sPosSvm);
   fChain->SetBranchAddress("cS2sPosNn", &cS2sPosNn, &b_cS2sPosNn);
   fChain->SetBranchAddress("cS2sPosChi2", &cS2sPosChi2, &b_cS2sPosChi2);
   fChain->SetBranchAddress("cS1Tot", &cS1Tot, &b_cS1Tot);
   fChain->SetBranchAddress("cS1sTot", &cS1sTot, &b_cS1sTot);
   fChain->SetBranchAddress("cxS1Tot", &cxS1Tot, &b_cxS1Tot);
   fChain->SetBranchAddress("cxS1sTot", &cxS1sTot, &b_cxS1sTot);
   fChain->SetBranchAddress("cS2Tot", &cS2Tot, &b_cS2Tot);
   fChain->SetBranchAddress("cS2TotTop", &cS2TotTop, &b_cS2TotTop);
   fChain->SetBranchAddress("cS2TotBottom", &cS2TotBottom, &b_cS2TotBottom);
   fChain->SetBranchAddress("cS2sTot", &cS2sTot, &b_cS2sTot);
   fChain->SetBranchAddress("cS2sTotTop", &cS2sTotTop, &b_cS2sTotTop);
   fChain->SetBranchAddress("cS2sTotBottom", &cS2sTotBottom, &b_cS2sTotBottom);
   fChain->SetBranchAddress("cS2sLowWidth", &cS2sLowWidth, &b_cS2sLowWidth);
   fChain->SetBranchAddress("cfS2sLowWidth", &cfS2sLowWidth, &b_cfS2sLowWidth);
   fChain->SetBranchAddress("S1PatternLikelihood", &S1PatternLikelihood, &b_S1PatternLikelihood);
   fChain->SetBranchAddress("S1sPmtMaxHeight", &S1sPmtMaxHeight, &b_S1sPmtMaxHeight);
   fChain->SetBranchAddress("S1sBeforeMaximum", &S1sBeforeMaximum, &b_S1sBeforeMaximum);
   fChain->SetBranchAddress("S1sAfterMaximum", &S1sAfterMaximum, &b_S1sAfterMaximum);
   fChain->SetBranchAddress("S1sEntropy", &S1sEntropy, &b_S1sEntropy);
   Notify();
}

Bool_t XenonDataReaderT3::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void XenonDataReaderT3::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t XenonDataReaderT3::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef XenonDataReaderT3_cxx
