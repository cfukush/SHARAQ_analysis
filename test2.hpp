#include <iostream>
#include <string>

class prmset{
public:
    Double_t sigmaAoQ = 0.0023;
    Double_t sigmaZ = 0.14;
    Double_t gateRange = 9.;

TCut gate(Double_t Z, Double_t A){
    Double_t aoq = A/Z;
    TCut gateNuclide = Form("((s2z-%f)/%f)**2 + ((s2aq-%f)/%f)**2 < %f", Z, sigmaZ, aoq, sigmaAoQ, gateRange);
//    TCut zCut = Form("abs(s2z-%f)<%f",Z, sigmaZ);
//    TCut aoqCut = Form("abs(s2aq-%f)<%f",aoq, sigmaAoQ);
//    return zCut&&aoqCut;
    return gateNuclide;
}

void pidsave(TCanvas *c, string name){
    //string filepath = "./picture/envents1000000/";
    string filepath = "./picture/maxevents/";
    string pname = filepath + name + "pid.pdf";
    c->Print(pname.c_str());
}

void histsave(TCanvas *c, string name, int firstRange, string option){
    //string filepath = "./picture/envents1000000/";
    string filepath = "./picture/maxevents/";
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
};