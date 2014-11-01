void skeleton_maker(TString name_of_file ="none") 
	{
	if(name_of_file == "none") return;
	TFile *f = new TFile(name_of_file);
	TTree *t1 = (TTree*)f->Get("T1");
	TTree *t2 = (TTree*)f->Get("T2");
	TTree *t3 = (TTree*)f->Get("T3");
	
	t1->MakeClass("XenonDataReaderT1");	
	t2->MakeClass("XenonDataReader");	
	t3->MakeClass("XenonDataReaderT3");	
	}
