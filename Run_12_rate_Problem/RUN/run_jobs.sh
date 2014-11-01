inputDir="/archive/root/minimum_bias/xenon100/run_12/"
list_number=$1
#cat "runList_${list_number}"
for arg in  `cat "runList_${list_number}"`; 
do
#	 ls "${inputDir}${arg}" 
	./run_rate "${inputDir}" "${arg}" &>"LOG/${arg}.out" 
done
