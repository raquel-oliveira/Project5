<<<<<<< HEAD
#!/bin/sh
# to run: $ . file.sh
file="./build.sh"

if [ -r $file ]
then
   echo "-- build the module"
   mkdir class
   javac -d class -sourcepath Java/src/ Java/src/dissimulator/*.java
   jar cvmf MANIFEST.MF dissimulation.jar -C ./class .
   echo "-- build with success"
   echo "#!/bin/bash" > ./dissimulation
   echo "java -jar dissimulation.jar \"\$@\"" >> ./dissimulation
   chmod 774 dissimulation
else
   echo "-- error"
fi
=======
#!/bin/bash

SRCFOLDER=$(pwd)/src
CLASSPATH=$(pwd)/classes
cd $SRCFOLDER
javac -d $CLASSPATH dissimulator/Main.java


jar cmf $SRCFOLDER/META-INF/MANIFEST.MF dissimulate.jar -C $CLASSPATH
>>>>>>> 1d6eceb8b02585b5b61491cb530fb92cc1cf3dfc
