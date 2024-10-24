#include "makeGate.hpp"

TCut makeGate::gate(Double_t Z, Double_t A){
    Double_t aoq = A/Z;
    TCut gateNuclide = TCut(Form("((s2z-%f)/%f)**2 + ((s2aq-%f)/%f)**2 < %f", Z, sigmaZ, aoq, sigmaAoQ, gateRange));
    return gateNuclide;
}
