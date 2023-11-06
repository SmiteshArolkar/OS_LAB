echo "Enter n "
read n
flag=2
i=1
j=0
while [ $j -ne $n ]
do 
   echo "$i" 
   if [ $flag -eq 2 ]
   then 
        i=$(($i + $flag))
        flag=-1
   else
       i=$(($i + $flag))
       flag=2
   fi
   j=$(($j+1))
done