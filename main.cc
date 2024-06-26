#include <iostream>
#include "TH1.h"
#include "TH2.h"
#include "./header/makeGate.hpp"
#include "./header/makeGraph.hpp"
using namespace std;

void analysis(string name, Double_t Z, Double_t A){
	int bins = 400;
	int events = 10000;
//	int events = 24867292;
	int firstEntry = 0;
	const int rangeElements = 5;
	int range[rangeElements] = {0,400,800,1200,1600};

	makeGate analykit;
	TCut gate = analykit.gate(Z,A);

	makeGraph graph;
	
	graph.makeHist(name, Z, A, gate, bins, events, firstEntry, range[0], range[4]);
	
	for(int i=0; i<rangeElements-1; i++){
		graph.makeHist(name, Z, A, gate, bins, events, firstEntry, range[i], range[i+1]);
	}

	graph.makeTvsE(name, Z, A, gate, bins, events, firstEntry);
	gROOT->ProcessLine(".q");
}
