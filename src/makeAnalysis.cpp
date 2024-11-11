#include <iostream>
#include <sstream>
#include <string>
#include <time.h>
#include <getopt.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TStyle.h"
#include "TSystem.h"
#include "TCutG.h"
#include "Analysis.hpp"

static void usage();

int main(int argc, char* argv[]){
	string outdir = "./picture/";
	string outdirEachNucl = "";
	int firstEntry = 0;
	int c;
	Long64_t events = 0;
	
	while((c = getopt(argc, argv, "h:e:f:d:n:"))!= -1){
		switch(c){
			case 'h':
				usage();
				exit(0);
			case 'e':
				events = (int)atoi(optarg);
				break;
			case 'f':
				firstEntry = (int)atoi(optarg);
				break;
			case 'd':
				outdir = "./" + string(optarg) + "/";
				break;
			case 'n':
				outdirEachNucl = string(optarg);
				outdir = outdir + outdirEachNucl + "/";
				break;
			default :
				usage();
				exit(1);
		}
	}
	argc -= optind;
	argv += optind;

	if(argc != 4){
		usage();
		exit(1);
	}

	const char* rootFile = argv[0];
	std::cout << "input root file: " << rootFile << std::endl;

	TFile *file = new TFile(rootFile);
	if (!file || file->IsZombie()) {
		std::cerr << "Error opening ROOT file: " << rootFile << std::endl;
		exit(1);
	}
	TTree *tree = (TTree*)file->Get("sttree");
    if (!tree) {
		std::cerr << "Error accessing TTree in ROOT file: " << rootFile << std::endl;
		file->Close();
		exit(1);
	}
	if(events == 0){
		Long64_t events = tree->GetEntries();
	}

	string name = argv[1];
	Double_t Z = atof(argv[2]); 
	Double_t A = atof(argv[3]);
	std::cout << "Nuclide you focus on: " << name << std::endl;
	std::cout << "Atiomin number: " << Z << std::endl;
	std::cout << "Mass number: " << A << std::endl;

	struct stat info;
	if(stat(outdir.c_str(), &info)!=0){
		std::cout << "There's no directory " << outdir << " ." << endl;
		mkdir(outdir.c_str(), 0777);
		std::cout << "Create new directory."  << endl;
	}

	Analysis *Ana = new Analysis();
	Ana->ana(rootFile, name, Z, A, events, firstEntry, outdir);
	delete Ana;

	return 0;
}

static void usage()
{
	 std::cout << " usage: ./bin/Analysis [option] [rootfile] [name] [Z] [A]"  << std::endl;
	 std::cout << " options" << std::endl;
	 std::cout << " -h: show this help" << std::endl;
	 std::cout << " -e [num]: number of events to be analyzed, default: MAX events" << std::endl;
	 std::cout << " -f : first entry event for analysis, default: 0" << std::endl;
	 std::cout << " -d [dir]: directory of output files (X/*.pdf), default: ./picture" << std::endl;
	 std::cout << " -n [dir]: directory of output files with nuclide name (X/nuclide/*.pdf)" << std::endl;
	 return;
}

