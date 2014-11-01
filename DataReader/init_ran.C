{

// setting aliases 
	T2->SetAlias("X","cS2sPosNn[0][0]");
	T2->SetAlias("Y","cS2sPosNn[0][1]");
	T2->SetAlias("Z","cS2sPosNn[0][2]");
	T2->SetAlias("R2","pow(X*X+Y*Y,2)");

        T2->SetAlias("CEc","(cS2TotBottom[0]/133.247528+cS1sTot[0])/4.21608");
	T2->SetAlias("dt","(S2sPeak[0]-S1sPeak[0])/100.");
	T2->SetAlias("DriftTime[i]","(S2sPeak[i]-S1sPeak[0])/100.");
	T2->SetAlias("Z[i]","cS2sPosNn[i][2]");
	T2->SetAlias("s1asym","(S1sTotTop[0]-S1sTotBottom[0])/S1sTot[0]");
	T2->SetAlias("s2asym","(S2sTotTop[0]-S2sTotBottom[0])/S2sTot[0]");
	T2->SetAlias("cs2asym","(cS2sTotTop[0]-cS2sTotBottom[0])/cS2sTot[0]");
	T2->SetAlias("noisypmts","((S1s[0][146]>0.35)+(S1s[0][148]>0.35)+(S1s[0][151]>0.35))");
	T2->SetAlias("noisypmts10","((S1s[0][151]>0.35)+(S1s[0][169]>0.35)+(TMath::Nint(0.4*(S1s[0][166]>0.35)+0.4*(S1s[0][168]>0.35))))");
	T2->SetAlias("ncoin_e","Sum$((S1s[0][S1sPmtCoin[0][]]>2)+((S1s[0][S1sPmtCoin[0][]]<=2.&&S1s[0][S1sPmtCoin[0][]]>1)*(S1sEntropy[0][S1sPmtCoin[0][]]<S1s[0][S1sPmtCoin[0][]]+1.5))+((S1s[0][S1sPmtCoin[0][]]<=1.)*(S1sEntropy[0][S1sPmtCoin[0][]]<2.5)))");
	T2->SetAlias("ncoin_e_s1_1","Alt$(Sum$((S1s[1][S1sPmtCoin[1][]]>2)+((S1s[1][S1sPmtCoin[1][]]<=2.&&S1s[1][S1sPmtCoin[1][]]>1)*(S1sEntropy[1][S1sPmtCoin[1][]]<S1s[1][S1sPmtCoin[1][]]+1.5))+((S1s[1][S1sPmtCoin[1][]]<=1.)*(S1sEntropy[1][S1sPmtCoin[1][]]<2.5))),0)");
	T2->SetAlias("ncoin_e_s1_2","Alt$(Sum$((S1s[2][S1sPmtCoin[2][]]>2)+((S1s[2][S1sPmtCoin[2][]]<=2.&&S1s[2][S1sPmtCoin[2][]]>1)*(S1sEntropy[2][S1sPmtCoin[2][]]<S1s[2][S1sPmtCoin[2][]]+1.5))+((S1s[2][S1sPmtCoin[2][]]<=1.)*(S1sEntropy[2][S1sPmtCoin[2][]]<2.5))),0)");
	T2->SetAlias("ncoin_e_s1_3","Alt$(Sum$((S1s[3][S1sPmtCoin[3][]]>2)+((S1s[3][S1sPmtCoin[3][]]<=2.&&S1s[3][S1sPmtCoin[3][]]>1)*(S1sEntropy[3][S1sPmtCoin[3][]]<S1s[3][S1sPmtCoin[3][]]+1.5))+((S1s[3][S1sPmtCoin[3][]]<=1.)*(S1sEntropy[3][S1sPmtCoin[3][]]<2.5))),0)");
	T2->SetAlias("ncoin_e_s1_4","Alt$(Sum$((S1s[4][S1sPmtCoin[4][]]>2)+((S1s[4][S1sPmtCoin[4][]]<=2.&&S1s[4][S1sPmtCoin[4][]]>1)*(S1sEntropy[4][S1sPmtCoin[4][]]<S1s[4][S1sPmtCoin[4][]]+1.5))+((S1s[4][S1sPmtCoin[4][]]<=1.)*(S1sEntropy[4][S1sPmtCoin[4][]]<2.5))),0)");
	T2->SetAlias("PL013","(-2*(S1PatternLikelihood[0]+S1PatternLikelihood[1]+S1PatternLikelihood[3]))");
	T2->SetAlias("mean_width","(TMath::Sqrt((1.18791e+02-4.53908e+00*log(S2sTot[0])+1.93864e-01*sqrt(S2sTot[0])-2.64963e-04*S2sTot[0])^2+(-2.93710e+02+9.43304e+01*log(S2sTot[0])-6.49995e+00*sqrt(S2sTot[0])+3.02096e-02*S2sTot[0])*dt))");
	T2->SetAlias("sigma_width","(4.65009e+01-8.24143e+00*log(S2sTot[0])+5.81395e-01*sqrt(S2sTot[0])-2.96082e-03*S2sTot[0]+(6.92605e-02+2.37447e-02*log(S2sTot[0])-5.77711e-03*sqrt(S2sTot[0])+3.71555e-05*S2sTot[0])*dt)");
        T2->SetAlias("ebandflat","log10(cS2sTotBottom[0]/cS1sTot[0])-(exp(-4.50714e-01-1.67142e-01*cS1sTot[0])+2.06217e+00-3.03635e-03*cS1sTot[0])-(1.49970e-01-7.05452e-02*cS1sTot[0]+ 1.13744e-02*cS1sTot[0]**2-8.64724e-04*cS1sTot[0]**3+3.40181e-05*cS1sTot[0]**4-6.72314e-07*cS1sTot[0]**5+5.29307e-09*cS1sTot[0]**6)");

        T2->SetAlias("ncoin_e_1","Sum$( (S1s[0][S1sPmtCoin[0][]]<0.4806)*(S1sEntropy[0][S1sPmtCoin[0][]]<2.66184) + (0.4806<=S1s[0][S1sPmtCoin[0][]] && S1s[0][S1sPmtCoin[0][]]<=2.08657)*( S1sEntropy[0][S1sPmtCoin[0][]] < (3.52658 - 5.04919*S1s[0][S1sPmtCoin[0][]] + 10.6078*S1s[0][S1sPmtCoin[0][]]**2 - 9.87844*S1s[0][S1sPmtCoin[0][]]**3 + 4.22897*S1s[0][S1sPmtCoin[0][]]**4 - 0.673842*S1s[0][S1sPmtCoin[0][]]**5) ) + (2.08657<S1s[0][S1sPmtCoin[0][]] && S1s[0][S1sPmtCoin[0][]]<15)*(S1sEntropy[0][S1sPmtCoin[0][]]<2.94477) + (S1s[0][S1sPmtCoin[0][]]>=15)*( S1sEntropy[0][S1sPmtCoin[0][]] < ( 7.9527e-01*log10(S1s[0][S1sPmtCoin[0][]]) + 2.0094598 ) ) )");

        T2->SetAlias("sigma_flattened_width_11","(6.77404e+01-1.01215e+01*log(S2sTot[0])+2.97558e-01*sqrt(S2sTot[0])-1.08131e+01*(1./exp(1.29359e-03*S2sTot[0])) + (3.82098e-02 + 9.63804e-02*exp( -5.15204e-04*S2sTot[0]))*dt)*(S2sTot[0]<5000.)+(6.77404e+01-1.01215e+01*log(5000.)+2.97558e-01*sqrt(5000.)-1.08131e+01*(1./exp(1.29359e-03*5000.)) + (3.82098e-02 + 9.63804e-02*exp( -5.15204e-04*5000.))*dt)*(S2sTot[0]>=5000.)");

// defining cuts
	TCut Xsignalnoise5("((log10(S2sTot[0])<2.77 && log10((S1sTot[0]+S2sTot[0])/TMath::Max(AreaTot-S1sTot[0]-S2sTot[0],0.00001))>0.0 && AreaTot>0.0) || (log10(S2sTot[0])>=2.77 && log10((S1sTot[0]+S2sTot[0])/TMath::Max(AreaTot-S1sTot[0]-S2sTot[0],0.00001))>TMath::Min(0.23436*log10(S2sTot[0])^3-2.77487*log10(S2sTot[0])^2+11.2553*log10(S2sTot[0])-14.8667,0.8) && AreaTot>0.0))");
        
	TCut Xs1width0("(S1sLowWidth[0]>2.6)");
	TCut Xentropy0("ncoin_e>1");
	TCut Xstop0("S2sTotTop[0]>0");
        TCut Xs2peaks0("S2sTot[0] > 150");
	TCut Xs1coin2("S1sCoin[0]>(1+noisypmts10)");
	TCut Xs2width0("((S2sWidth[0] < -0.2167*(Z[0]+4)+75))");
	TCut Xhighlog1("log10(cS2sTotBottom[0]/cS1sTot[0])<3.1");
	TCut Xs2single3("(Alt$(S2sTot[1],0)<(70+(S2sTot[0]-300)/100.))");
	TCut Xs1single5("((ncoin_e_s1_1 < 2 || (S2sPeak[0]-Alt$(S1sPeak[1],-18500)) > 18500 || log10(cS2sTot[0]/Alt$(cS1sTot[1],1.e-4)) > 3.2) && (ncoin_e_s1_2 < 2 || (S2sPeak[0]-Alt$(S1sPeak[2],-18500)) > 18500 || log10(cS2sTot[0]/Alt$(cS1sTot[2],1.e-4)) > 3.2) && (ncoin_e_s1_3 < 2 || (S2sPeak[0]-Alt$(S1sPeak[3],-18500)) > 18500 || log10(cS2sTot[0]/Alt$(cS1sTot[3],1.e-4)) > 3.2) && (ncoin_e_s1_4 < 2))");
	TCut Xveto2("S1sTotOutside[0]<0.35");
	TCut Xs2width9("S2sLowWidth[0]>mean_width-2.*sigma_width && S2sLowWidth[0]<mean_width+2.*sigma_width");
	TCut XPL013_97("PL013 < -16.9181 + 27.3756 * pow(S1sTot[0],0.5) + -1.73185 * S1sTot[0] + 0.041431 * pow(S1sTot[0],1.5)");
	TCut Xposrec1("sqrt((pow((S2sPosNn[0][0]-S2sPosSvm[0][0]),2)+pow((S2sPosNn[0][1]-S2sPosSvm[0][1]),2)) + (pow((S2sPosNn[0][0]-S2sPosChi2[0][0]),2)+pow((S2sPosNn[0][1]-S2sPosChi2[0][1]),2)))<7");
	TCut Xs2chisquare0("(S2sPosNn[0][3]/(S2sCoinTop[0]-1))<7");
//	TCut n3sigma = new TCut("(ebandflat_new>((-1.24318+0.0726079*cxS1sTot[0]-0.00268342*cxS1sTot[0]**2+3.51746e-05*cxS1sTot[0]**3)*(cxS1sTot[0]<30)+(-0.530307-0.00380772*(cxS1sTot[0]-30)+6.02839e-06*(cxS1sTot[0]-30)**2+4.08147e-08*(cxS1sTot[0]-30)**3)*(cxS1sTot[0]>=30)))");
	TCut Xs2peakpos0("(S2sPeak[0]/100) > 178");
	TCut X34kg2("(TMath::Power(TMath::Abs(-Z-152.)/126.8,2.7)+TMath::Power((X*X+Y*Y)/17500.,2.7)<1)");
	TCut Xlownoise0_m("cs2asym<0.25 && cs2asym>-0.2");
	TCut X40keV_1("(log10(cS2sTotBottom[0]/cS1sTot[0]))> (1.9*exp((11-CEc)/14)+1.3) && (log10(cS2sTotBottom[0]/cS1sTot[0]))<(5*exp(-CEc/32)+1.25) && (log10(cS2sTotBottom[0]/cS1sTot[0]))< 2.5 && CEc<67");
	TCut X48kg0("(pow(TMath::Abs((-Z-150)/146.),4)+pow(TMath::Abs((X*X+Y*Y)/20000.),4))<1");

	TCut Xentropy1("ncoin_e_1>1");
	TCut Xs2peaks2("S2sTot[0] > 150.");
	TCut Xs2width11("(cfS2sLowWidth[0]>-2.*sigma_flattened_width_11 && cfS2sLowWidth[0]<2.*sigma_flattened_width_11)");
	TCut Xs2chisquare1("((S2sPosNn[0][3]/(S2sCoinTop[0]-1))<6)");

	TCut BasicCut = Xsignalnoise5 + Xs1width0 + Xentropy0 +Xstop0+Xs2peaks0+Xs1coin2+Xhighlog1+Xs2single3+Xs1single5+Xveto2+Xs2width9+XPL013_97+Xposrec1+Xs2chisquare0+Xs2peakpos0+X34kg2;//+X40keV_1;
	TCut allCutNoLowNoise = BasicCut+Xlownoise0_m;	


// define rejection line
// //99.5% rejection line
	TF1 *er995_flat = new TF1("er995_flat","pol4(0)",2.5, 35);
	er995_flat->SetParameter(0,-3.94311e-01);
	er995_flat->SetParameter(1,3.82660e-03);
	er995_flat->SetParameter(2,1.32231e-04);
	er995_flat->SetParameter(3,-1.81839e-05);
	er995_flat->SetParameter(4,3.47962e-07);
// // 
// // //99.75% rejection line
	TF1 *er9975_flat = new TF1("er9975_flat","pol4(0)",2.5,35);
	er9975_flat->SetParameter(0,-4.29397e-01);
	er9975_flat->SetParameter(1,4.31026e-03);
	er9975_flat->SetParameter(2,1.26412e-04);
	er9975_flat->SetParameter(3,-1.90695e-05);
	er9975_flat->SetParameter(4,3.69433e-07);
//       //  
//       //  //99.9% rejection line
	TF1 *er999_flat = new TF1("er999_flat","pol4(0)",2.5, 35);
	er999_flat->SetParameter(0,-4.73071e-01);
	er999_flat->SetParameter(1,4.77851e-03);
	er999_flat->SetParameter(2,1.35668e-04);
	er999_flat->SetParameter(3,-2.07563e-05);
	er999_flat->SetParameter(4,4.02179e-07);
//

}
