#!/bin/bash

function print_msg
{
	echo "this is a functrion"

}

second_fun()
{
	echo "this is second function"
}

addition()
{
	res=`expr $1 + $2`
	echo $res

}

echo "enter the two numbers"
read num1 num2

sum=`addition $num1 $num2`
echo "$num1 + $num2 = $sum"
