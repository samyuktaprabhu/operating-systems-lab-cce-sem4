c=1
read f
e=even.txt
o=odd.txt
while read line
do

 even=$( expr $c % 2 )

 if [ $even -eq 1 ]
 then

 echo $line >> $o
 else
 echo $line >> $e
 fi
 
 (( c++ ))
done < $f
 
