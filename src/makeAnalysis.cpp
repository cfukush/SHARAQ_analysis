#include <iostream>
#include <sstream>
#include <string>
#include <time.h>
#include <getopt.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <cctype>
#include <fstream>
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TStyle.h"
#include "TSystem.h"
#include "TCutG.h"
#include "Analysis.hpp"

static void usage();
static void searchNuclide(string name, Double_t *A, Double_t *Z);

int main(int argc, char* argv[]){
	string outdir = "./picture/";
	string outdirEachNucl = "";
	int firstEntry = 0;
	int c;
	Long64_t events = 0;
	Double_t Z = 0;
	Double_t A = 0;
	
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

	if(argc != 2){
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
	searchNuclide(name, &A, &Z);
	 
	std::cout << "Nuclide you focus on: " << name << std::endl;
	std::cout << "Atiomic number: " << Z << std::endl;
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
	 std::cout << " usage: ./bin/Analysis [option] [rootfile] [name]"  << std::endl;
	 std::cout << " options" << std::endl;
	 std::cout << " -h: show this help" << std::endl;
	 std::cout << " -e [num]: number of events to be analyzed, default: MAX events" << std::endl;
	 std::cout << " -f : first entry event for analysis, default: 0" << std::endl;
	 std::cout << " -d [dir]: directory of output files (X/*.pdf), default: ./picture" << std::endl;
	 std::cout << " -n [dir]: directory of output files with nuclide name (X/nuclide/*.pdf)" << std::endl;
	 return;
}

void searchNuclide(string name,  Double_t *A, Double_t *Z){
	std::fstream file("./elementsList.txt");
	std::string line;
	std::string fileEleName;
	if (!file.is_open()) {
		std::cerr << "Error: Unable to open elementsList.txt file." << std::endl;
		exit(1);
	}

	for(char ch : name){
		if(std::isdigit(ch)){
			*A += *A*10 + (ch-'0');
		}
		else if(std::isalpha(ch)){
			fileEleName += ch;
		}
	}	

    if (fileEleName.empty() || *A == 0) {
		std::cerr << "Error: Invalid input format. Expected format: [mass number][element symbol] (e.g., 45Cr)." << std::endl;
		exit(1);
	}

	while(std::getline(file, line)){
		std::istringstream iss(line);
		std::string fileElement;
		Double_t fileNum;

		if(iss >> fileElement >> fileNum){
			if(fileElement == fileEleName){
				*Z = fileNum;
				break;
			}
		}
	}
	file.close();

	if (*Z == 0) {
		std::cerr << "Error: Element " << fileEleName << " not found in elementsList.txt." << std::endl;
		exit(1);
	}

}
