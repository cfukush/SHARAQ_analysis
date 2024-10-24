#include "makeGraph.hpp"
using namespace std;

void makeGraph::makePID(string name, Double_t Z, Double_t A, TCut gate, int bins, int events, int firstEntry){
    TCanvas *c1 = new TCanvas("c1");
    c1->SetLogz();
    TH2D *h1 = new TH2D("h1", name.c_str(), bins, 1.7, 2.2, bins, 16, 28);
    sttree->Draw("s2z:s2aq >> h1", gate, "colz", events, firstEntry);
    saver.pidsave(c1, name);
    delete c1;
    delete h1;
}

void makeGraph::makeHist(string name, Double_t Z, Double_t A, TCut gate, int bins, int events, int firstEntry, int initial, int finale){
    TCut Tgate0 = "Tdiff[1]>100&&Tdiff[1]<10000";
    TCut Tgate1 = "Tdiff[1]>200&&Tdiff[1]<10000";
    TCut Tgate2 = "Tdiff[1]>100&&Tdiff[1]<1000000";
    TCut Tgate3 = "Tdiff[1]>100&&Tdiff[1]<10000000";  

    string canvasName = "c_";
    string histName = "h_";

    TCanvas *c2 = new TCanvas((canvasName+"Tgate0"+name).c_str());
    c2->SetLogy();
    TH1D *h2 = new TH1D(((histName+"Tgate0"+name).c_str()),name.c_str(),bins,initial,finale);
    sttree->Draw("Ecal[1]>>h2", gate&&Tgate0, "", events,firstEntry);
    saver.histsave(c2, name, initial, "Tgate0");
    delete h2;
    delete c2;

    TCanvas *c3 = new TCanvas((canvasName+"Tgate1"+name).c_str());
    c3->SetLogy();
    TH1D *h3 = new TH1D(((histName+"Tgate1"+name).c_str()),name.c_str(),bins,initial,finale);
    sttree->Draw("Ecal[1]>>h3", gate&&Tgate1, "", events,firstEntry);
    saver.histsave(c3, name, initial, "Tgate1");
    delete h3;
    delete c3;

    TCanvas *c4 = new TCanvas((canvasName+"Tgate2"+name).c_str());
    c4->SetLogy();
    TH1D *h4 = new TH1D(((histName+"Tgate2"+name).c_str()),name.c_str(),bins,initial,finale);
    sttree->Draw("Ecal[1]>>h4", gate&&Tgate2, "", events,firstEntry);
    saver.histsave(c4, name, initial, "Tgate2");
    delete h4;
    delete c4;

    TCanvas *c5 = new TCanvas((canvasName+"Tgate3"+name).c_str());
    c5->SetLogy();
    TH1D *h5 = new TH1D(((histName+"Tgate3"+name).c_str()),name.c_str(),bins,initial,finale);
    sttree->Draw("Ecal[1]>>h5", gate&&Tgate3, "", events,firstEntry);
    saver.histsave(c5, name, initial, "Tgate3");
    delete h5;
    delete c5;
}

void makeGraph::makeTvsE(string name, Double_t Z, Double_t A, TCut gate, int bins, int events, int firstEntry){
    TCanvas *c22 = new TCanvas("c22");
    TH2D *h22 = new TH2D("h22",name.c_str(),bins,-10000,20000000,bins,0,1600);
    sttree->Draw("Ecal[1]:Tdiff[1]>> h22", gate, "colz", events,firstEntry);
    string p22name = "./picture/" + name + "_ET.pdf";
    c22->Print(p22name.c_str());
    delete h22;
    delete c22;
}

