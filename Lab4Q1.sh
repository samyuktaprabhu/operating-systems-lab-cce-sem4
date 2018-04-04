name=`ls $1|cut -d "." -f 1`
extn=`ls $1|cut -d "." -f 2`
cp $1 $name"(copy)."$extn
