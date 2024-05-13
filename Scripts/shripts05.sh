#!/bin/bash
echo -n "Enter the num"
read num
echo "$num 's tables"
i=1
until [ $i -eq 11 ]
do
	echo `expr $num \* $i`
	i=`expr $i + 1`
done 
