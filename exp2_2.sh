echo "enter a b c for  eqn 1 : ax2 + bx + c"
read a
read b
read c

d=$(($b*$b - 4*$a*$c))

if [ $d -gt 0 ]
then 
   root1=$( echo "scale=2; (-$b + sqrt($d)) / (2*$a)" | bc )
   root2=$( echo "scale=2; (-$b - sqrt($d)) / (2*$a)" | bc )
   echo "Root 1 : $root1"
   echo "Root 2 : $root2"
else [ $d -eq 0 ]
 root=$( echo "scale=2; -$b / (2*$a)" | bc )
 echo "roots : $root"
fi