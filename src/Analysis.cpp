#include <Analysis.hpp>
#define ANALYSIS_CPP

void Analysis::ana(const char* rootFile, string name, Double_t Z, Double_t A, Long64_t event, int first, string dir){
	TFile *file = new TFile(rootFile);
	if (!file || file->IsZombie()){
		std::cerr << "Error opening ROOT file: " << rootFile << std::endl;
		return;
	}
	TTree *tree = (TTree*)file->Get("sttree");
	if (!tree){
		std::cerr << "Error accessing TTree in ROOT file: " << rootFile << std::endl;
		return;
	}
	
	std::cout <<  "All events:  " << tree->GetEntries() << " entries." << std::endl;

	int bins = 400;
	int events = event;
	int firstEntry = first;
	const int rangeElements = 5;
	int range[rangeElements]={0,400,800,1200,1600};

	makeGate analykit;
	TCut gate = analykit.gate(Z,A);

	save saver;
	saver.setFilepath(dir);
    std::cout << "Filepath: " << saver.filepath << std::endl;

	makeGraph graph(tree);
	graph.makePID(saver, name, Z, A, gate, bins, events, firstEntry);
	graph.makeHist(saver, name, Z, A, gate, 4*bins, events, firstEntry, range[0], range[4]);

	for(int i=0; i<rangeElements-1; i++){
		graph.makeHist(saver, name, Z, A, gate, bins, events, firstEntry, range[i], range[i+1]);
	}

	graph.makeTvsE(saver, name, Z, A, gate, bins, events, firstEntry);
	gROOT->ProcessLine(".q");
}
