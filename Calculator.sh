echo "Enter first number"
read a
echo "Enter second number"
read b
ch=1
while [ $ch -eq 1 ]
do
	echo "Menu"
	echo "1. Addition"
	echo "2. Subtraction"
	echo "3. Multiplication"
	echo "4. Division"
	echo "Enter your choice"
	read choice
	
	case $choice in
	1) c=$(($a + $b))
	echo "Addition is $c"
	;;
	
	2) c=$(($a - $b))
	echo "Subtraction is $c"
	;;
	
	3) c=$(($a * $b))
	echo "Multiplication is $c"
	;;

	4) c=$(($a / $b))
	echo "Division is $c"
	;;
	
	*) echo "Invalid choice"
	esac
	
	echo "Do you want to continue(1/0)?"
	read ch
done
	
	

