#!/bin/bash

echo "Enter the path"
read path

if [ -e $path ]
then
	if [ -f $path ]
	then 
		echo "File Contents : "
		cat $path
	else
		ls $path
	fi
else
	echo "file does not exist"
fi
