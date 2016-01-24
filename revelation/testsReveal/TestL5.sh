#!/bin/sh
# to run: $ . file.sh
file="./TestL5.sh"

if [ -r $file ]
then 
   cd ..
   pwd
   ./build.sh
   echo "--build---"

   echo "First test to the file L5Test1.png"
   ./reveal -in testsReveal/L5test1.png -compress -out testsReveal/outputs/outputL5test1.txt
   sdiff -B -b -s testsReveal/L5test1.txt testsReveal/outputs/outputL5test1.txt | wc

   echo "Second test to the file L5Test2.png"
   ./reveal -in testsReveal/L5test2.png -c Red,Green,Blue -b 1 -p direct -magic 44657573 -compress -out testsReveal/outputs/outputL5test2.txt
   sdiff -B -b -s testsReveal/L5test2.txt testsReveal/outputs/outputL5test2.txt | wc
else
   echo "-- error"
fi