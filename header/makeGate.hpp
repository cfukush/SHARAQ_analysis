#ifndef makeGate_hpp
#define makeGate_hpp
#include <iostream>
#include <string>
#include "TCut.h"
using namespace std;

class makeGate{ 
private:
    Double_t sigmaAoQ = 0.0023;
    Double_t sigmaZ = 0.14;

public:
    Double_t gateRange = 9.; //Square of the radius of the ellipse
	TCut gate(Double_t Z, Double_t A);
};

#endif
