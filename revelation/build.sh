#!/bin/sh
# to run: $ . file.sh
file="./bash.sh"

if [ -r $file ]
then
   echo "-- build the module"
   cmake .
   make
   echo "-- build with success"
else
   echo "-- error"
fi