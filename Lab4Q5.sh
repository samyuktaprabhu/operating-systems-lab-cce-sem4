echo " 1. search 2. del 3. exit"
read a
echo "File name"
read b
case $a in
1)echo $*
  for i in $@;do
  grep $i $b
  done;;
2)echo $*
  for i in $@;do
  grep $i $b
  sed -i -e 's/$i/g' $b
  done;;
3)exit
esac
