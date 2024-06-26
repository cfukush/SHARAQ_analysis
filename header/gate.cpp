#include <iostream>
#include <string>
#include "makeGate.hpp"

TCut makeGate::gate(Double_t Z, Double_t A){
    Double_t aoq = A/Z;
    TCut gateNuclide = Form("((s2z-%f)/%f)**2 + ((s2aq-%f)/%f)**2 < %f", Z, sigmaZ, aoq, sigmaAoQ, gateRange);
//    TCut zCut = Form("abs(s2z-%f)<%f",Z, sigmaZ);
//    TCut aoqCut = Form("abs(s2aq-%f)<%f",aoq, sigmaAoQ);
//    return zCut&&aoqCut;
    return gateNuclide;
}
