#!/bin/sh
# to run: $ . file.sh
file="./build.sh"

if [ -r $file ]
then
	echo "-- Clean module"
	make clean
   	echo "-- build the module"
   	cmake .
   	make
	echo "-- build with success"
else
   echo "-- error"
fi