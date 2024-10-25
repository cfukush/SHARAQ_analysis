#include <iostream>
#include "TH1.h"
#include "TFile.h"
#include "TTree.h"
#include "TH2.h"
#include "TROOT.h"
#include "TCut.h"
#include "makeGate.hpp"
#include "makeGraph.hpp"

using namespace std;

void analysis(const char* rootFile, string name, Double_t Z, Double_t A);

int main(int argc, char* argv[]){
	if (argc != 5){
		cerr << "Usage: " <<argv[0] <<" <root file> <nuclide> <Atomic number> <Mass number>" << endl;
		return 1;
	}
	const char* rootFile = argv[1];
	string name = argv[2];
	Double_t Z = atof(argv[3]);
	Double_t A = atof(argv[4]);

	analysis(rootFile, name, Z, A);
	return 0;
}

void analysis(const char* rootFile, string name, Double_t Z, Double_t A){
	TFile *file = new TFile(rootFile);
	if (!file || file->IsZombie()) {
		std::cerr << "Error opening ROOT file: " << rootFile << std::endl;
		return;
	}
	TTree *tree = (TTree*)file->Get("sttree");
    if (!tree) {
		std::cerr << "Error accessing TTree in ROOT file: " << rootFile << std::endl;
		file->Close();
		return;
	}
	int bins = 400;
	int events = 1000000;
//	int events = 24867292;
	int firstEntry = 0;
	const int rangeElements = 5;
	int range[rangeElements] = {0,400,800,1200,1600};

	//settting ellipson gate
	makeGate analykit;
	TCut gate = analykit.gate(Z,A);

	makeGraph graph(tree);

	//make PID 
	graph.makePID(name, Z, A, gate, bins, events, firstEntry);

	//make energy spectrum with the range 0 to 1600, bins are 1600
	graph.makeHist(name, Z, A, gate, 4*bins, events, firstEntry, range[0], range[4]);

	//make energy spectrum separeted 400 keV energy 	
	for(int i=0; i<rangeElements-1; i++){
		graph.makeHist(name, Z, A, gate, bins, events, firstEntry, range[i], range[i+1]);
	}

	//make Tdiff vs Ecal 2D-hist 
	graph.makeTvsE(name, Z, A, gate, bins, events, firstEntry);
	gROOT->ProcessLine(".q");
}


