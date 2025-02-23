
#include <iostream>
#include <string>
#include <stdio.h>

TFile *file = TFile::Open("~/code/HEP/cpp/data/mc_361106.Zee.1largeRjet1lep.root");
TTree *tree = (TTree*) file->Get("mini");
TTree *tree = (TTree*) file->Get("mini");
TFile *dat = TFile::Open("~/code/HEP/cpp/data/mc_361106.Zee.1largeRjet1lep.root");
TTree *tree = (TTree*) dat->Get("mini");
UInt_t lepton_n = -1;
tree->SetBranchAddress("lep_n", &lepton_n);
TCanvas *canvas = new TCanvas("Canvas","a first way to plot a variable",800,600);
TH1F *hist = new TH1F("variable","Example plot: Number of leptons; Number of leptons ; Events", 5, -0.5 , 4.5);
int nentries, nbytes;
int nentries = (Int_t)tree->GetEntries();
for (int i=0; i < nentries; i++){
    nbytes = tree->GetEntry(i);
    hist->Fill(lepton_n);}
std::cout << "Done!" <<std::endl;
hist->SetFillColor(kRed);
hist->Draw();
canvas->Draw();
