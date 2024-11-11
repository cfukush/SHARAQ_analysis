#include "save.hpp"

using namespace std;

void save::setFilepath(string path){
	filepath = path;
	cout << filepath << endl;
}

void save::pidsave(TCanvas *c, string name){
    //string filepath = "./picture/envents1000000/";
    //string filepath = "./picture/";
	cout << filepath << endl;
    string pname = filepath + name + "pid.pdf";
    c->Print(pname.c_str());
}

void save::histsave(TCanvas *c, string name, int firstRange, string option){
    //string filepath = "./picture/envents1000000/";
    //string filepath = "./picture/";
    string pname = filepath + name;
    
    switch (firstRange){
       case 0: 
            pname += "_Ecal0_from0" + option + ".pdf";
            c->Print(pname.c_str());
            break;
       case 400: 
            pname += "_Ecal0_from400" + option + ".pdf";
            c->Print(pname.c_str());
            break;
       case 800: 
            pname += "_Ecal0_from800" + option + ".pdf";
            c->Print(pname.c_str());
            break;
       case 1200: 
            pname += "_Ecal0_from1200" + option + ".pdf";
            c->Print(pname.c_str());
            break;
       default: 
            pname += "_Ecal0_allRange" + option + ".pdf";
            c->Print(pname.c_str());
            break;
    }
}


