#!/bin/bash

# ´$@´ is all of the parameters passed to the script
# ´val´ is a abitrary variable name which holds the place of 
# one of the parameters, echo prints the the variable ($val)
# to the screen

# commented out because every argument was printed out but only 3 need to be printed
<<com
for val in $@
do
echo $val
done
com

if [ $# == 0 ]
then
	echo "No arguments supplied"
fi

if [ $1 ]
then
	echo $1
fi

if [ $2 ]
then
	echo $2
fi

if [ $3 ]
then
	echo $3
fi
