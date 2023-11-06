echo "Enter number of terms"
read n
sum=0
num=$n
while [ $num -gt 0 ]
do
	echo "Enter number"
	read a
	sum=$(($sum + $a))
	num=$(($num - 1))
done
avg=$(($sum / $n))
echo "Sum is $sum"
echo "Average is $avg"
