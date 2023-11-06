
echo 'Enter a number'
read num
m=$num
largest=0
smallest=9

while [ $m -ne 0 ]
do
    d=$(($m%10))
    if [ $largest -lt $d ]
    then
        largest=$d
    fi
    if [ $smallest -gt $d ]
    then
        smallest=$d
    fi
    m=$(($m/10))

done

echo "laregest,smallest : $largest,$smallest"

m=$num
second_largest=0
second_smallest=$largest
while [ $m -ne 0 ]
do 
    d=$(($m%10))
    if [ $second_largest -lt $d ]
    then 
        if [ $d -ne $largest ]
        then 
            second_largest=$d
        fi
    fi
    if [ $second_smallest -gt $d ]
    then 
        if [ $d -ne $smallest ]
        then 
            second_smallest=$d
        fi
    fi
    m=$((m/10))
done

echo "2 nd laregest , smallest : $second_largest,$second_smallest"

diff=$(($second_largest - $second_smallest))
echo "difference = $diff"