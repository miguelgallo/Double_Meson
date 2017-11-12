#include "TTree.h"
#include "TLorentzVector.h"
#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TImage.h"
#include "TAttLine.h"
#include "TLegend.h"
#include <iostream>
#include <math.h>
#include "TMath.h"
#include "TStyle.h"

using namespace std;

void DoubleMeson() {
    gStyle->SetOptStat(1111110);

    	TFile *f1 = new TFile("Dados/JpsiKKOnlyExclusiveCut2011.root","read");
    	TFile *f2 = new TFile("Dados/JpsiKKOnlyExclusiveCut2012.root","read");
    	//TFile *f1 = new TFile("~gustavo/NewTuples/DoubleMeson11.root","read");
    	//TFile *f2 = new TFile("~gustavo/NewTuples/DoubleMeson12.root","read");
    	TTree *t1 = (TTree*)f1->Get(/*"TupleXJpsikk*/"DecayTree");
	TTree *t2 = (TTree*)f2->Get(/*"TupleXJpsikk*/"DecayTree");
    
	int nBackTracks, nLongTracks, nVeloTracks;
	short Polarity;
	double muminus_PX, muminus_PY, muminus_PZ, muminus_PE, muplus_PX, muplus_PY, muplus_PZ,  muplus_PE, Jpsi_PX, Jpsi_PY, Jpsi_PZ, Jpsi_PE, Kminus_PX, Kminus_PY, Kminus_PZ, Kminus_PE, Kplus_PX, Kplus_PY, Kplus_PZ,  Kplus_PE;
	double Jpsi_M, Jpsi_PT, Phi_M, Phi_PT,  Kminus_PIDK, Kplus_PIDK, chi_PT, chi_M, chi_ENDVERTEX_X, chi_ENDVERTEX_Y, chi_ENDVERTEX_Z, chi_ENDVERTEX_CHI2;
	double Jpsi_ENDVERTEX_X, Jpsi_ENDVERTEX_Y, Jpsi_ENDVERTEX_Z, Jpsi_ENDVERTEX_CHI2, Phi_ENDVERTEX_X, Phi_ENDVERTEX_Y, Phi_ENDVERTEX_Z, Phi_ENDVERTEX_CHI2;
	
	t1->SetBranchAddress("Jpsi_M",&Jpsi_M);							t2->SetBranchAddress("Jpsi_M",&Jpsi_M);
	t1->SetBranchAddress("Jpsi_PT",&Jpsi_PT);						t2->SetBranchAddress("Jpsi_PT",&Jpsi_PT);
	t1->SetBranchAddress("Jpsi_PX",&Jpsi_PX);						t2->SetBranchAddress("Jpsi_PX",&Jpsi_PX);
	t1->SetBranchAddress("Jpsi_PY",&Jpsi_PY);						t2->SetBranchAddress("Jpsi_PY",&Jpsi_PY);
	t1->SetBranchAddress("Jpsi_PZ",&Jpsi_PZ);						t2->SetBranchAddress("Jpsi_PZ",&Jpsi_PZ);
	t1->SetBranchAddress("Jpsi_PE",&Jpsi_PE);						t2->SetBranchAddress("Jpsi_PE",&Jpsi_PE);
	t1->SetBranchAddress("Phi_M",&Phi_M);							t2->SetBranchAddress("Phi_M",&Phi_M);
	t1->SetBranchAddress("Phi_PT",&Phi_PT);							t2->SetBranchAddress("Phi_PT",&Phi_PT);
	t1->SetBranchAddress("Kminus_PIDK",&Kminus_PIDK);					t2->SetBranchAddress("Kminus_PIDK",&Kminus_PIDK);
	t1->SetBranchAddress("Kminus_PX",&Kminus_PX);						t2->SetBranchAddress("Kminus_PX",&Kminus_PX);
	t1->SetBranchAddress("Kminus_PY",&Kminus_PY);						t2->SetBranchAddress("Kminus_PY",&Kminus_PY);
	t1->SetBranchAddress("Kminus_PZ",&Kminus_PZ);						t2->SetBranchAddress("Kminus_PZ",&Kminus_PZ);			
	t1->SetBranchAddress("Kminus_PE",&Kminus_PE);						t2->SetBranchAddress("Kminus_PE",&Kminus_PE);			
	t1->SetBranchAddress("Kplus_PIDK",&Kplus_PIDK);						t2->SetBranchAddress("Kplus_PIDK",&Kplus_PIDK);
	t1->SetBranchAddress("Kplus_PX",&Kplus_PX);						t2->SetBranchAddress("Kplus_PX",&Kplus_PX);
	t1->SetBranchAddress("Kplus_PY",&Kplus_PY);						t2->SetBranchAddress("Kplus_PY",&Kplus_PY);
	t1->SetBranchAddress("Kplus_PZ",&Kplus_PZ);						t2->SetBranchAddress("Kplus_PZ",&Kplus_PZ);
	t1->SetBranchAddress("Kplus_PE",&Kplus_PE);						t2->SetBranchAddress("Kplus_PE",&Kplus_PE);
	t1->SetBranchAddress("muminus_PX",&muminus_PX);						t2->SetBranchAddress("muminus_PX",&muminus_PX);
	t1->SetBranchAddress("muminus_PY",&muminus_PY);						t2->SetBranchAddress("muminus_PY",&muminus_PY);
	t1->SetBranchAddress("muminus_PZ",&muminus_PZ);						t2->SetBranchAddress("muminus_PZ",&muminus_PZ);			
	t1->SetBranchAddress("muminus_PE",&muminus_PE);						t2->SetBranchAddress("muminus_PE",&muminus_PE);			
	t1->SetBranchAddress("muplus_PX",&muplus_PX);						t2->SetBranchAddress("muplus_PX",&muplus_PX);
	t1->SetBranchAddress("muplus_PY",&muplus_PY);						t2->SetBranchAddress("muplus_PY",&muplus_PY);
	t1->SetBranchAddress("muplus_PZ",&muplus_PZ);						t2->SetBranchAddress("muplus_PZ",&muplus_PZ);
	t1->SetBranchAddress("muplus_PE",&muplus_PE);						t2->SetBranchAddress("muplus_PE",&muplus_PE);
	t1->SetBranchAddress("nBackTracks",&nBackTracks);					t2->SetBranchAddress("nBackTracks",&nBackTracks);
	t1->SetBranchAddress("nVeloTracks",&nVeloTracks);					t2->SetBranchAddress("nVeloTracks",&nVeloTracks);
	t1->SetBranchAddress("nLongTracks",&nLongTracks);					t2->SetBranchAddress("nLongTracks",&nLongTracks);
	t1->SetBranchAddress("chi_PT",&chi_PT);							t2->SetBranchAddress("chi_PT",&chi_PT);
	t1->SetBranchAddress("chi_M",&chi_M);							t2->SetBranchAddress("chi_M",&chi_M);
	t1->SetBranchAddress("chi_ENDVERTEX_X",&chi_ENDVERTEX_X);				t2->SetBranchAddress("chi_ENDVERTEX_X",&chi_ENDVERTEX_X);
	t1->SetBranchAddress("chi_ENDVERTEX_Y",&chi_ENDVERTEX_Y);				t2->SetBranchAddress("chi_ENDVERTEX_Y",&chi_ENDVERTEX_Y);
	t1->SetBranchAddress("chi_ENDVERTEX_Z",&chi_ENDVERTEX_Z);				t2->SetBranchAddress("chi_ENDVERTEX_Z",&chi_ENDVERTEX_Z);
	t1->SetBranchAddress("chi_ENDVERTEX_CHI2",&chi_ENDVERTEX_CHI2);				t2->SetBranchAddress("chi_ENDVERTEX_CHI2",&chi_ENDVERTEX_CHI2);
	t1->SetBranchAddress("Jpsi_ENDVERTEX_X",&Jpsi_ENDVERTEX_X);				t2->SetBranchAddress("Jpsi_ENDVERTEX_X",&Jpsi_ENDVERTEX_X);
	t1->SetBranchAddress("Jpsi_ENDVERTEX_Y",&Jpsi_ENDVERTEX_Y);				t2->SetBranchAddress("Jpsi_ENDVERTEX_Y",&Jpsi_ENDVERTEX_Y);
	t1->SetBranchAddress("Jpsi_ENDVERTEX_Z",&Jpsi_ENDVERTEX_Z);				t2->SetBranchAddress("Jpsi_ENDVERTEX_Z",&Jpsi_ENDVERTEX_Z);
	t1->SetBranchAddress("Jpsi_ENDVERTEX_CHI2",&Jpsi_ENDVERTEX_CHI2);			t2->SetBranchAddress("Jpsi_ENDVERTEX_CHI2",&Jpsi_ENDVERTEX_CHI2);
	t1->SetBranchAddress("Phi_ENDVERTEX_X",&Phi_ENDVERTEX_X);				t2->SetBranchAddress("Phi_ENDVERTEX_X",&Phi_ENDVERTEX_X);
	t1->SetBranchAddress("Phi_ENDVERTEX_Y",&Phi_ENDVERTEX_Y);				t2->SetBranchAddress("Phi_ENDVERTEX_Y",&Phi_ENDVERTEX_Y);
	t1->SetBranchAddress("Phi_ENDVERTEX_Z",&Phi_ENDVERTEX_Z);				t2->SetBranchAddress("Phi_ENDVERTEX_Z",&Phi_ENDVERTEX_Z);
	t1->SetBranchAddress("Phi_ENDVERTEX_CHI2",&Phi_ENDVERTEX_CHI2);				t2->SetBranchAddress("Phi_ENDVERTEX_CHI2",&Phi_ENDVERTEX_CHI2);
	t1->SetBranchAddress("Polarity",&Polarity);						t2->SetBranchAddress("Polarity",&Polarity);
	
	TFile *f3 = new TFile("Dados/DoubleMesonPIDK.root","recreate");
	
	//2011
	TH1D *h01 = new TH1D("h01","J/#psi Mass", 20,3036, 3156);
	TH1D *h02_35 = new TH1D("h02_35","#phi(1005-1035) Mass", 20, 1005, 1035);
	TH1D *h02_200 = new TH1D("h02_200","#phi(1005-1200) Mass", 20, 1005, 1200);
	TH1D *h03 = new TH1D("h03","J/#psi#phi(1005-1035) P_{T}^{2}",20,0 ,10000000);
	TH1D *h03_psi = new TH1D("h03_psi","J/#psi#pi#pi P_{T}^{2}",20,0 ,10000000);
	TH1D *h04 = new TH1D("h04","J/#psi#phi(990-1005) P_{T}^{2}",20,0 ,10000000);
	TH1D *h05 = new TH1D("h05","J/#psi#phi(1035-1050) P_{T}^{2}",20,0 ,10000000);
	TH1D *h06 = new TH1D("h06","Average of J/#psi#phi P_{T}^{2}", 20, 0, 10000000);
	TH1D *h07 = new TH1D("h07","J/#psi#phi P_{T}^{2}", 20, 0, 10000000);
	TH1D *h08 = new TH1D("h08","J/#psi#phi(1005-1035) Mass", 20, 4000, 7000);   
	TH1D *h08_gt4 = new TH1D("h08_gt4","J/#psi#phi(1005-1035) Mass", 20, 4000, 7000);   
	TH1D *h08_gt6 = new TH1D("h08_gt6","J/#psi#phi(1005-1035) Mass", 20, 4000, 7000);   
	TH1D *h08_KK = new TH1D("h08_KK","J/#psiKK Mass", 50, 4000, 7000);   
	TH1D *h08_pipi = new TH1D("h08_pipi","J/#psi#pi#pi Mass", 50, 3400, 7000);   
	TH1D *h08_pp = new TH1D("h08_pp","J/#psi#pi#pi_zoom Mass", 50, 3400, 4000);   
	TH1D *h09 = new TH1D("h09","J/#psi P_{T}",20, 0, 4000);
	TH1D *h10 = new TH1D("h10","#phi(1005-1035) P_{T}",20, 0, 3000);
	TH1D *h11 = new TH1D("h11","#phi(990-1005) P_{T}",20, 0, 3000);
	TH1D *h12 = new TH1D("h12","#phi(1035-1050) P_{T}",20, 0, 3000);
	TH1D *h13 = new TH1D("h13","Average of #phi P_{T}",20, 0, 3000);
	TH1D *h14 = new TH1D("h14","#phi P_{T}",20, 0, 3000);
	TH2D *h15 = new TH2D("h15","#phi P_{T} x Mass", 20, 1005, 1035, 20, 0, 3000);   	
	TH2D *h16 = new TH2D("h16","J/#psi P_{T} x Mass", 20, 3036, 3156, 20, 0, 4000);   	 
	TH2D *h17 = new TH2D("h17","J/#psi#phi P_{T}^{2} x Mass", 100, 4000, 7000, 100, 0, 15000000);  
	TH2D *h18 = new TH2D("h18","J/#psi x #phi Mass", 200, 500, 1500, 200, 2500, 3500);
	TH1D *h19 = new TH1D("h19","J/#psi P_{T}^{2}",50, 0, 10000000);
	TH1D *h20 = new TH1D("h20","#phi (1005-1035) P_{T}^{2}",100, 0, 3000000);
	TH1D *h21 = new TH1D("h21","#phi (990-1005) P_{T}^{2}",100, 0, 3000000);
	TH1D *h22 = new TH1D("h22","#phi (1035-1050) P_{T}^{2}",100, 0, 3000000);
	TH1D *h23 = new TH1D("h23","Average of #phi P_{T}^{2}",100, 0, 3000000);
	TH1D *h24 = new TH1D("h24","#phi P_{T}^{2}",100, 0, 3000000);
	TH2D *h25 = new TH2D("h25","J/#psi x #phi (1005-1035) P_{T}^{2}", 100, 0, 5000000, 100, 0, 10000000);
	TH2D *h26 = new TH2D("h26","J/#psi x #phi (990-1005) P_{T}^{2}", 100, 0, 5000000, 100, 0, 10000000);
	TH2D *h27 = new TH2D("h27","J/#psi x #phi (1035-1050) P_{T}^{2}", 100, 0, 5000000, 100, 0, 10000000);
	TH2D *h28 = new TH2D("h28","Average of J/#psi x #phi P_{T}^{2}", 100, 0, 5000000, 100, 0, 10000000);
	TH2D *h29 = new TH2D("h29","J/#psi x #phi P_{T}^{2}", 100, 0, 5000000, 100, 0, 10000000);
	TH1D *h44 = new TH1D("h44","#pi#pi Mass", 50, 200, 2000);
	TH1D *h44_s_psi = new TH1D("h44_s_psi","#pi#pi Mass without #psi(2S)", 50, 200, 2000);
	TH1D *h45_KK = new TH1D("h45_KK","#Delta#phi J/#psi, KK", 20, 0, 1);
	TH1D *h45_phi = new TH1D("h45_phi","#Delta#phi J/#psi, #phi", 20, 0, 1);
	TH1D *h45_rho = new TH1D("h45_rho","#Delta#phi J/#psi, #rho", 20, 0, 1);
	TH1D *h45_psi = new TH1D("h45_psi","#Delta#phi J/#psi, #pi#pi", 20, 0, 1);
	TH1D *h46_phi = new TH1D("h46_phi","J/#psi#phi y", 50, 2, 5);
	TH1D *h46_rho = new TH1D("h46_rho","J/#psi#rho y", 50, 2, 5);
	TH1D *h46_psi = new TH1D("h46_psi","#psi(2S) y", 50, 2, 5);
	TH1D *h47_phi = new TH1D("h47_phi","J/#psi#phi #eta", 50, 2, 8);
	TH1D *h47_muon1 = new TH1D("h47_muon1","#mu^{-} #eta", 50, 1.5, 5.5);
	TH1D *h47_muon2 = new TH1D("h47_muon2","#mu^{+} #eta", 50, 1.5, 5.5);
	TH1D *h47_rho = new TH1D("h47_rho","J/#psi#rho #eta", 50, 2, 8);
	TH1D *h47_pion1 = new TH1D("h47_pion1","#pi^{-} #eta", 50, 1.5, 5.5);
	TH1D *h47_pion2 = new TH1D("h47_pion2","#pi^{+} #eta", 50, 1.5, 5.5);
	TH1D *h47_psi = new TH1D("h47_psi","#psi(2S) #eta", 50, 2, 8);
	
	TH1D *t01 = new TH1D("t01","J/#psi Mass", 20,3036, 3156);
	TH1D *t02_35 = new TH1D("t02_35","#phi(1005-1035) Mass", 20, 1005, 1035);
	TH1D *t02_200 = new TH1D("t02_200","#phi(1005-1200) Mass", 20, 1005, 1200);
	TH1D *t03 = new TH1D("t03","J/#psi#phi(1005-1035) P_{T}^{2}",20,0 ,10000000);
	TH1D *t03_psi = new TH1D("t03_psi","J/#psi#pi#pi P_{T}^{2}",20,0 ,10000000);
	TH1D *t04 = new TH1D("t04","J/#psi#phi(990-1005) P_{T}^{2}",20,0 ,10000000);
	TH1D *t05 = new TH1D("t05","J/#psi#phi(1035-1050) P_{T}^{2}",20,0 ,10000000);
	TH1D *t06 = new TH1D("t06","Average of J/#psi#phi P_{T}^{2}", 20, 0, 10000000);
	TH1D *t07 = new TH1D("t07","J/#psi#phi P_{T}^{2}", 20, 0, 10000000);
	TH1D *t08 = new TH1D("t08","J/#psi#phi(1005-1035) Mass", 20, 4000, 7000);   
	TH1D *t08_gt4 = new TH1D("t08_gt4","J/#psi#phi(1005-1035) Mass", 20, 4000, 7000);   
	TH1D *t08_gt6 = new TH1D("t08_gt6","J/#psi#phi(1005-1035) Mass", 20, 4000, 7000);   
	TH1D *t08_KK = new TH1D("t08_KK","J/#psiKK Mass", 50, 4000, 7000);   
	TH1D *t08_pipi = new TH1D("t08_pipi","J/#psi#pi#pi Mass", 50, 3400, 7000);   
	TH1D *t08_pp = new TH1D("t08_pp","J/#psi#pi#pi_zoom Mass", 50, 3400, 4000);   
	TH1D *t09 = new TH1D("t09","J/#psi P_{T}",20, 0, 4000);
	TH1D *t10 = new TH1D("t10","#phi(1005-1035) P_{T}",20, 0, 3000);
	TH1D *t11 = new TH1D("t11","#phi(990-1005) P_{T}",20, 0, 3000);
	TH1D *t12 = new TH1D("t12","#phi(1035-1050) P_{T}",20, 0, 3000);
	TH1D *t13 = new TH1D("t13","Average of #phi P_{T}",20, 0, 3000);
	TH1D *t14 = new TH1D("t14","#phi P_{T}",20, 0, 3000);
	TH2D *t15 = new TH2D("t15","#phi P_{T} x Mass", 20, 1005, 1035, 20, 0, 3000);   	
	TH2D *t16 = new TH2D("t16","J/#psi P_{T} x Mass", 20, 3036, 3156, 20, 0, 4000);   	 
	TH2D *t17 = new TH2D("t17","J/#psi#phi P_{T}^{2} x Mass", 100, 4000, 7000, 100, 0, 15000000);  
	TH2D *t18 = new TH2D("t18","J/#psi x #phi Mass", 200, 500, 1500, 200, 2500, 3500);
	TH1D *t19 = new TH1D("t19","J/#psi P_{T}^{2}",50, 0, 10000000);
	TH1D *t20 = new TH1D("t20","#phi (1005-1035) P_{T}^{2}",100, 0, 3000000);
	TH1D *t21 = new TH1D("t21","#phi (990-1005) P_{T}^{2}",100, 0, 3000000);
	TH1D *t22 = new TH1D("t22","#phi (1035-1050) P_{T}^{2}",100, 0, 3000000);
	TH1D *t23 = new TH1D("t23","Average of #phi P_{T}^{2}",100, 0, 3000000);
	TH1D *t24 = new TH1D("t24","#phi P_{T}^{2}",100, 0, 3000000);
	TH2D *t25 = new TH2D("t25","J/#psi x #phi (1005-1035) P_{T}^{2}", 100, 0, 5000000, 100, 0, 10000000);
	TH2D *t26 = new TH2D("t26","J/#psi x #phi (990-1005) P_{T}^{2}", 100, 0, 5000000, 100, 0, 10000000);
	TH2D *t27 = new TH2D("t27","J/#psi x #phi (1035-1050) P_{T}^{2}", 100, 0, 5000000, 100, 0, 10000000);
	TH2D *t28 = new TH2D("t28","Average of J/#psi x #phi P_{T}^{2}", 100, 0, 5000000, 100, 0, 10000000);
	TH2D *t29 = new TH2D("t29","J/#psi x #phi P_{T}^{2}", 100, 0, 5000000, 100, 0, 10000000);
	TH1D *t44 = new TH1D("t44","#pi#pi Mass", 50, 200, 2000);
	TH1D *t44_s_psi = new TH1D("t44_s_psi","#pi#pi Mass without #psi(2S)", 50, 200, 2000);
	TH1D *t45_KK = new TH1D("t45_KK","#Delta#phi J/#psi, KK", 20, 0, 1);
	TH1D *t45_phi = new TH1D("t45_phi","#Delta#phi J/#psi, #phi", 20, 0, 1);
	TH1D *t45_rho = new TH1D("t45_rho","#Delta#phi J/#psi, #rho", 20, 0, 1);
	TH1D *t45_psi = new TH1D("t45_psi","#Delta#phi J/#psi, #pi#pi", 20, 0, 1);
	TH1D *t46_phi = new TH1D("t46_phi","J/#psi#phi y", 50, 2, 5);
	TH1D *t46_rho = new TH1D("t46_rho","J/#psi#rho y", 50, 2, 5);
	TH1D *t46_psi = new TH1D("t46_psi","#psi(2S) y", 50, 2, 5);
	TH1D *t47_phi = new TH1D("t47_phi","J/#psi#phi #eta", 50, 2, 8);
	TH1D *t47_muon1 = new TH1D("t47_muon1","#mu^{-} #eta", 50, 1.5, 5.5);
	TH1D *t47_muon2 = new TH1D("t47_muon2","#mu^{+} #eta", 50, 1.5, 5.5);
	TH1D *t47_rho = new TH1D("t47_rho","J/#psi#rho #eta", 50, 2, 8);
	TH1D *t47_pion1 = new TH1D("t47_pion1","#pi^{-} #eta", 50, 1.5, 5.5);
	TH1D *t47_pion2 = new TH1D("t47_pion2","#pi^{+} #eta", 50, 1.5, 5.5);
	TH1D *t47_psi = new TH1D("t47_psi","#psi(2S) #eta", 50, 2, 8);

	TLorentzVector phi_11, phi_12, pion1_11, pion2_11, muon1_11, muon2_11, kaon1_11, kaon2_11, rho_11, pion1_12, pion2_12, muon1_12, muon2_12, kaon1_12, kaon2_12, rho_12, jpsi_11, jpsi_12, jpsipipi_11, jpsipipi_12, jpsiphi_11, jpsiphi_12;

	int nentries = (Int_t)t1->GetEntries();
	int mentries = (Int_t)t2->GetEntries();
	double Eminus_K11=0,            Eminus_K12=0;
	double Eplus_K11=0,             Eplus_K12=0;
	double EXCdown11=0,             EXCdown12=0;
	double EXCup11=0,               EXCup12=0;
	double PIDKdown11=0,            PIDKdown12=0;
	double PIDKup11=0,              PIDKup12=0;
	double MCdown11=0,              MCdown12=0;
	double MCup11=0,                MCup12=0;
	double MC_PIDKdown11=0,         MC_PIDKdown12=0;
	double MC_PIDKup11=0,           MC_PIDKup12=0;
	double ETAdown11=0,             ETAdown12=0;
	double ETAup11=0,               ETAup12=0;
	double ETA_MC_PIDKdown11=0,     ETA_MC_PIDKdown12=0;
	double ETA_MC_PIDKup11=0,       ETA_MC_PIDKup12=0;
	double pion_mass=139.57018;
	for (int i=0; i<nentries; i++) {
		t1->GetEntry(i);
		if(Polarity == -1) EXCdown11++;
		if(Polarity == 1) EXCup11++;
		Eminus_K11 = sqrt(pow(pion_mass,2)+pow(Kminus_PX,2)+pow(Kminus_PY,2)+pow(Kminus_PZ,2));
		pion1_11.SetPxPyPzE(Kminus_PX,Kminus_PY,Kminus_PZ,Eminus_K11);
		kaon1_11.SetPxPyPzE(Kminus_PX,Kminus_PY,Kminus_PZ,Kminus_PE);
		muon1_11.SetPxPyPzE(muminus_PX,muminus_PY,muminus_PZ,muminus_PE);
		Eplus_K11 = sqrt(pow(pion_mass,2)+pow(Kplus_PX,2)+pow(Kplus_PY,2)+pow(Kplus_PZ,2));
		pion2_11.SetPxPyPzE(Kplus_PX,Kplus_PY,Kplus_PZ,Eplus_K11);
		kaon2_11.SetPxPyPzE(Kplus_PX,Kplus_PY,Kplus_PZ,Kplus_PE);
		muon2_11.SetPxPyPzE(muplus_PX,muplus_PY,muplus_PZ,muplus_PE);
		phi_11 = kaon1_11+kaon2_11;
		rho_11 = pion1_11+pion2_11;
		jpsi_11.SetPxPyPzE(Jpsi_PX,Jpsi_PY,Jpsi_PZ,Jpsi_PE);
		jpsiphi_11 = jpsi_11+kaon1_11+kaon2_11;
		jpsipipi_11 = jpsi_11+pion1_11+pion2_11;
		if (Kminus_PIDK > 0 && Kplus_PIDK > 0) {
			if(Polarity == -1) PIDKdown11++;
			if(Polarity == 1) PIDKup11++;
		}
		if (Jpsi_M > 3036 && Jpsi_M < 3156 && Phi_M > 1005 && Phi_M < 1035) {
			if(Polarity == -1) MCdown11++;
			if(Polarity == 1) MCup11++;
		}
		if (Jpsi_M > 3036 && Jpsi_M < 3156 && Phi_M > 1005 && Phi_M < 1035 && Kminus_PIDK > 0 && Kplus_PIDK > 0) {
			if(Polarity == -1) MC_PIDKdown11++;
			if(Polarity == 1) MC_PIDKup11++;
		}
		if (muon1_11.Eta() >= 2 && muon1_11.Eta() <= 4.5) {
		if (muon2_11.Eta() >= 2 && muon2_11.Eta() <=4.5) {
		if (pion1_11.Eta() >= 2 && pion1_11.Eta() <= 4.5) {
		if (pion2_11.Eta() >= 2 && pion2_11.Eta() <= 4.5) {
		if (kaon1_11.Eta() >= 2 && kaon1_11.Eta() <= 4.5) {
		if (kaon2_11.Eta() >= 2 && kaon2_11.Eta() <= 4.5) {   
		if(Polarity == -1) ETAdown11++;
		if(Polarity == 1) ETAup11++;
		if(jpsipipi_11.M() > 3600 && jpsipipi_11.M() < 3800) {
			h45_psi->Fill(abs(jpsi_11.DeltaPhi(rho_11))/3.14159265358979323846);
			h46_psi->Fill(jpsipipi_11.Rapidity());
			h03_psi->Fill(jpsipipi_11.Pt()*jpsipipi_11.Pt());
			
		}
			if (Kminus_PIDK > 0 && Kplus_PIDK > 0) {
				if (Jpsi_M > 3036 && Jpsi_M < 3156) { 
					h08_KK->Fill(chi_M);
					h08_pipi->Fill(jpsipipi_11.M());
					h08_pp->Fill(jpsipipi_11.M());
					h45_KK->Fill(abs(jpsi_11.DeltaPhi(phi_11))/3.14159265358979323846);
					h47_muon1->Fill(muon1_11.Eta());
					h47_muon2->Fill(muon2_11.Eta());
					h44->Fill(rho_11.M());
					if(jpsipipi_11.M() < 3600 || jpsipipi_11.M() > 3800) h44_s_psi->Fill(rho_11.M());
					if (rho_11.M() > 675 && rho_11.M() < 875) {
						h45_rho->Fill(abs(jpsi_11.DeltaPhi(rho_11))/3.14159265358979323846);
						h46_rho->Fill(jpsipipi_11.Rapidity());
						h47_rho->Fill(jpsipipi_11.Eta());
						h47_pion1->Fill(pion1_11.Eta());
						h47_pion2->Fill(pion2_11.Eta());
					}
					if (Phi_M > 1005 && Phi_M < 1035) {
						if(Polarity == -1) ETA_MC_PIDKdown11++;
						if(Polarity == 1) ETA_MC_PIDKup11++;
						if(nBackTracks == 0 && nVeloTracks > 4) h08_gt4->Fill(chi_M);
						if(nBackTracks == 0 && nVeloTracks > 6) h08_gt6->Fill(chi_M);
						h01->Fill(Jpsi_M);
						h02_35->Fill(Phi_M);
						h03->Fill(chi_PT*chi_PT);
						if(nBackTracks == 0 && nVeloTracks == 4) h08->Fill(chi_M);
						h09->Fill(Jpsi_PT);
						h10->Fill(Phi_PT);
						h15->Fill(Phi_M,Phi_PT); 
						h16->Fill(Jpsi_M, Jpsi_PT);
						h17->Fill(chi_M,chi_PT*chi_PT);
						h18->Fill(Phi_M, Jpsi_M);
						h19->Fill(Jpsi_PT*Jpsi_PT);
						h20->Fill(Phi_PT*Phi_PT);
						h25->Fill(Phi_PT*Phi_PT, Jpsi_PT*Jpsi_PT);
						h45_phi->Fill(abs(jpsi_11.DeltaPhi(phi_11))/3.14159265358979323846);
						h46_phi->Fill(jpsiphi_11.Rapidity());
						h47_phi->Fill(jpsiphi_11.Eta());
					}
					if (Phi_M > 990 && Phi_M <= 1005) { 
						h04->Fill(chi_PT*chi_PT);
						h11->Fill(Phi_PT);
						h21->Fill(Phi_PT*Phi_PT);
						h26->Fill(Phi_PT*Phi_PT, Jpsi_PT*Jpsi_PT);

					}
					if (Phi_M >= 1035 && Phi_M < 1050) { 
						h05->Fill(chi_PT*chi_PT);
						h12->Fill(Phi_PT);
						h22->Fill(Phi_PT*Phi_PT);
						h27->Fill(Phi_PT*Phi_PT, Jpsi_PT*Jpsi_PT);

					}
					if (Phi_M > 1005 && Phi_M < 1200) h02_200->Fill(Phi_M);
				}	
			}
		}
		}
		}
		}
		}
		}
		h06->Add(h04,h05,0.5,0.5);
		h07->Add(h03,h06,1,-1);
		h13->Add(h11,h12,0.5,0.5);
		h14->Add(h10,h13,1,-1);	
		h23->Add(h21,h22,0.5,0.5);
		h24->Add(h20,h23,1,-1);	
		h28->Add(h26,h27,0.5,0.5);
		h29->Add(h25,h28,1,-1);

	}
		cout << "EXC (Down) 2011: " << EXCdown11 << endl;
		cout << "EXC (Up) 2011: " << EXCup11 << endl;
		cout << "PIDK (Down) 2011: " << PIDKdown11 << endl;
		cout << "PIDK (Up) 2011: " << PIDKup11 << endl;
		cout << "MC (Down) 2011: " << MCdown11 << endl;
		cout << "MC (Up) 2011: " << MCup11 << endl;
		cout << "MC+PIDK (Down) 2011: " << MC_PIDKdown11 << endl;
		cout << "MC+PIDK (Up) 2011: " << MC_PIDKup11 << endl;
		cout << "ETA (Down) 2011: " << ETAdown11 << endl;
		cout << "ETA (Up) 2011: " << ETAup11 << endl;
		cout << "ETA+MC+PIDK (Down) 2011: " << ETA_MC_PIDKdown11 << endl;
		cout << "ETA+MC+PIDK (Up) 2011: " << ETA_MC_PIDKup11 << endl;
	
	for (int j=0; j<mentries; j++) {
		t2->GetEntry(j);
		if(Polarity == -1) EXCdown12++;
		if(Polarity == 1) EXCup12++;
		Eminus_K12 = sqrt(pow(pion_mass,2)+pow(Kminus_PX,2)+pow(Kminus_PY,2)+pow(Kminus_PZ,2));
		pion1_12.SetPxPyPzE(Kminus_PX,Kminus_PY,Kminus_PZ,Eminus_K12);
		kaon1_12.SetPxPyPzE(Kminus_PX,Kminus_PY,Kminus_PZ,Kminus_PE);
		muon1_12.SetPxPyPzE(muminus_PX,muminus_PY,muminus_PZ,muminus_PE);
		Eplus_K12 = sqrt(pow(pion_mass,2)+pow(Kplus_PX,2)+pow(Kplus_PY,2)+pow(Kplus_PZ,2));
		pion2_12.SetPxPyPzE(Kplus_PX,Kplus_PY,Kplus_PZ,Eplus_K12);
		kaon2_12.SetPxPyPzE(Kplus_PX,Kplus_PY,Kplus_PZ,Kplus_PE);
		muon2_12.SetPxPyPzE(muplus_PX,muplus_PY,muplus_PZ,muplus_PE);	
		phi_12 = kaon1_12+kaon2_12;
		rho_12 = pion1_12+pion2_12;
		jpsi_12.SetPxPyPzE(Jpsi_PX,Jpsi_PY,Jpsi_PZ,Jpsi_PE);
		jpsiphi_12 = jpsi_12+kaon1_12+kaon2_12;
		jpsipipi_12 = jpsi_12+pion1_12+pion2_12;
		if (Kminus_PIDK > 0 && Kplus_PIDK > 0) {
			if(Polarity == -1) PIDKdown12++;
			if(Polarity == 1) PIDKup12++;
		}
		if (Jpsi_M > 3036 && Jpsi_M < 3156 && Phi_M > 1005 && Phi_M < 1035) {
			if(Polarity == -1) MCdown12++;
			if(Polarity == 1) MCup12++;
		}
		if (Jpsi_M > 3036 && Jpsi_M < 3156 && Phi_M > 1005 && Phi_M < 1035 && Kminus_PIDK > 0 && Kplus_PIDK > 0) {
			if(Polarity == -1) MC_PIDKdown12++;
			if(Polarity == 1) MC_PIDKup12++;
		}
		if (muon1_12.Eta() >= 2 && muon1_12.Eta() <= 4.5) {
		if (muon2_12.Eta() >= 2 && muon2_12.Eta() <=4.5) {
		if (pion1_12.Eta() >= 2 && pion1_12.Eta() <= 4.5) {
		if (pion2_12.Eta() >= 2 && pion2_12.Eta() <= 4.5) {
		if (kaon1_12.Eta() >= 2 && kaon1_12.Eta() <= 4.5) {
		if (kaon2_12.Eta() >= 2 && kaon2_12.Eta() <= 4.5) {   
		if(Polarity == -1) ETAdown12++;
		if(Polarity == 1) ETAup12++;
		if(jpsipipi_12.M() < 3600 || jpsipipi_12.M() > 3800) t44_s_psi->Fill(rho_12.M());
		if(jpsipipi_12.M() > 3600 && jpsipipi_12.M() < 3800) {
			t45_psi->Fill(abs(jpsi_12.DeltaPhi(rho_12))/3.14159265358979323846);
			t46_psi->Fill(jpsipipi_12.Rapidity());
			t47_psi->Fill(jpsipipi_12.Eta());
			t03_psi->Fill(jpsipipi_12.Pt()*jpsipipi_12.Pt());
		}
			if (Kminus_PIDK > 0 && Kplus_PIDK > 0) {
				if (Jpsi_M > 3036 && Jpsi_M < 3156) { 
					t08_KK->Fill(chi_M);
					t08_pipi->Fill(jpsipipi_12.M());
					t08_pp->Fill(jpsipipi_12.M());
					t45_KK->Fill(abs(jpsi_12.DeltaPhi(phi_12))/3.14159265358979323846);
					t47_muon1->Fill(muon1_12.Eta());
					t47_muon2->Fill(muon2_12.Eta());
					t44->Fill(rho_12.M());
					if (rho_12.M() > 675 && rho_12.M() < 875) {
						t45_rho->Fill(abs(jpsi_12.DeltaPhi(rho_12))/3.14159265358979323846);
						t46_rho->Fill(jpsipipi_12.Rapidity());
						t47_rho->Fill(jpsipipi_12.Eta());
						t47_pion1->Fill(pion1_12.Eta());
						t47_pion2->Fill(pion2_12.Eta());
					}
					if (Phi_M > 1005 && Phi_M < 1035) {
						if(Polarity == -1) ETA_MC_PIDKdown12++;
						if(Polarity == 1) ETA_MC_PIDKup12++;
						if(nBackTracks == 0 && nVeloTracks > 4) t08_gt4->Fill(chi_M);
						if(nBackTracks == 0 && nVeloTracks > 6) t08_gt6->Fill(chi_M);
						t01->Fill(Jpsi_M);
						t02_35->Fill(Phi_M);
						t03->Fill(chi_PT*chi_PT);
						if(nBackTracks == 0 && nVeloTracks == 4) t08->Fill(chi_M);
						t09->Fill(Jpsi_PT);
						t10->Fill(Phi_PT);
						t15->Fill(Phi_M,Phi_PT); 
						t16->Fill(Jpsi_M, Jpsi_PT);
						t17->Fill(chi_M,chi_PT*chi_PT);
						t18->Fill(Phi_M, Jpsi_M);
						t19->Fill(Jpsi_PT*Jpsi_PT);
						t20->Fill(Phi_PT*Phi_PT);
						t25->Fill(Phi_PT*Phi_PT, Jpsi_PT*Jpsi_PT);
						t45_phi->Fill(abs(jpsi_12.DeltaPhi(phi_12))/3.14159265358979323846);
						t46_phi->Fill(jpsiphi_12.Rapidity());
						t47_phi->Fill(jpsiphi_12.Eta());
					}
					if (Phi_M > 990 && Phi_M <= 1005) { 
						t04->Fill(chi_PT*chi_PT);
						t11->Fill(Phi_PT);
						t21->Fill(Phi_PT*Phi_PT);
						t26->Fill(Phi_PT*Phi_PT, Jpsi_PT*Jpsi_PT);

					}
					if (Phi_M >= 1035 && Phi_M < 1050) { 
						t05->Fill(chi_PT*chi_PT);
						t12->Fill(Phi_PT);
						t22->Fill(Phi_PT*Phi_PT);
						t27->Fill(Phi_PT*Phi_PT, Jpsi_PT*Jpsi_PT);

					}
					if (Phi_M > 1005 && Phi_M < 1200) t02_200->Fill(Phi_M);
				}	
			}
		}
		}
		}
		}
		}
		}
		t06->Add(t04,t05,0.5,0.5);
		t07->Add(t03,t06,1,-1);
		t13->Add(t11,t12,0.5,0.5);
		t14->Add(t10,t13,1,-1);	
		t23->Add(t21,t22,0.5,0.5);
		t24->Add(t20,t23,1,-1);	
		t28->Add(t26,t27,0.5,0.5);
		t29->Add(t25,t28,1,-1);
		

	}
		cout << "EXC (Down) 2012: " << EXCdown12 << endl;
		cout << "EXC (Up) 2012: " << EXCup12 << endl;
		cout << "PIDK (Down) 2012: " << PIDKdown12 << endl;
		cout << "PIDK (Up) 2012: " << PIDKup12 << endl;
		cout << "MC (Down) 2012: " << MCdown12 << endl;
		cout << "MC (Up) 2012: " << MCup12 << endl;
		cout << "MC+PIDK (Down) 2012: " << MC_PIDKdown12 << endl;
		cout << "MC+PIDK (Up) 2012: " << MC_PIDKup12 << endl;
		cout << "ETA (Down) 2012: " << ETAdown12 << endl;
		cout << "ETA (Up) 2012: " << ETAup12 << endl;
		cout << "ETA+MC+PIDK (Down) 2012: " << ETA_MC_PIDKdown12 << endl;
		cout << "ETA+MC+PIDK (Up) 2012: " << ETA_MC_PIDKup12 << endl;
	
	h01->GetXaxis()->SetTitle("M(#mu#mu) [MeV]");				h01->GetYaxis()->SetTitle("Events/(6)");			
	h02_35->GetXaxis()->SetTitle("M(KK) [MeV]");				h02_35->GetYaxis()->SetTitle("Events/(1.5)");
	h02_200->GetXaxis()->SetTitle("M(KK) [MeV]");				h02_200->GetYaxis()->SetTitle("Events/(9.75)");
	h03->GetXaxis()->SetTitle("P_{T}^{2}(#mu#muKK) [MeV^{2}]");		h03->GetYaxis()->SetTitle("Events/(500000)");
	h03_psi->GetXaxis()->SetTitle("P_{T}^{2}(#mu#muKK) [MeV^{2}]");		h03_psi->GetYaxis()->SetTitle("Events/(500000)");
	h04->GetXaxis()->SetTitle("P_{T}^{2}(#mu#muKK) [MeV^{2}]");		h04->GetYaxis()->SetTitle("Events/(500000)");
	h05->GetXaxis()->SetTitle("P_{T}^{2}(#mu#muKK) [MeV^{2}]");		h05->GetYaxis()->SetTitle("Events/(500000)");
	h06->GetXaxis()->SetTitle("P_{T}^{2}(#mu#muKK) [MeV^{2}]");		h06->GetYaxis()->SetTitle("Events/(500000)");
	h07->GetXaxis()->SetTitle("P_{T}^{2}(#mu#muKK) [MeV^{2}]");		h07->GetYaxis()->SetTitle("Events/(500000)");
	h08->GetXaxis()->SetTitle("M(#mu#muKK) [MeV]");				h08->GetYaxis()->SetTitle("Events/(150)");
	h08_gt4->GetXaxis()->SetTitle("M(#mu#muKK) [MeV]");			h08_gt4->GetYaxis()->SetTitle("Events/(150)");			h08_gt4->SetLineColor(kRed);
	h08_gt6->GetXaxis()->SetTitle("M(#mu#muKK) [MeV]");			h08_gt6->GetYaxis()->SetTitle("Events/(150)");			h08_gt6->SetLineColor(kGreen);
	h08_KK->GetXaxis()->SetTitle("M(#mu#muKK) [MeV]");			h08_KK->GetYaxis()->SetTitle("Events/(60)");
	h08_pipi->GetXaxis()->SetTitle("M(#mu#mu#pi#pi) [MeV]");		h08_pipi->GetYaxis()->SetTitle("Events/(72)");
	h08_pp->GetXaxis()->SetTitle("M(#mu#mu#pi#pi) [MeV]");			h08_pp->GetYaxis()->SetTitle("Events/(12)");
	h09->GetXaxis()->SetTitle("P_{T}(#mu#mu) [MeV]");			h09->GetYaxis()->SetTitle("Events/(200)");
	h10->GetXaxis()->SetTitle("P_{T}(KK) [MeV]");				h10->GetYaxis()->SetTitle("Events/(150)");
	h11->GetXaxis()->SetTitle("P_{T}(KK) [MeV]");				h11->GetYaxis()->SetTitle("Events/(150)");
	h12->GetXaxis()->SetTitle("P_{T}(KK) [MeV]");				h12->GetYaxis()->SetTitle("Events/(150)");
	h13->GetXaxis()->SetTitle("P_{T}(KK) [MeV]");				h13->GetYaxis()->SetTitle("Events/(150)");
	h14->GetXaxis()->SetTitle("P_{T}(KK) [MeV]");				h14->GetYaxis()->SetTitle("Events/(150)");
	h15->GetXaxis()->SetTitle("M(KK) [MeV]");				h15->GetYaxis()->SetTitle("P_{T}(KK) [MeV]");			h15->GetYaxis()->SetTitleOffset(1.5);
	h16->GetXaxis()->SetTitle("M(#mu#mu) [MeV]");				h16->GetYaxis()->SetTitle("P_{T}(#mu#mu) [MeV]");		h16->GetYaxis()->SetTitleOffset(1.5);
	h17->GetXaxis()->SetTitle("M(#mu#muKK) [MeV]");				h17->GetYaxis()->SetTitle("P_{T}^{2} (#mu#muKK) [MeV]");	
	h18->GetXaxis()->SetTitle("M(KK) [MeV]");				h18->GetYaxis()->SetTitle("M(#mu#mu) [MeV]");			h18->GetYaxis()->SetTitleOffset(1.5); 
	h19->GetXaxis()->SetTitle("P_{T}^{2}(KK) [MeV^{2}]");			h19->GetYaxis()->SetTitle("Events/(200000)");
	h20->GetXaxis()->SetTitle("P_{T}^{2}(#mu#mu) [MeV^{2}]");		h20->GetYaxis()->SetTitle("Events/(3000)");
	h21->GetXaxis()->SetTitle("P_{T}^{2}(KK) [MeV^{2}]");			h21->GetYaxis()->SetTitle("Events/(3000)");
	h22->GetXaxis()->SetTitle("P_{T}^{2}(KK) [MeV^{2}]");			h22->GetYaxis()->SetTitle("Events/(3000)");
	h23->GetXaxis()->SetTitle("P_{T}^{2}(KK) [MeV^{2}]");			h23->GetYaxis()->SetTitle("Events/(3000)");
	h24->GetXaxis()->SetTitle("P_{T}^{2}(KK) [MeV^{2}]");			h24->GetYaxis()->SetTitle("Events/(3000)");
	h25->GetXaxis()->SetTitle("P_{T}^{2}(KK) [MeV^{2}]");			h25->GetYaxis()->SetTitle("P_{T}^{2}(#mu#mu [Mev^{2}]");	h25->GetYaxis()->SetTitleOffset(1.5);
	h26->GetXaxis()->SetTitle("P_{T}^{2}(KK) [MeV^{2}]");			h26->GetYaxis()->SetTitle("P_{T}^{2}(#mu#mu [Mev^{2}]");	h26->GetYaxis()->SetTitleOffset(1.5);
	h27->GetXaxis()->SetTitle("P_{T}^{2}(KK) [MeV^{2}]");			h27->GetYaxis()->SetTitle("P_{T}^{2}(#mu#mu [Mev^{2}]");	h27->GetYaxis()->SetTitleOffset(1.5);
	h28->GetXaxis()->SetTitle("P_{T}^{2}(KK) [MeV^{2}]");			h28->GetYaxis()->SetTitle("P_{T}^{2}(#mu#mu [Mev^{2}]");	h28->GetYaxis()->SetTitleOffset(1.5);
	h29->GetXaxis()->SetTitle("P_{T}^{2}(KK) [MeV^{2}]");			h29->GetYaxis()->SetTitle("P_{T}^{2}(#mu#mu [Mev^{2}]");	h29->GetYaxis()->SetTitleOffset(1.5);
	h44->GetXaxis()->SetTitle("M(#pi#pi) [MeV]");				h44->GetYaxis()->SetTitle("Events/(36)");			
	h44_s_psi->GetXaxis()->SetTitle("M(#pi#pi) [MeV]");			h44_s_psi->GetYaxis()->SetTitle("Events/(36)");			
	h45_KK->GetXaxis()->SetTitle("#Delta#phi/#pi");				h45_KK->GetYaxis()->SetTitle("Events/(0.05)");			
	h45_phi->GetXaxis()->SetTitle("#Delta#phi/#pi");				h45_phi->GetYaxis()->SetTitle("Events/(0.05)");			
	h45_rho->GetXaxis()->SetTitle("#Delta#phi/#pi");				h45_rho->GetYaxis()->SetTitle("Events/(0.05)");			
	h45_psi->GetXaxis()->SetTitle("#Delta#phi/#pi");				h45_psi->GetYaxis()->SetTitle("Events/(0.05)");			
	h46_phi->GetXaxis()->SetTitle("y");					h46_phi->GetYaxis()->SetTitle("Events/(0.06)");			
	h46_rho->GetXaxis()->SetTitle("y");					h46_rho->GetYaxis()->SetTitle("Events/(0.06)");			
	h46_psi->GetXaxis()->SetTitle("y");					h46_phi->GetYaxis()->SetTitle("Events/(0.06)");			
	h47_phi->GetXaxis()->SetTitle("#eta");					h47_phi->GetYaxis()->SetTitle("Events/(0.12)");			
	h47_muon1->GetXaxis()->SetTitle("#eta");				h47_muon1->GetYaxis()->SetTitle("Events/(0.08)");			
	h47_muon2->GetXaxis()->SetTitle("#eta");				h47_muon2->GetYaxis()->SetTitle("Events/(0.08)");			
	h47_rho->GetXaxis()->SetTitle("#eta");					h47_rho->GetYaxis()->SetTitle("Events/(0.12)");			
	h47_pion1->GetXaxis()->SetTitle("#eta");				h47_pion1->GetYaxis()->SetTitle("Events/(0.08)");			
	h47_pion2->GetXaxis()->SetTitle("#eta");				h47_pion2->GetYaxis()->SetTitle("Events/(0.08)");			
	h47_psi->GetXaxis()->SetTitle("#eta");					h47_phi->GetYaxis()->SetTitle("Events/(0.12)");			

	t01->GetXaxis()->SetTitle("M(#mu#mu) [MeV]");				t01->GetYaxis()->SetTitle("Events/(6)");			
	t02_35->GetXaxis()->SetTitle("M(KK) [MeV]");				t02_35->GetYaxis()->SetTitle("Events/(1.5)");
	t02_200->GetXaxis()->SetTitle("M(KK) [MeV]");				t02_200->GetYaxis()->SetTitle("Events/(9.75)");
	t03->GetXaxis()->SetTitle("P_{T}^{2}(#mu#muKK) [MeV^{2}]");		t03->GetYaxis()->SetTitle("Events/(500000)");
	t03_psi->GetXaxis()->SetTitle("P_{T}^{2}(#mu#muKK) [MeV^{2}]");		t03_psi->GetYaxis()->SetTitle("Events/(500000)");
	t04->GetXaxis()->SetTitle("P_{T}^{2}(#mu#muKK) [MeV^{2}]");		t04->GetYaxis()->SetTitle("Events/(500000)");
	t05->GetXaxis()->SetTitle("P_{T}^{2}(#mu#muKK) [MeV^{2}]");		t05->GetYaxis()->SetTitle("Events/(500000)");
	t06->GetXaxis()->SetTitle("P_{T}^{2}(#mu#muKK) [MeV^{2}]");		t06->GetYaxis()->SetTitle("Events/(500000)");
	t07->GetXaxis()->SetTitle("P_{T}^{2}(#mu#muKK) [MeV^{2}]");		t07->GetYaxis()->SetTitle("Events/(500000)");
	t08->GetXaxis()->SetTitle("M(#mu#muKK) [MeV]");				t08->GetYaxis()->SetTitle("Events/(150)");
	t08_gt4->GetXaxis()->SetTitle("M(#mu#muKK) [MeV]");			t08_gt4->GetYaxis()->SetTitle("Events/(150)");    		t08_gt4->SetLineColor(kRed);
	t08_gt6->GetXaxis()->SetTitle("M(#mu#muKK) [MeV]");			t08_gt6->GetYaxis()->SetTitle("Events/(150)");			t08_gt6->SetLineColor(kGreen);
	t08_KK->GetXaxis()->SetTitle("M(#mu#muKK) [MeV]");			t08_KK->GetYaxis()->SetTitle("Events/(60)");
	t08_pipi->GetXaxis()->SetTitle("M(#mu#mu#pi#pi) [MeV]");		t08_pipi->GetYaxis()->SetTitle("Events/(72)");
	t08_pp->GetXaxis()->SetTitle("M(#mu#mu#pi#pi) [MeV]");			t08_pp->GetYaxis()->SetTitle("Events/(12)");
	t09->GetXaxis()->SetTitle("P_{T}(#mu#mu) [MeV]");			t09->GetYaxis()->SetTitle("Events/(200)");
	t10->GetXaxis()->SetTitle("P_{T}(KK) [MeV]");				t10->GetYaxis()->SetTitle("Events/(150)");
	t11->GetXaxis()->SetTitle("P_{T}(KK) [MeV]");				t11->GetYaxis()->SetTitle("Events/(150)");
	t12->GetXaxis()->SetTitle("P_{T}(KK) [MeV]");				t12->GetYaxis()->SetTitle("Events/(150)");
	t13->GetXaxis()->SetTitle("P_{T}(KK) [MeV]");				t13->GetYaxis()->SetTitle("Events/(150)");
	t14->GetXaxis()->SetTitle("P_{T}(KK) [MeV]");				t14->GetYaxis()->SetTitle("Events/(150)");
	t15->GetXaxis()->SetTitle("M(KK) [MeV]");				t15->GetYaxis()->SetTitle("P_{T}(KK) [MeV]");			t15->GetYaxis()->SetTitleOffset(1.5);
	t16->GetXaxis()->SetTitle("M(#mu#mu) [MeV]");				t16->GetYaxis()->SetTitle("P_{T}(#mu#mu) [MeV]");		t16->GetYaxis()->SetTitleOffset(1.5);
	t17->GetXaxis()->SetTitle("M(#mu#muKK) [MeV]");				t17->GetYaxis()->SetTitle("P_{T}^{2} (#mu#muKK) [MeV]");		
	t18->GetXaxis()->SetTitle("M(KK) [MeV]");				t18->GetYaxis()->SetTitle("M(#mu#mu) [MeV]");			t18->GetYaxis()->SetTitleOffset(1.5); 
	t19->GetXaxis()->SetTitle("P_{T}^{2}(KK) [MeV^{2}]");			t19->GetYaxis()->SetTitle("Events/(200000)");
	t20->GetXaxis()->SetTitle("P_{T}^{2}(#mu#mu) [MeV^{2}]");		t20->GetYaxis()->SetTitle("Events/(3000)");
	t21->GetXaxis()->SetTitle("P_{T}^{2}(KK) [MeV^{2}]");			t21->GetYaxis()->SetTitle("Events/(3000)");
	t22->GetXaxis()->SetTitle("P_{T}^{2}(KK) [MeV^{2}]");			t22->GetYaxis()->SetTitle("Events/(3000)");
	t23->GetXaxis()->SetTitle("P_{T}^{2}(KK) [MeV^{2}]");			t23->GetYaxis()->SetTitle("Events/(3000)");
	t24->GetXaxis()->SetTitle("P_{T}^{2}(KK) [MeV^{2}]");			t24->GetYaxis()->SetTitle("Events/(3000)");
	t25->GetXaxis()->SetTitle("P_{T}^{2}(KK) [MeV^{2}]");			t25->GetYaxis()->SetTitle("P_{T}^{2}(#mu#mu [Mev^{2}]");	t25->GetYaxis()->SetTitleOffset(1.5);
	t26->GetXaxis()->SetTitle("P_{T}^{2}(KK) [MeV^{2}]");			t26->GetYaxis()->SetTitle("P_{T}^{2}(#mu#mu [Mev^{2}]");	t26->GetYaxis()->SetTitleOffset(1.5);
	t27->GetXaxis()->SetTitle("P_{T}^{2}(KK) [MeV^{2}]");			t27->GetYaxis()->SetTitle("P_{T}^{2}(#mu#mu [Mev^{2}]");	t27->GetYaxis()->SetTitleOffset(1.5);
	t28->GetXaxis()->SetTitle("P_{T}^{2}(KK) [MeV^{2}]");			t28->GetYaxis()->SetTitle("P_{T}^{2}(#mu#mu [Mev^{2}]");	t28->GetYaxis()->SetTitleOffset(1.5);
	t29->GetXaxis()->SetTitle("P_{T}^{2}(KK) [MeV^{2}]");			t29->GetYaxis()->SetTitle("P_{T}^{2}(#mu#mu [Mev^{2}]");	t29->GetYaxis()->SetTitleOffset(1.5);
	t44->GetXaxis()->SetTitle("M(#pi#pi) [MeV]");				t44->GetYaxis()->SetTitle("Events/(36)");			
	t44_s_psi->GetXaxis()->SetTitle("M(#pi#pi) [MeV]");			t44_s_psi->GetYaxis()->SetTitle("Events/(36)");		
	t45_KK->GetXaxis()->SetTitle("#Delta#phi/#pi");				t45_KK->GetYaxis()->SetTitle("Events/(0.05)");			
	t45_phi->GetXaxis()->SetTitle("#Delta#phi/#pi");				t45_phi->GetYaxis()->SetTitle("Events/(0.05)");			
	t45_rho->GetXaxis()->SetTitle("#Delta#phi/#pi");				t45_rho->GetYaxis()->SetTitle("Events/(0.05)");			
	t45_psi->GetXaxis()->SetTitle("#Delta#phi/#pi");				t45_psi->GetYaxis()->SetTitle("Events/(0.05)");			
	t46_phi->GetXaxis()->SetTitle("y");					t46_phi->GetYaxis()->SetTitle("Events/(0.06)");			
	t46_rho->GetXaxis()->SetTitle("y");					t46_rho->GetYaxis()->SetTitle("Events/(0.06)");			
	t46_psi->GetXaxis()->SetTitle("y");					t46_phi->GetYaxis()->SetTitle("Events/(0.06)");			
	t47_phi->GetXaxis()->SetTitle("#eta");					t47_phi->GetYaxis()->SetTitle("Events/(0.12)");			
	t47_muon1->GetXaxis()->SetTitle("#eta");				t47_muon1->GetYaxis()->SetTitle("Events/(0.08)");			
	t47_muon2->GetXaxis()->SetTitle("#eta");				t47_muon2->GetYaxis()->SetTitle("Events/(0.08)");			
	t47_rho->GetXaxis()->SetTitle("#eta");					t47_rho->GetYaxis()->SetTitle("Events/(0.12)");			
	t47_pion1->GetXaxis()->SetTitle("#eta");				t47_pion1->GetYaxis()->SetTitle("Events/(0.08)");			
	t47_pion2->GetXaxis()->SetTitle("#eta");				t47_pion2->GetYaxis()->SetTitle("Events/(0.08)");			
	t47_psi->GetXaxis()->SetTitle("#eta");					t47_phi->GetYaxis()->SetTitle("Events/(0.12)");			

	//TCanvas *c01 = new TCanvas("c01","Histos", 1); 						
	h01->Draw(); 										
	h01->Write("h01");									
	//c01->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/Massa(JPsi).png");					
	
	//TCanvas *d01 = new TCanvas("d01","Histos", 1);
	t01->Draw(); 
	t01->Write("t01");	
	//d01->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/Massa(JPsi).png");

	//TCanvas *c02_35 = new TCanvas("c02_35","Histos", 1);					
	h02_35->Draw();										
	h02_35->Write("h02_35");								
	//c02_35->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/Massa(Phi(1005-1035)).png");			
	
	//TCanvas *d02_35 = new TCanvas("t02_35","Histos", 1);
	t02_35->Draw();		
	t02_35->Write("t02_35");
	//d02_35->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/Massa(Phi(1005-1035)).png");
	
	//TCanvas *c02_200 = new TCanvas("c02_200","Histos", 1);					
	h02_200->Draw();									
	h02_200->Write("h02_200");								
	//c02_200->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/Massa(Phi(1005-1200)).png");			

	//TCanvas *d02_200 = new TCanvas("d02_200","Histos", 1);
	t02_200->Draw();
	t02_200->Write("t02_200");
	//d02_200->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/Massa(Phi(1005-1200)).png");

	//TCanvas *c03 = new TCanvas("c03","Histos", 1);						
	h03->Draw();										
	h03->Write("h03");									
	//c03->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/PT^2(JPsi_Phi(1005-1035)).png");			

	//TCanvas *d03 = new TCanvas("d03","Histos", 1);                     	
	t03->Draw();
	t03->Write("t03");
	//d03->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/PT^2(JPsi_Phi(1005-1035)).png");
	
	TCanvas *c03_psi = new TCanvas("c03_psi","Histos", 1);						
	h03_psi->Draw();										
	h03_psi->Write("h03_psi");									
	c03_psi->SaveAs("Histo==4_2011/JpsiKKExclusiveLongPIDK/PT^2(JPsi_PiPi).png");			

	TCanvas *d03_psi = new TCanvas("d03_psi","Histos", 1);                     	
	t03_psi->Draw();
	t03_psi->Write("t03_psi");
	d03_psi->SaveAs("Histo==4_2012/JpsiKKExclusiveLongPIDK/PT^2(JPsi_PiPi).png");

	//TCanvas *c04 = new TCanvas("c04","Histos", 1);						
	h04->Draw();										
	h04->Write("h04");									
	//c04->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/PT^2(JPsi_Phi(990-1005)).png");			

	//TCanvas *d04 = new TCanvas("d04","Histos", 1);
	t04->Draw();
	t04->Write("t04");
	//d04->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/PT^2(JPsi_Phi(990-1005)).png");

	//TCanvas *c05 = new TCanvas("c05","Histos", 1);						
	h05->Draw();										
	h05->Write("h05");									
	//c05->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/PT^2(JPsi_Phi(1035-1050)).png");			

	//TCanvas *d05 = new TCanvas("d05","Histos", 1);
	t05->Draw();
	t05->Write("t05");
	//d05->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/PT^2(JPsi_Phi(1035-1050)).png");

	//TCanvas *c06 = new TCanvas("c06","Histos", 1);						
	h06->Draw();										
	h06->Write("h06");									
	//c06->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/PT^2(Media_JPsi_Phi).png");				

	//TCanvas *d06 = new TCanvas("d06","Histos", 1);					
	t06->Draw();
	t06->Write("t06");
	//d06->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/PT^2(Media_JPsi_Phi).png");

	//TCanvas *c07 = new TCanvas("c07","Histos", 1);						
	h07->Draw();										
	h07->Write("h07");									
	//c07->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/PT^2(JPsi_Phi_sem_bkg).png");				

	//TCanvas *d07 = new TCanvas("d07","Histos", 1);
	t07->Draw();
	t07->Write("t07");
	//d07->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/PT^2(JPsi_Phi_sem_bkg).png");

	//TCanvas *c08 = new TCanvas("c08","Histos", 1);						
	h08->Draw();										
	h08->Write("h08");									
	//c08->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/Massa(JPsi_Phi(1005-1035)).png");			

	//TCanvas *d08 = new TCanvas("d08","Histos", 1);
	t08->Draw();
	t08->Write("t08");
	//d08->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/Massa(JPsi_Phi(1005-1035)).png");

	/*TCanvas *c08_gt4 = new TCanvas("c08_gt4","Histos", 1);                      
	c08_gt4->SetLogy();
	h08_gt4->Draw("same");                                        
	h08_gt4->Write("h08_gt4");
	h08_gt6->Draw("same");                                        
	h08_gt6->Write("h08_gt6");
	h08->Draw("same");                                        
	h08->Write("h08");
	TLegend *leg08 = new TLegend(0.60, 0.50, 0.90, 0.70);                  
	leg08->AddEntry(h08,"nVeloTracks==4","lep");                 
	leg08->AddEntry(h08_gt4,"nVeloTracks>4","lep");                   
	leg08->AddEntry(h08_gt6,"nVeloTracks>6","lep");                   
	leg08->Draw("same");                                    
	c08_gt4->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/Massa(JPsiPhi(1005-1035))_comp.png");

	TCanvas *d08_gt4 = new TCanvas("d08_gt4","Histos", 1);                      
	d08_gt4->SetLogy();
	t08_gt4->Draw("same");                                        
	t08_gt4->Write("t08_gt4");
	t08_gt6->Draw("same");                                        
	t08_gt6->Write("t08_gt6");
	t08->Draw("same");                                        
	t08->Write("t08");
	TLegend *log08 = new TLegend(0.60, 0.50, 0.90, 0.70);                  
	log08->AddEntry(t08,"nVeloTracks==4","lep");                 
	log08->AddEntry(t08_gt4,"nVeloTracks>4","lep");                   
	log08->AddEntry(t08_gt6,"nVeloTracks>6","lep");                   
	log08->Draw("same");                                    
	d08_gt4->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/Massa(JPsiPhi(1005-1035))_comp.png");
 */
	//TCanvas *c08_KK = new TCanvas("c08_KK","Histos", 1);						
	h08_KK->Draw();										
	h08_KK->Write("h08_KK");									
	//c08_KK->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/Massa(JPsi_K_K).png");			

	//TCanvas *d08_KK = new TCanvas("d08_KK","Histos", 1);
	t08_KK->Draw();
	t08_KK->Write("t08_KK");
	//d08_KK->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/Massa(JPsi_K_K).png");

	//TCanvas *c08_pipi = new TCanvas("c08_pipi","Histos", 1);						
	h08_pipi->Draw();										
	h08_pipi->Write("h08_pipi");									
	//c08_pipi->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/Massa(JPsi_Pion_Pion).png");			

	//TCanvas *d08_pipi = new TCanvas("d08_pipi","Histos", 1);
	t08_pipi->Draw();
	t08_pipi->Write("t08_pipi");
	//d08_pipi->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/Massa(JPsi_Pion_Pion).png");

	//TCanvas *c08_pp = new TCanvas("c08_pp","Histos", 1);						
	h08_pp->Draw();										
	h08_pp->Write("h08_pp");									
	//c08_pp->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/Massa(JPsi_Pion_Pion)(Zoom).png");			

	//TCanvas *d08_pp = new TCanvas("d08_pp","Histos", 1);
	t08_pp->Draw();
	t08_pp->Write("t08_pp");
	//d08_pp->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/Massa(JPsi_Pion_Pion)(Zoom).png");
	
	//TCanvas *c09 = new TCanvas("c09","Histos", 1);						
	h09->Draw();										
	h09->Write("h09");									
	//c09->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/PT(JPsi).png");					

	//TCanvas *d09 = new TCanvas("d09","Histos", 1);
	t09->Draw();
	t09->Write("t09");
	//d09->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/PT(JPsi).png");

	//TCanvas *c10 = new TCanvas("c10","Histos", 1);						
	h10->Draw();										
	h10->Write("h10");									
	//c10->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/PT(Phi(1005-1035)).png");				

	//TCanvas *d10 = new TCanvas("d10","Histos", 1);
	t10->Draw();
	t10->Write("t10");
	//d10->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/PT(Phi(1005-1035)).png");

	//TCanvas *c11 = new TCanvas("c11","Histos", 1);						
	h11->Draw();										
	h11->Write("h11");									
	//c11->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/PT(Phi(990-1005)).png");				

	//TCanvas *d11 = new TCanvas("d11","Histos", 1);
	t11->Draw();
	t11->Write("t11");
	//d11->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/PT(Phi(990-1005)).png");

	//TCanvas *c12 = new TCanvas("c12","Histos", 1);						
	h12->Draw();										
	h12->Write("h12");									
	//c12->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/PT(Phi(1035-1050)).png");				

	//TCanvas *d12 = new TCanvas("d12","Histos", 1);
	t12->Draw();
	t12->Write("t12");
	//d12->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/PT(Phi(1035-1050)).png");

	//TCanvas *c13 = new TCanvas("c13","Histos", 1);						
	h13->Draw();										
	h13->Write("h13");									
	//c13->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/PT(Media_Phi).png");					

	//TCanvas *d13 = new TCanvas("d13","Histos", 1);
	t13->Draw();
	t13->Write("t13");
	//d13->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/PT(Media_Phi).png");
	
	//TCanvas *c14 = new TCanvas("c14","Histos", 1);						
	h14->Draw();										
	h14->Write("h14");									
	//c14->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/PT(Phi_sem_bkg).png");				

	//TCanvas *d14 = new TCanvas("d14","Histos", 1);
	t14->Draw();
	t14->Write("t14");
	//d14->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/PT(Phi_sem_bkg).png");
	
	//TCanvas *c15 = new TCanvas("c15","Histos", 1);						
	h15->Draw("colz");										
	h15->Write("h15");									
	//c15->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/PTxMassa(Phi).png");					

	//TCanvas *d15 = new TCanvas("d15","Histos", 1);
	t15->Draw("colz");
	t15->Write("t15");
	//d15->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/PTxMassa(Phi).png");

	//TCanvas *c16 = new TCanvas("c16","Histos", 1);						
	h16->Draw("colz");									
	h16->Write("h16");									
	//c16->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/PTxMassa(JPsi).png");					

	//TCanvas *d16 = new TCanvas("d16","Histos", 1);
	t16->Draw("colz");
	t16->Write("t16");
	//d16->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/PTxMassa(JPsi).png");

	//TCanvas *c17 = new TCanvas("c17","Histos", 1);						
	h17->Draw("colz");									
	h17->Write("h17");									
	//c17->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/PT^2xMassa(JPsi_Phi).png");				

	//TCanvas *d17 = new TCanvas("d17","Histos", 1);
	t17->Draw("colz");
	t17->Write("t17");
	//d17->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/PT^2xMassa(JPsi_Phi).png");

	//TCanvas *c18 = new TCanvas("c18","Histos", 1);						
	h18->Draw("colz");									
	h18->Write("h18");									
	//c18->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/Massa(JPsixPhi).png");				

	//TCanvas *d18 = new TCanvas("d18","Histos", 1);
	t18->Draw("colz");
	t18->Write("t18");
	//d18->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/Massa(JPsixPhi).png");

	//TCanvas *c19 = new TCanvas("c19","Histos", 1);						
	h19->Draw();										
	h19->Write("h19");									
	//c19->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/PT^2(JPsi).png");

	//TCanvas *d19 = new TCanvas("d19","Histos", 1);
	t19->Draw();
	t19->Write("t19");
	//d19->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/PT^2(JPsi).png");
	
	//TCanvas *c20 = new TCanvas("c20","Histos", 1);						
	h20->Draw();										
	h20->Write("h20");									
	//c20->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/PT^2(Phi(1005-1035)).png");				

	//TCanvas *d20 = new TCanvas("d20","Histos", 1);
	t20->Draw();
	t20->Write("t20");
	//d20->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/PT^2(Phi(1005-1035)).png");

	//TCanvas *c21 = new TCanvas("c21","Histos", 1);						
	h21->Draw();										
	h21->Write("h21");									
	//c21->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/PT^2(Phi(990-1005)).png");				

	//TCanvas *d21 = new TCanvas("d21","Histos", 1);
	t21->Draw();
	t21->Write("t21");
	///d21->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/PT^2(Phi(990-1005)).png");

	//TCanvas *c22 = new TCanvas("c22","Histos", 1);						
	h22->Draw();										
	h22->Write("h22");									
	//c22->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/PT^2(Phi(1035-1050)).png");				

	//TCanvas *d22 = new TCanvas("d22","Histos", 1);
	t22->Draw();
	t22->Write("t22");
	//d22->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/PT^2(Phi(1035-1050)).png");

	//TCanvas *c23 = new TCanvas("c23","Histos", 1);						
	h23->Draw();										
	h23->Write("h23");									
	//c23->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/PT^2(Media_Phi).png");				

	//TCanvas *d23 = new TCanvas("d23","Histos", 1);
	t23->Draw();
	t23->Write("t23");
	//d23->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/PT^2(Media_Phi).png");
	
	//TCanvas *c24 = new TCanvas("c24","Histos", 1);						
	h24->Draw();										
	h24->Write("h24");									
	//c24->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/PT^2(Phi_sem_bkg).png");				

	//TCanvas *d24 = new TCanvas("d24","Histos", 1);
	t24->Draw();
	t24->Write("t24");
	//d24->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/PT^2(Phi_sem_bkg).png");

	//TCanvas *c25 = new TCanvas("c25","Histos", 1);						
	h25->Draw("colz");										
	h25->Write("h25");									
	//c25->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/PT^2(JPsixPhi(1005-1035)).png");			
	
	//TCanvas *d25 = new TCanvas("d25","Histos", 1);
	t25->Draw("colz");
	t25->Write("t25");
	//d25->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/PT^2(JPsixPhi(1005-1035)).png");

	//TCanvas *c26 = new TCanvas("c26","Histos", 1);						
	h26->Draw("colz");									
	h26->Write("h26");									
	//c26->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/PT^2(JPsixPhi(990-1005)).png");			

	//TCanvas *d26 = new TCanvas("d26","Histos", 1);
	t26->Draw("colz");
	t26->Write("t26");
	//d26->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/PT^2(JPsixPhi(990-1005)).png");

	//TCanvas *c27 = new TCanvas("c27","Histos", 1);						
	h27->Draw("colz");									
	h27->Write("h26");									
	//c27->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/PT^2(JPsixPhi(1035-1050)).png");			

	//TCanvas *d27 = new TCanvas("d27","Histos", 1);
	t27->Draw("colz");
	t27->Write("t27");
	//d27->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/PT^2(JPsixPhi(1035-1050)).png");

	//TCanvas *c28 = new TCanvas("c28","Histos", 1);						
	h28->Draw("colz");									
	h28->Write("h28");									
	//c28->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/PT^2(Media_JPsixPhi).png");				

	//TCanvas *d28 = new TCanvas("d28","Histos", 1);
	t28->Draw("colz");
	t28->Write("t28");
	//d28->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/PT^2(Media_JPsixPhi).png");

	//TCanvas *c29 = new TCanvas("c29","Histos", 1);						
	h29->Draw("colz");									
	h29->Write("h29");									
	//c29->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/PT^2(JPsixPhi_sem_bkg).png");				

	//TCanvas *d29 = new TCanvas("d29","Histos", 1);
	t29->Draw("colz");
	t29->Write("t29");
	//d29->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/PT^2(JPsixPhi_sem_bkg).png");
	
	//TCanvas *c44 = new TCanvas("c44","Histos", 1);						
	h44->Draw();										
	h44->Write("h44");									
	//c44->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/Massa_PionPion.png");					
	
	//TCanvas *d44 = new TCanvas("d44","Histos", 1);
	t44->Draw();
	t44->Write("t44");
	//d44->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/Massa_PionPion.png");
	
	//TCanvas *c44_s_psi = new TCanvas("c44_s_psi","Histos", 1);						
	h44_s_psi->Draw();										
	h44_s_psi->Write("h44_s_psi");									
	//c44_s_psi->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/Massa_PionPion_sem_Psi(2S).png");					

	//TCanvas *d44_s_psi = new TCanvas("d44_s_psi","Histos", 1);						
	t44_s_psi->Draw();										
	t44_s_psi->Write("t44_s_psi");									
	//d44_s_psi->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/Massa_PionPion_sem_Psi(2S).png");					
	
	TCanvas *c45_KK = new TCanvas("c45_KK","Histos",1);
	h45_KK->Draw();
	h45_KK->Write("h45_KK");
	c45_KK->SaveAs("Histo==4_2011/JpsiKKExclusiveLongPIDK/Delta_Phi_JPsiKK.png");
	
	TCanvas *d45_KK = new TCanvas("d45_KK","Histos",1);
	t45_KK->Draw();
	t45_KK->Write("t45_KK");
	d45_KK->SaveAs("Histo==4_2012/JpsiKKExclusiveLongPIDK/Delta_Phi_JPsiKK.png");
	
	TCanvas *c45_phi = new TCanvas("c45_phi","Histos",1);
	h45_phi->Draw();
	h45_phi->Write("h45_phi");
	c45_phi->SaveAs("Histo==4_2011/JpsiKKExclusiveLongPIDK/Delta_Phi_JPsiPhi.png");
	
	TCanvas *d45_phi = new TCanvas("d45_phi","Histos",1);
	t45_phi->Draw();
	t45_phi->Write("t45_phi");
	d45_phi->SaveAs("Histo==4_2012/JpsiKKExclusiveLongPIDK/Delta_Phi_JPsiPhi.png");
	
	TCanvas *c45_rho = new TCanvas("c45_rho","Histos",1);
	h45_rho->Draw();
	h45_rho->Write("h45_rho");
	c45_rho->SaveAs("Histo==4_2011/JpsiKKExclusiveLongPIDK/Delta_Phi_JPsiRho.png");
	
	TCanvas *d45_rho = new TCanvas("d45_rho","Histos",1);
	t45_rho->Draw();
	t45_rho->Write("t45_rho");
	d45_rho->SaveAs("Histo==4_2012/JpsiKKExclusiveLongPIDK/Delta_Phi_JPsiRho.png");
	
	TCanvas *c45_psi = new TCanvas("c45_psi","Histos",1);
	h45_psi->Draw();
	h45_psi->Write("h45_psi");
	c45_psi->SaveAs("Histo==4_2011/JpsiKKExclusiveLongPIDK/Delta_Phi_JPsiPiPi.png");
	
	TCanvas *d45_psi = new TCanvas("d45_psi","Histos",1);
	t45_psi->Draw();
	t45_psi->Write("t45_psi");
	d45_psi->SaveAs("Histo==4_2012/JpsiKKExclusiveLongPIDK/Delta_Phi_JPsiPiPi.png");
	
	//TCanvas *c46_phi = new TCanvas("c46_phi","Histos",1);
	h46_phi->Draw();
	h46_phi->Write("h46_phi");
	//c46_phi->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/Rapidez_JPsiPhi.png");
	
	//TCanvas *d46_phi = new TCanvas("d46_phi","Histos",1);
	t46_phi->Draw();
	t46_phi->Write("t46_phi");
	//d46_phi->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/Rapidez_JPsiPhi.png");
	
	//TCanvas *c46_rho = new TCanvas("c46_rho","Histos",1);
	h46_rho->Draw();
	h46_rho->Write("h46_rho");
	//c46_rho->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/Rapidez_JPsiRho.png");
	
	//TCanvas *d46_rho = new TCanvas("d46_rho","Histos",1);
	t46_rho->Draw();
	t46_rho->Write("t46_rho");
	//d46_rho->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/Rapidez_JPsiRho.png");
	
	//TCanvas *c46_psi = new TCanvas("c46_psi","Histos",1);
	h46_psi->Draw();
	h46_psi->Write("h46_psi");
	//c46_psi->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/Rapidez_Psi(2S).png");
	
	//TCanvas *d46_psi = new TCanvas("d46_psi","Histos",1);
	t46_psi->Draw();
	t46_psi->Write("t46_psi");
	//d46_psi->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/Rapidez_Psi(2S).png");

	//TCanvas *c47_phi = new TCanvas("c47_phi","Histos",1);
	h47_phi->Draw();
	h47_phi->Write("h47_phi");
	//c47_phi->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/PseudoRapidez_JPsiPhi.png");
	
	//TCanvas *d47_phi = new TCanvas("d47_phi","Histos",1);
	t47_phi->Draw();
	t47_phi->Write("t47_phi");
	//d47_phi->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/PseudoRapidez_JPsiPhi.png");
	
	//TCanvas *c47_muon1 = new TCanvas("c47_muon1","Histos",1);
	h47_muon1->Draw();
	h47_muon1->Write("h47_muon1");
	//c47_muon1->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/PseudoRapidez_Muon-.png");
	
	//TCanvas *d47_muon1 = new TCanvas("d47_muon1","Histos",1);
	t47_muon1->Draw();
	t47_muon1->Write("t47_muon1");
	//d47_muon1->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/PseudoRapidez_Muon-.png");
	
	//TCanvas *c47_muon2 = new TCanvas("c47_muon2","Histos",1);
	h47_muon2->Draw();
	h47_muon2->Write("h47_muon2");
	//c47_muon2->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/PseudoRapidez_Muon+.png");
	
	//TCanvas *d47_muon2 = new TCanvas("d47_muon2","Histos",1);
	t47_muon2->Draw();
	t47_muon2->Write("t47_muon2");
	//d47_muon2->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/PseudoRapidez_Muon+.png");
	
	//TCanvas *c47_rho = new TCanvas("c47_rho","Histos",1);
	h47_rho->Draw();
	h47_rho->Write("h47_rho");
	//c47_rho->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/PseudoRapidez_JPsiRho.png");
	
	//TCanvas *d47_rho = new TCanvas("d47_rho","Histos",1);
	t47_rho->Draw();
	t47_rho->Write("t47_rho");
	//d47_rho->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/PseudoRapidez_JPsiRho.png");

	//TCanvas *c47_pion1 = new TCanvas("c47_pion1","Histos",1);
	h47_pion1->Draw();
	h47_pion1->Write("h47_pion1");
	//c47_pion1->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/PseudoRapidez_Pion-.png");
	
	//TCanvas *d47_pion1 = new TCanvas("d47_pion1","Histos",1);
	t47_pion1->Draw();
	t47_pion1->Write("t47_pion1");
	//d47_pion1->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/PseudoRapidez_Pion-.png");
	
	//TCanvas *c47_pion2 = new TCanvas("c47_pion2","Histos",1);
	h47_pion2->Draw();
	h47_pion2->Write("h47_pion2");
	//c47_pion2->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/PseudoRapidez_Pion+.png");
	
	//TCanvas *d47_pion2 = new TCanvas("d47_pion2","Histos",1);
	t47_pion2->Draw();
	t47_pion2->Write("t47_pion2");
	//d47_pion2->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/PseudoRapidez_Pion+.png");
	
	//TCanvas *c47_psi = new TCanvas("c47_psi","Histos",1);
	h47_psi->Draw();
	h47_psi->Write("h47_psi");
	//c47_psi->SaveAs("Histo==4_2011/JpsiKKExclusiveLong/PseudoRapidez_Psi(2S).png");
	
	//TCanvas *d47_psi = new TCanvas("d47_psi","Histos",1);
	t47_psi->Draw();
	t47_psi->Write("t47_psi");
	//d47_psi->SaveAs("Histo==4_2012/JpsiKKExclusiveLong/PseudoRapidez_Psi(2S).png");
	
	f3->Close();
}                                                                              
