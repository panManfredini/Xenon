filenumber=$1
INPUTDIR="/archive/root/minimum_bias/xenon100/run_10/"

#for filename in `cat RUN/list_ambe`  #comment me 
for filename in `cat RUN/run_10_co60_std_split_${filenumber}` #uncomment for run on multiple file
do 
#	./run_Inelastic $INPUTDIR $filename &> LOG/${filename}.log  & #comment me
	./run_Inelastic $INPUTDIR $filename &> LOG/${filename}.log #uncomment me
done