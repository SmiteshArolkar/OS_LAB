echo "Enter number"
read n
for ((i=2;i<n;i++))
do
	r=$(($n % $i))
	if [ $r -eq 0 ]
	then
		echo "Not prime"
		exit
	fi
done
echo "Prime"

