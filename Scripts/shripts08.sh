#!/bin/bash
echo -n "Enter path"
read path

if [ -e $path ]
then 
	if [ -f $path ]
	then
		echo "path is of regular file"
		if [ -w $path -a -r $path ]
		then 
			echo "both permissions are there"
		elif [ -w $path ]
		then 
			echo "only write peermissions"
		fi
	else
		echo "some other file"
	fi
else
	echo "no file exist"
fi
