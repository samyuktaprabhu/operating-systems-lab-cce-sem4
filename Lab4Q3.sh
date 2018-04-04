ss()
{
for i in $@
do
 echo $i>>temp.txt
done
sort temp.txt
rm temp.txt
}

ss $@
