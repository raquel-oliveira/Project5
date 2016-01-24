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
echo "./dissimulate -in ../tests/original.jpg -msg ../tests/compressedFiles/alluminium.txt -out ../tests/compressedFiles/alluminium.png -metrics time -compress"
./dissimulate -in ../tests/original.jpg -msg ../tests/compressedFiles/alluminium.txt -out ../tests/compressedFiles/alluminium.png -metrics time -compress #1>/dev/null
cd ../revelation;

echo "./reveal -in ../tests/compressedFiles/ab.png -out ../tests/compressedFiles/ab.out -compress -show"
./reveal -in ../tests/compressedFiles/alluminium.png -out ../tests/compressedFiles/alluminium.out -compress -show #1>/dev/null

 echo "compare: with cmp:"
 cmp -s ../tests/compressedFiles/alluminium.out ../tests/compressedFiles/alluminium.txt && echo "Identical"  
 echo "show difference using sdiff -B -b -s:"
 sdiff -B -b -s ../tests/compressedFiles/alluminium.out ../tests/compressedFiles/alluminium.txt | wc
