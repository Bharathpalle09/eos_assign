#!/bin/bash

echo "positional parameters : $*"
echo "positional parameter count : $#"
echo "Scripit :$0"

for param in $*
do
	echo $param
done
