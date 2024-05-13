#!/bin/bash
echo -n "Enter the leap year"
read year
num1=100
if[$((`expr $year % $num1`) -eq 0) ]
then
	if[`expr $year% 400` -eq 0 ]
	then
		echo -n "$year is a leap year"
elif[`expr $year % 4` - eq 0 ]
then
	echo -n "$year is leap year"
else
then
	echo -n "its not a leap year"
fi
