#ifndef save_hpp
#define save_hpp
#include <iostream>
#include <string>
#include "TCanvas.h"
using namespace std;

class save{
public:
	string filepath;
	void setFilepath(string path);
	void pidsave(TCanvas *c, string name);
	void histsave(TCanvas *c, string name, int firstRange, string option);
};

#endif
