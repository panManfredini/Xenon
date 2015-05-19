filenumber=$1
INPUTDIR="/archive/root/minimum_bias/xenon100/run_12-reprocessing/"

for filename in `cat RUN/run_12_all_std_split_${filenumber}`
do 
	./run_AmBeTest $INPUTDIR $filename &> LOG/${filename}.log
done
