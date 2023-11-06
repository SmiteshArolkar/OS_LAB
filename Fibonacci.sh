echo "Enter number of terms"
read n
echo "Fibonacci series is:"
a=0
b=1
echo "$a"
echo "$b"
for((c=2;c<n;c++))
do
	c=$(($a + $b))
	echo "$c"
	a=$b
	b=$c
done
