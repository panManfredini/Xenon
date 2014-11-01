{


TFile *f = TFile::Open("/mnt/Lustre/xenon/manfredi/run_12_repro/xe100_131015_0354.root");


T2->AddFriend("T1",f);
T2->AddFriend("T3",f);

gROOT->ProcessLine(".x init_ran.C"); 

TH1F *h = new TH1F("h","",1,0,1);

T2->Draw("NbS2Peaks>>h",Xsignalnoise5 && Xs1width0 && Xentropy1 && Xs2peaks2 && Xs1coin2 && Xhighlog1 && Xs2single3 );
cout << h->GetEntries() << endl;
h = new  TH1F("h","",1,0,1);
T2->Draw("NbS2Peaks>>h",Xsignalnoise5 && Xs1width0 && Xentropy1 && Xs2peaks2 && Xs1coin2 && Xhighlog1 && Xs2single3  && Xs1single5 &&
	Xveto2 && Xs2width11 && XPL013_97 && Xposrec1 && Xs2chisquare1 && Xlownoise0_m && Xs2peakpos0 && X34kg2);
cout << h->GetEntries() << endl;
/*cout << "TOTAL" << endl;
T2->Draw("NbS2Peaks>>h" );
cout << h->GetEntries() << endl;
h = new  TH1F("h","",1,0,1);

cout << "Xsignalnoise5" << endl;
T2->Draw("NbS2Peaks>>h",   "S1s[0][0] >=0 && S2s[0][0]>=0" && Xsignalnoise5);
cout << h->GetEntries() << endl;

cout << "Xs1width0" << endl;
T2->Draw("NbS2Peaks>>h",  "S1s[0][0] >=0 && S2s[0][0]>=0" &&  Xs1width0);
cout << h->GetEntries() << endl;
h = new  TH1F("h","",1,0,1);

cout << "Xentropy0" << endl;
T2->Draw("NbS2Peaks>>h",   "S1s[0][0] >=0 && S2s[0][0]>=0" && Xentropy0);
cout << h->GetEntries() << endl;
h = new  TH1F("h","",1,0,1);

cout << "Xstop0" << endl;
T2->Draw("NbS2Peaks>>h",  "S1s[0][0] >=0 && S2s[0][0]>=0" &&  Xstop0);
cout << h->GetEntries() << endl;
h = new  TH1F("h","",1,0,1);

cout << "Xs2peaks0" << endl;
T2->Draw("NbS2Peaks>>h",   "S1s[0][0] >=0 && S2s[0][0]>=0" && Xs2peaks0);
cout << h->GetEntries() << endl;
h = new  TH1F("h","",1,0,1);

cout << "Xs1coin2" << endl;
T2->Draw("NbS2Peaks>>h",  "S1s[0][0] >=0 && S2s[0][0]>=0" &&  Xs1coin2);
cout << h->GetEntries() << endl;
h = new  TH1F("h","",1,0,1);

cout << "Xs2width0" << endl;
T2->Draw("NbS2Peaks>>h",   "S1s[0][0] >=0 && S2s[0][0]>=0" && Xs2width0);
cout << h->GetEntries() << endl;
h = new  TH1F("h","",1,0,1);

cout << "Xhighlog1" << endl;
T2->Draw("NbS2Peaks>>h",  "S1s[0][0] >=0 && S2s[0][0]>=0" &&  Xhighlog1);
cout << h->GetEntries() << endl;
h = new  TH1F("h","",1,0,1);

cout << "Xs2single3" << endl;
T2->Draw("NbS2Peaks>>h",  "S1s[0][0] >=0 && S2s[0][0]>=0" &&  Xs2single3);
cout << h->GetEntries() << endl;
h = new  TH1F("h","",1,0,1);

cout << "Xs1single5" << endl;
T2->Draw("NbS2Peaks>>h",  "S1s[0][0] >=0 && S2s[0][0]>=0" &&  Xs1single5);
cout << h->GetEntries() << endl;
h = new  TH1F("h","",1,0,1);

cout << "Xveto2" << endl;
T2->Draw("NbS2Peaks>>h",  "S1s[0][0] >=0 && S2s[0][0]>=0" &&  Xveto2);
cout << h->GetEntries() << endl;
h = new  TH1F("h","",1,0,1);

cout << "Xs2width9" << endl;
T2->Draw("NbS2Peaks>>h",  "S1s[0][0] >=0 && S2s[0][0]>=0" &&  Xs2width9);
cout << h->GetEntries() << endl;
h = new  TH1F("h","",1,0,1);

cout << "XPL013_97" << endl;
T2->Draw("NbS2Peaks>>h",  "S1s[0][0] >=0 && S2s[0][0]>=0" &&  XPL013_97);
cout << h->GetEntries() << endl;
h = new  TH1F("h","",1,0,1);

cout << "Xposrec1" << endl;
T2->Draw("NbS2Peaks>>h",   "S1s[0][0] >=0 && S2s[0][0]>=0" && Xposrec1);
cout << h->GetEntries() << endl;
h = new  TH1F("h","",1,0,1);

cout << "Xs2chisquare0" << endl;
T2->Draw("NbS2Peaks>>h",  "S1s[0][0] >=0 && S2s[0][0]>=0" &&  Xs2chisquare0);
cout << h->GetEntries() << endl;
h = new  TH1F("h","",1,0,1);

cout << "Xs2peakpos0" << endl;
T2->Draw("NbS2Peaks>>h",  "S1s[0][0] >=0 && S2s[0][0]>=0" &&  Xs2peakpos0);
cout << h->GetEntries() << endl;
h = new  TH1F("h","",1,0,1);

cout << "X34kg2" << endl;
T2->Draw("NbS2Peaks>>h",  "S1s[0][0] >=0 && S2s[0][0]>=0" &&  X34kg2);
cout << h->GetEntries() << endl;
h = new  TH1F("h","",1,0,1);

cout << "Xlownoise0_m" << endl;
T2->Draw("NbS2Peaks>>h",  "S1s[0][0] >=0 && S2s[0][0]>=0" &&  Xlownoise0_m);
cout << h->GetEntries() << endl;
h = new  TH1F("h","",1,0,1);

cout << "X40keV_1" << endl;
T2->Draw("NbS2Peaks>>h",  "S1s[0][0] >=0 && S2s[0][0]>=0" &&  X40keV_1);
cout << h->GetEntries() << endl;
h = new  TH1F("h","",1,0,1);

cout << "X48kg0" << endl;
T2->Draw("NbS2Peaks>>h",  "S1s[0][0] >=0 && S2s[0][0]>=0" &&  X48kg0);
cout << h->GetEntries() << endl;
h = new  TH1F("h","",1,0,1);


cout << "ncoin_e_s1_1" << endl;
T2->Draw("NbS2Peaks>>h", "S1s[0][0] >=0 && S2s[0][0]>=0 && ncoin_e_s1_1 < 2");
cout << h->GetEntries() << endl;
h = new  TH1F("h","",1,0,1);

cout << "ncoin_e_s1_2" << endl;
T2->Draw("NbS2Peaks>>h", "S1s[0][0] >=0 && S2s[0][0]>=0 && ncoin_e_s1_2 < 2");
cout << h->GetEntries() << endl;
h = new  TH1F("h","",1,0,1);

cout << "ncoin_e_s1_3" << endl;
T2->Draw("NbS2Peaks>>h", "S1s[0][0] >=0 && S2s[0][0]>=0 && ncoin_e_s1_3 < 2");
cout << h->GetEntries() << endl;
h = new  TH1F("h","",1,0,1);

cout << "ncoin_e_s1_4" << endl;
T2->Draw("NbS2Peaks>>h", "S1s[0][0] >=0 && S2s[0][0]>=0 && ncoin_e_s1_4 < 2");
cout << h->GetEntries() << endl;

cout << "Xentropy1" << endl;
T2->Draw("NbS2Peaks>>h", "S1s[0][0] >=0 && S2s[0][0]>=0 && ncoin_e_1>1");
cout << h->GetEntries() << endl;


cout << "Xs2peaks2" << endl;
T2->Draw("NbS2Peaks>>h",  "S1s[0][0] >=0 && S2s[0][0]>=0" &&  Xs2peaks2);
cout << h->GetEntries() << endl;

cout << "Xs2width11" << endl;
T2->Draw("NbS2Peaks>>h", "S1s[0][0] >=0 && S2s[0][0]>=0" && Xs2width11);
cout << h->GetEntries() << endl;
cout << "Xs2chisquare1" << endl;
*/

/*TH1F *h1 = new TH1F("h1", "", 500,-500,500);
T2->Draw("S2sCoinTop[0]>>h1", "S2sCoinTop[0]==1" && Xsignalnoise5 && Xs1width0 && Xentropy1 && Xs2peaks2 && Xs1coin2 && Xhighlog1 && Xs2single3 && Xs1single5 && Xveto2 && Xs2width11 && XPL013_97 && Xposrec1 && Xs2chisquare1 && Xlownoise0_m && Xs2peakpos0 && X34kg2 );
cout << h1->GetEntries() << endl;
*/
}
