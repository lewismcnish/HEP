#include <TChain.h>
#include <vector>
#include <TFile.h>
#include <iostream>
#include <string>
#include <stdio.h>

TString path = "/hyy-data";

TChain* fchain = new TChain("mini");
fChain->Addfile(path+"data_A.GamGam.root");
fChain->Addfile(path+"data_B.GamGam.root");
fChain->Addfile(path+"data_C.GamGam.root");
fChain->Addfile(path+"data_D.GamGam.root");

UInt_t Photon_n = -1;

vector<float> *Photon_pt;
vector<float> *Photon_eta = 0;
vector<float> *Photon_phi = 0;
vector<float> *Photon_E = 0;
vector<bool> *Photon_isTightID = 0;


Bool_t TrigP = 0;
vector<float> *Photon_ptcone30 = 0;
vector<float> *Photon_etcone20 = 0;

fChain->SetBranchAddress("photon_n", &Photon_n);
fChain->SetBranchAddress("photon_pt", &Photon_pt);
fChain->SetBranchAddress("photon_eta", &Photon_eta);
fChain->SetBranchAddress("photon_phi", &Photon_phi);
fChain->SetBranchAddress("photon_E", &Photon_E);
fChain->SetBranchAddress("photon_isTightID", &Photon_isTightID);

fChain->SetBranchAddress("trigP", &TrigP);
fChain->SetBranchAddress("photon_ptcone30", &Photon_ptcone30);
fChain->SetBranchAddress("photon_etcone20", &Photon_etcone20);

TH1F *h_M_Hyy = new TH1F("h_M_Hyy", "Diphton invariant-mass ; M_{#gamma#gamma} [GeV] ; Events / bin",30,105,160);

h_M_Hyy->SetMarkerSize(2.0);


