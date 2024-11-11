#ifndef ANALISIS_HPP
#define ANALISIS_HPP
#include <iostream>
#include "TH1.h"
#include "TFile.h"
#include "TTree.h"
#include "TH2.h"
#include "TROOT.h"
#include "TCut.h"
#include "makeGate.hpp"
#include "makeGraph.hpp"
#include "save.hpp"

class Analysis{
public:
	Analysis() {};
	~Analysis() {};
	void ana(const char* rootFile, string name, Double_t Z, Double_t A, Long64_t event, int first, string dir);
};

#endif
