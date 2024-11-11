#ifndef makeGraph_hpp
#define makeGraph_hpp
#include <iostream>
#include <string>
#include "TH1.h"
#include "TH2.h"
#include "TCut.h"
#include "TTree.h"
#include "save.hpp"
using namespace std;

class makeGraph{
public: 
	makeGraph(TTree* tree):sttree(tree){}
	void makePID(save saver, string name, Double_t Z, Double_t A, TCut gate, int bins, int events, int firstEntry);
	void makeHist(save saver, string name, Double_t Z, Double_t A, TCut gate, int bins, int events, int firstEntry, int initial, int finale);
	void makeTvsE(save saver, string name, Double_t Z, Double_t A, TCut gate, int bins, int events, int firstEntry);

private:
	TTree *sttree;

};

#endif
