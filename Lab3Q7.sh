c=1
read f
out=outi.txt
while read line
do

 even=$( expr $c % 2 )

 if [ $even -eq 1 ]
 then

 echo $line >> $out
 fi
 
 (( c++ ))
done < $f

rm $f
mv $out $f


