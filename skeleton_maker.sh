SkeletonName=$1
if [ -z "${SkeletonName}" ]; then 
	echo "Syntax:  skeleton_maker.sh  PROJECT_NAME"
	echo "You Should give a name!! QUIT!"
	return
fi

if [ -e "${SkeletonName}" ]; then
	echo "ERROR: File or Project exist allready!  QUIT!"
	return
fi

cp -r skeletons/ ${SkeletonName}
mv ${SkeletonName}/skeleton.C ${SkeletonName}/${SkeletonName}.C
mv ${SkeletonName}/skeleton.h ${SkeletonName}/${SkeletonName}.h

sed -i -e "s/skeleton/${SkeletonName}/g" ${SkeletonName}/*.C 
sed -i -e "s/skeleton/${SkeletonName}/g" ${SkeletonName}/*.h 
sed -i -e "s/skeleton/${SkeletonName}/g" ${SkeletonName}/*.sh 
sed -i -e "s/skeleton/${SkeletonName}/g" ${SkeletonName}/makefile 

