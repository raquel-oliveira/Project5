#!/bin/sh
# to run: $ . file.sh
file="./integrationTest.sh"

if [ -r $file ]
then 
   cd dissimulation
   ./build.sh
   echo "--build dissimulation---"

   echo "First test: "
   ./dissimulate -in resources/original.jpg -msg resources/predefined_dictionnary.txt -metrics time -compress -out output/output1.png
   
   cd ../revelation
   ./build.sh 
   echo "--build revelation---"
   ./reveal -in ../dissimulation/output/output1.png  -compress -show -out output/output1.txt
   
   echo "compare: "
   sdiff -B -b -s ../dissimulation/resources/predefined_dictionnary.txt output/output1.txt | wc
else
   echo "-- error"
fi