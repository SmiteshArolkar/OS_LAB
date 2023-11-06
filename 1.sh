echo "Enter a number"
read n
sum=0
while [ $n -ne 0 ]
  do
     a=$(($n % 10))
     n=$(($n/10))
     sum=$(($sum + $a))
  done
echo "sum = $sum"