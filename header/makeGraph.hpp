#include <iostream>
#include <string>
#include "TH1.h"
#include "TH2.h"
#include "save.hpp"
using namespace std;

void makePID(string name, Double_t Z, Double_t A, TCut gate, int bins, int events, int firstEntry){
    TCanvas *c1 = new TCanvas("c1");
    c1->SetLogz();
    TH2D *h1 = new TH2D("h1", name.c_str(), bins, 1.7, 2.2, bins, 16, 28);
    sttree->Draw("s2z:s2aq >> h1", gate, "colz", events, firstEntry);
    pidsave(c1, name);
}

void makeHist(string name, Double_t Z, Double_t A, TCut gate, int bins, int events, int firstEntry, int initial, int finale){
    TCut Tgate0 = "Tdiff[1]>100&&Tdiff[1]<10000";
    TCut Tgate1 = "Tdiff[1]>200&&Tdiff[1]<10000";
    TCut Tgate2 = "Tdiff[1]>100&&Tdiff[1]<1000000";
    TCut Tgate3 = "Tdiff[1]>100&&Tdiff[1]<10000000";  

    TCanvas *c2 = new TCanvas("c2");
    c2->SetLogy();
    TH1D *h2 = new TH1D("h2",name.c_str(),bins,initial,finale);
    sttree->Draw("Ecal[1]>>h2", gate&&Tgate0, "", events,firstEntry);
    histsave(c2, name, initial, "Tgate0");
    TCanvas *c3 = new TCanvas("c3");
    c3->SetLogy();
    TH1D *h3 = new TH1D("h3",name.c_str(),bins,initial,finale);
    sttree->Draw("Ecal[1]>>h3", gate&&Tgate1, "", events,firstEntry);
    histsave(c3, name, initial, "Tgate1");
    TCanvas *c4 = new TCanvas("c4");
    c4->SetLogy();
    TH1D *h4 = new TH1D("h4",name.c_str(),bins,initial,finale);
    sttree->Draw("Ecal[1]>>h4", gate&&Tgate2, "", events,firstEntry);
    histsave(c4, name, initial, "Tgate2");
    TCanvas *c5 = new TCanvas("c5");
    c5->SetLogy();
    TH1D *h5 = new TH1D("h5",name.c_str(),bins,initial,finale);
    sttree->Draw("Ecal[1]>>h5", gate&&Tgate3, "", events,firstEntry);
    histsave(c5, name, initial, "Tgate3");
}

void makeTvsE(string name, Double_t Z, Double_t A, TCut gate, int bins, int events, int firstEntry){
    TCanvas *c22 = new TCanvas("c22");
    TH2D *h22 = new TH2D("h22",name.c_str(),bins,-10000,20000000,bins,0,1600);
    sttree->Draw("Ecal[1]:Tdiff[1]>> h22", gate, "colz", events,firstEntry);
    string p22name = "./picture/" + name + "_ET.pdf";
    c22->Print(p22name.c_str());
}
