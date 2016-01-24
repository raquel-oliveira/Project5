#!/bin/bash
echo "Build dissimulation and revelation"
cd dissimulation; ./build.sh; cd ..
cd revelation; ./build.sh; cd ..

echo "Clean path"
rm compressedFiles/*.out
rm compressedFiles/*.png

chmod 700 dissimulation/dissimulate
chmod 700 revelation/reveal

image="../tests/original.jpg" 
failList="";

#for all the exemples files

for f in tests/compressedFiles/*.txt; 
do echo "Processing $f file.."; 
cd dissimulation;
echo "executing ./dissimulate -in $image -msg ../$f -out ../$f.png -metrics time"
./dissimulate -in $image -msg ../$f -out ../$f.png -metrics time -compress #1>/dev/null
echo "dissimulate done, revealing ..."
cd ../revelation;
echo "./reveal -in ../$f.png -out ../$f.out -compress"
./reveal -in ../$f.png -out ../$f.out -compress #1>/dev/null
cd ..

echo
#echo "comparing file with original"
original=$f
decoded=$f".out"
#echo "###############################################"
echo -e "From: $original Decoded : $decoded  :"
cmp -s $original $decoded && echo "Identical"  || failList="$failList $f"
#echo "###############################################"
done
if [ -z "$failList" ]; then
echo "################################# TEST OK #############################"; 
else
echo "################################# TEST FAIL ###########################"; 
echo "File with problems : $failList"
fi