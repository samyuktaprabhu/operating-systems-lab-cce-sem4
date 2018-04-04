echo "Enter a number:"
read num
i=2
while [ $i -lt $num ]
do
 if [ `expr $num % $i` -eq 0 ]
 then
  echo "Entered num isnt a prime"
  exit
 fi
 i=`expr $i + 1`
done

echo "It is prime number."
