#!/bin/bash
echo "Build dissimulation and revelation"
cd ..
cd dissimulation; ./build.sh; cd ..
cd revelation; ./build.sh; cd ..

echo "Clean path"
rm tests/compressedFiles/*.out
rm tests/compressedFiles/*.png

chmod 700 dissimulation/dissimulate
chmod 700 revelation/reveal

cd dissimulation;
echo "./dissimulate -in ../tests/original.jpg -msg ../tests/compressedFiles/7a.txt -out ../tests/compressedFiles/7a.png -metrics time -compress"
./dissimulate -in ../tests/original.jpg -msg ../tests/compressedFiles/7a.txt -out ../tests/compressedFiles/7a.png -metrics time -compress #1>/dev/null
cd ../revelation;
echo "./reveal -in ../tests/compressedFiles/7a.png -out ../tests/compressedFiles/7a.out -compress"
./reveal -in ../tests/compressedFiles/7a.png -out ../tests/compressedFiles/7a.out -compress #1>/dev/null

 echo "compare: with cmp:"
 cmp -s ../tests/compressedFiles/7a.out ../tests/compressedFiles/7a.txt && echo "Identical"  
 echo "show difference using sdiff -B -b -s:"
 sdiff -B -b -s ../tests/compressedFiles/7a.out ../tests/compressedFiles/7a.txt | wc
