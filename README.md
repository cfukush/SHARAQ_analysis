# SHARAQ_analysis
##requirements
ROOT > 6.28

#installation
```
git clone https://github.com/cfukush/SHARAQ_analysis.git
make clean;make
```
then Analysis file was created in ./bin directory


##usage
Analysis was performed 
```
./bin/Analysis [option] [rootfile] [nuclide] [atomic number] [mass number]
```
```
usage: ./bin/Analysis [option] [rootfile] [name] [Z] [A]
options
-h: show this help
-e [num]: number of events to be analyzed, default: MAX events
-f : first entry event for analysis, default: 0
-d [dir]: directory of output files (X/*.pdf), default: ./picture
-n [dir]: directory of output files with nuclide name (X/nuclide/*.pdf)
```

if you want to analysis all nuclide on PID, you can use roopAnalysis
```
./bin/roopAnalysis
```
