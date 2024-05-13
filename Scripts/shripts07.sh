#!/bin/bash

echo -n "Enter the Num"
read num
echo "$num's table"
for (( i=1 ; i<11 ; i++))
do 
	echo `expr $num \* $i`
done
