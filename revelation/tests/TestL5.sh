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
   ./reveal -in tests/L5test1.png -compress -out tests/outputs/outputL5test1.txt
   sdiff -B -b -s tests/L5test1.txt tests/outputs/outputL5test1.txt | wc

   echo "Second test to the file L5Test2.png"
   ./reveal -in tests/L5test2.png -c Red,Green,Blue -b 1 -p direct -magic 44657573 -compress -out tests/outputs/outputL5test2.txt
   sdiff -B -b -s tests/L5test2.txt tests/outputs/outputL5test2.txt | wc
else
   echo "-- error"
fi