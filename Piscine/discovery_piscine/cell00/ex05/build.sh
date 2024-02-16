#!	/bin/bash


if [ $# == 0 ]
then
	echo "No arguments supplied"
fi

for val in $@
do
mkdir ex$val
done
