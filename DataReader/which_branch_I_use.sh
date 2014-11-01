INPUTFILE="XenonDataReader.C"
list_of_branchesT2=(PmtCalibrationFiles AreaTot AreaTotVeto Area AbsAreaTot AbsArea S1Tot S1TotTop S1TotBottom S1s S1sTot PmtCalibrationFiles AreaTot AreaTotVeto Area AbsAreaTot AbsArea S1Tot S1TotTop S1TotBottom S1s S1sTot S1sTotTop S1sTotBottom S1sTotOutside S2Tot S2TotTop S2TotBottom S2TotAfter S2s S2sTot S2sTotTop S2sTotBottom S1TotVeto S1sVeto S1sTotVeto S1sCoin S1sCoinTop S1sCoinBottom S2sCoin S2sCoinTop S2sCoinBottom S1sCoinVeto S1sPmtCoin S1sPmtOrder S2sPmtOrder S2sPosMaxPmt S2sPosSvm S2sPosNn S2sPosChi2 S2sTopClustersE S2sTopClustersX S2sTopClustersY   S2sTopClustersHits)

list_of_branchesT1=(Filename EventId TimeSec TimeMicroSec Channels BaselinesAvg BaselinesMax
   AreaTotRaw
   AreaTotRawVeto
      AreaRaw
   AbsAreaTotRaw
      AbsAreaRaw
   NbNonZeroLast
   NbS1Peaks
        S1sPeak
        S1sLeftEdge
        S1sRightEdge
      S1sWidth
      S1sLowWidth
      S1sFilteredLowWidth
      S1sHeight
      S1sMinimum
      S1sMeanTime
      S1sTimeSpread
        S1sSaturation
        S1Order
        S1SizeOrder
   NbS2Peaks
        S2sPeak
        S2sLeftEdge
        S2sRightEdge
      S2sWidth
      S2sLowWidth
      S2sHeight
        S2sSaturation
        S2Order
   NbS1PeaksVeto
        S1sPeakVeto
        S1sLeftEdgeVeto
        S1sRightEdgeVeto
      S1sWidthVeto
      S1sLowWidthVeto
      S1sHeightVeto
        S1OrderVeto
    S1sRaw
    S2sRaw
    S1sRawVeto
    S1sMaxPosition
    S1sMaxPositionVeto)

list_of_branchesT3=(cS2sPosSvm cS2sPosNn cS2sPosChi2 cS1Tot cS1sTot cxS1Tot cxS1sTot cS2Tot
           cS2TotTop
           cS2TotBottom
     cS2sTot
     cS2sTotTop
     cS2sTotBottom
     cS2sLowWidth
     cfS2sLowWidth
     S1PatternLikelihood
   S1sPmtMaxHeight
   S1sBeforeMaximum
   S1sAfterMaximum
   S1sEntropy)

for arg in ${list_of_branchesT2[@]}
do
	if  grep -q $arg "$INPUTFILE"; then
		echo "b_$arg->GetEntry(ientry);"
#		echo "fChain->SetBranchStatus(\"$arg\",1);"
	fi
done  

for arg in ${list_of_branchesT1[@]}
do
	if  grep -q $arg "$INPUTFILE"; then
		echo "XeT1.b_$arg->GetEntry(ientry);"
#		echo "XeT1.fChain->SetBranchStatus(\"$arg\",1);"
	fi
done  

for arg in ${list_of_branchesT3[@]}
do
	if  grep -q $arg "$INPUTFILE"; then
#		echo "XeT3.fChain->SetBranchStatus(\"$arg\",1);"
		echo "XeT3.b_$arg->GetEntry(ientry);"
	fi
done  
