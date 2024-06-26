#ifndef makeGraph_hpp
#define makeGraph_hpp
#include <iostream>
#include <string>
#include "TH1.h"
#include "TH2.h"
#include "save.hpp"
using namespace std;

class makeGraph{
public:
	void makePID(string name, Double_t Z, Double_t A, TCut gate, int bins, int events, int firstEntry);
	void makeHist(string name, Double_t Z, Double_t A, TCut gate, int bins, int events, int firstEntry, int initial, int finale);
	void makeTvsE(string name, Double_t Z, Double_t A, TCut gate, int bins, int events, int firstEntry);
};

#endif
