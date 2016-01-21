#!/bin/bash

if [ ! -d classes ]; then
    mkdir classes
fi
javac -d classes src/dissimulator/*.java