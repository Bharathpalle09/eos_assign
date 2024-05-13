#!/bin/bash
echo "Enter the num"
read num
echo "$num table"
for i in `seq 1 10`
do
	echo `expr $num \* $i`
done
