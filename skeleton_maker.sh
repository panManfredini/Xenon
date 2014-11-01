SkeletonName=$1

if [ -e "${SkeletonName}" ]; then
	echo "file exist allready!  QUIT!"
	return
fi

cp -r skeletons/ ${SkeletonName}
mv ${SkeletonName}/skeleton.C ${SkeletonName}/${SkeletonName}.C
mv ${SkeletonName}/skeleton.h ${SkeletonName}/${SkeletonName}.h

sed -i -e "s/skeleton/${SkeletonName}/g" ${SkeletonName}/*.C 
sed -i -e "s/skeleton/${SkeletonName}/g" ${SkeletonName}/*.h 
sed -i -e "s/skeleton/${SkeletonName}/g" ${SkeletonName}/*.sh 
sed -i -e "s/skeleton/${SkeletonName}/g" ${SkeletonName}/makefile 

