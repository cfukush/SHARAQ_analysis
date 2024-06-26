#include <iostream>
#include "TH1.h"
#include "TH2.h"
#include "test2.hpp"

void makehist_PID(string name, Double_t Z, Double_t A){
    int bins = 400;

    prmset analykit;
    TCut gate = analykit.gate(Z,A);
    TCut Tgate0 = "Tdiff[1]>100&&Tdiff[1]<10000";
    TCut Tgate1 = "Tdiff[1]>200&&Tdiff[1]<10000";
    TCut Tgate2 = "Tdiff[1]>100&&Tdiff[1]<1000000";
    TCut Tgate3 = "Tdiff[1]>100&&Tdiff[1]<10000000";  

    TCanvas *c1 = new TCanvas("c1");
    c1->SetLogz();
    TH2D *h1 = new TH2D("h1",name.c_str(),bins,1.7,2.2,bins,16,28);
    sttree->Draw("s2z:s2aq >> h1", gate, "colz");
//j    string pidname = name + "PID.pdf";
//    c1->Print(pname.c_str());
    analykit.pidsave(c1, name);


//    TCanvas *c2 = new TCanvas("c2");
//    TH1D *h2 = new TH1D("h2",name.c_str(),bins,0,1600);
//    sttree->Draw("Ecal[1]>>h2", gate&&Tgate0);
//    analykit.histsave(c2, name, 2,"Tgate0");
//    TCanvas *c3 = new TCanvas("c3");
//    TH1D *h3 = new TH1D("h3",name.c_str(),bins,0,1600);
//    sttree->Draw("Ecal[1]>>h3", gate&&Tgate1);
//    analykit.histsave(c3, name, 2, "Tgate1");
//    TCanvas *c4 = new TCanvas("c4");
//    TH1D *h4 = new TH1D("h4",name.c_str(),bins,0,1600);
//    sttree->Draw("Ecal[1]>>h4", gate&&Tgate2);
//    analykit.histsave(c4, name, 2, "Tgate2");
//    TCanvas *c5 = new TCanvas("c5");
//    TH1D *h5 = new TH1D("h5",name.c_str(),bins,0,1600);
//    sttree->Draw("Ecal[1]>>h5", gate&&Tgate3);
//    analykit.histsave(c5, name, 2, "Tgate3");
//
//    TCanvas *c6 = new TCanvas("c6");
//    TH1D *h6 = new TH1D("h6",name.c_str(),bins,0,400);
//    sttree->Draw("Ecal[1]>>h6", gate&&Tgate0);
//    analykit.histsave(c6, name, 0, "Tgate0");
//    TCanvas *c7 = new TCanvas("c7");
//    TH1D *h7 = new TH1D("h7",name.c_str(),bins,0,400);
//    sttree->Draw("Ecal[1]>>h7", gate&&Tgate1);
//    analykit.histsave(c7, name, 0, "Tgate1");
//    TCanvas *c8 = new TCanvas("c8");
//    TH1D *h8 = new TH1D("h8",name.c_str(),bins,0,400);
//    sttree->Draw("Ecal[1]>>h8", gate&&Tgate2);
//    analykit.histsave(c8, name, 0, "Tgate2");
//    TCanvas *c9 = new TCanvas("c9");
//    TH1D *h9 = new TH1D("h9",name.c_str(),bins,0,400);
//    sttree->Draw("Ecal[1]>>h9", gate&&Tgate3);
//    analykit.histsave(c9, name, 0, "Tgate3");
//     
//    TCanvas *c10 = new TCanvas("c10");
//    TH1D *h10 = new TH1D("h10",name.c_str(),bins,400,800);
//    sttree->Draw("Ecal[1]>>h10", gate&&Tgate0);
//    analykit.histsave(c10, name, 400, "Tgate0");
//    TCanvas *c11 = new TCanvas("c11");
//    TH1D *h11 = new TH1D("h11",name.c_str(),bins,400,800);
//    sttree->Draw("Ecal[1]>>h11", gate&&Tgate1);
//    analykit.histsave(c11, name, 400, "Tgate1");
//    TCanvas *c12 = new TCanvas("c12");
//    TH1D *h12 = new TH1D("h12",name.c_str(),bins,400,800);
//    sttree->Draw("Ecal[1]>>h12", gate&&Tgate2);
//    analykit.histsave(c12, name, 400, "Tgate2");
//    TCanvas *c13 = new TCanvas("c13");
//    TH1D *h13 = new TH1D("h13",name.c_str(),bins,400,800);
//    sttree->Draw("Ecal[1]>>h13", gate&&Tgate3);
//    analykit.histsave(c13, name, 400, "Tgate3");
//
//    TCanvas *c14 = new TCanvas("c14");
//    TH1D *h14 = new TH1D("h14",name.c_str(),bins,800,1200);
//    sttree->Draw("Ecal[1]>>h14", gate&&Tgate0);
//    analykit.histsave(c14, name, 800, "Tgate0");
//    TCanvas *c15 = new TCanvas("c15");
//    TH1D *h15 = new TH1D("h15",name.c_str(),bins,800,1200);
//    sttree->Draw("Ecal[1]>>h15", gate&&Tgate1);
//    analykit.histsave(c15, name, 800, "Tgate1");
//    TCanvas *c16 = new TCanvas("c16");
//    TH1D *h16 = new TH1D("h16",name.c_str(),bins,800,1200);
//    sttree->Draw("Ecal[1]>>h16", gate&&Tgate2);
//    analykit.histsave(c16, name, 800, "Tgate2");
//    TCanvas *c17 = new TCanvas("c17");
//    TH1D *h17 = new TH1D("h17",name.c_str(),bins,800,1200);
//    sttree->Draw("Ecal[1]>>h17", gate&&Tgate3);
//    analykit.histsave(c17, name, 800, "Tgate3");
//
//    TCanvas *c18 = new TCanvas("c18");
//    TH1D *h18 = new TH1D("h18",name.c_str(),bins,1200,1600);
//    sttree->Draw("Ecal[1]>>h18", gate&&Tgate0);
//    analykit.histsave(c18, name, 1200, "Tgate0");
//    TCanvas *c19 = new TCanvas("c19");
//    TH1D *h19 = new TH1D("h19",name.c_str(),bins,1200,1600);
//    sttree->Draw("Ecal[1]>>h19", gate&&Tgate1);
//    analykit.histsave(c19, name, 1200, "Tgate1");
//    TCanvas *c20 = new TCanvas("c20");
//    TH1D *h20 = new TH1D("h20",name.c_str(),bins,1200,1600);
//    sttree->Draw("Ecal[1]>>h20", gate&&Tgate2);
//    analykit.histsave(c20, name, 1200, "Tgate2");
//    TCanvas *c21 = new TCanvas("c21");
//    TH1D *h21 = new TH1D("h21",name.c_str(),bins,1210,1600);
//    sttree->Draw("Ecal[1]>>h21", gate&&Tgate3);
//    analykit.histsave(c21, name, 1200, "Tgate3");
//
//    TCanvas *c22 = new TCanvas("c22");
//    TH2D *h22 = new TH2D("h22",name.c_str(),bins,-10000,20000000,bins,0,1600);
//    sttree->Draw("Ecal[1]:Tdiff[1]>> h22", gate, "colz");
//    string p22name = "./picture/" + name + "_ET.pdf";
//    c22->Print(p22name.c_str());
}