#!/bin/bash

SRCFOLDER=$(pwd)/src
CLASSPATH=$(pwd)/classes
cd $SRCFOLDER
javac -d $CLASSPATH dissimulator/Main.java


jar cmf $SRCFOLDER/META-INF/MANIFEST.MF dissimulate.jar -C $CLASSPATH