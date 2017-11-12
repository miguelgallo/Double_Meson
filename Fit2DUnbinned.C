{
gROOT->Reset();
gROOT->ProcessLine(".X lhcbStyle.C"); // LHCb Style for plots/fits
gSystem->Load("libRooFit.so") ;
using namespace RooFit ;
using namespace RooStats ;
// ---------------- Binning and range ---------------- //
Int_t   nbin = 70;
Float_t xmin = 1005;
Float_t xmax = 1035;
Float_t Jmax = 3156;
Float_t Jmin = 3036;
// --------------- Data ------------- //
TChain * Data = new TChain("","");
Data->Add("/home/gustavo/NewTuples/JpsiKKExclusivePIDK2011.root/DecayTree");
//Data->Add("/mnt/c/NewTuples/JpsiKKExclusive2011.root/DecayTree");
TTree * t = Data->CopyTree("");
RooRealVar Phi_M("Phi_M","M(KK) [MeV]",xmin,xmax);
RooRealVar Jpsi_M("Jpsi_M","M(#mu#mu) [MeV]",Jmin,Jmax);
RooDataSet data("data","data",t,RooArgSet(Phi_M,Jpsi_M));
// Phi Models
// Signal
//RooRealVar  sig_Gauss( "#sigma_{G}", "sigmag",   4,    1,   10,            "MeV");
//RooRealVar  sig_Breit( "#sigma_{S}","sigmabw",   9,    1,   10,            "MeV");
//RooRealVar          N(          "S",      "S", 1e4,    1,  1e7,         "Events");
//RooRealVar         Fg(  "F_{Gauss}",     "Fg", 0.5,    0,    1, "Gauss Fraction");
//RooRealVar        Fbw( "F_{BreitW}",    "Fbw", 0.5,    0,    1,"BreitW Fraction");
//RooRealVar       mean("M_{0}(#phi)",   "mean",1020, xmin, xmax,            "MeV");
//// Gaussian
//RooGaussian     g( "g",  "g", Phi_M, mean, sig_Gauss);
//RooBreitWigner bw("bw", "bw", Phi_M, mean, sig_Breit);
//// PDF def.
//RooAddPdf cPDF("cPDF","cPDF", RooArgList(bw, g), RooArgList(Fbw, Fg));
//RooAddPdf PhiPDF("PhiPDF","PhiPDF", RooArgList(cPDF), RooArgList(N));

RooRealVar  sigmabw( "#sigma_{G}","sigmabw",  2.67,    1,  4.,            "MeV");
RooRealVar          N(          "S",      "S", 110,    5,  930,         "Events");
RooRealVar       mean("M_{0}(#phi)",   "mean",1019, 1017, 1021,            "MeV");

//RooBreitWigner bw("bw", "bw", Phi_M, mean, sig_Breit);
RooGaussian     g( "g",  "g", Phi_M, mean, sigmabw);

//RooAddPdf PhiPDF("PhiPDF","PhiPDF", RooArgList(g), RooArgList(N));
//RooAddPdf PhiPDF("PhiPDF","PhiPDF", RooArgList(bw), RooArgList(N));
RooAddPdf PhiPDF("PhiPDF","PhiPDF", RooArgList(g), RooArgList(N));
//RooRealVar  r("Exp par.", "r", .084, 0, 1.15, "MeV^{-1}") ;
//RooExponential BackExpon_Phi("BackExpon_Phi","BackExpon_Phi", Phi_M, r);
//RooRealVar B_Phi("Bkg","B", 64, 0, 92, "Bkg Events");
//RooAbsPdf * bPDF1 = new RooExtendPdf("bPDF1","bPDF1", BackExpon_Phi, B_Phi);

RooRealVar p0("p0","p0",  -.7, -1.1, -0.5) ;
RooRealVar p1("p1","p1", 7e-4, 4e-4, 1e-3) ; 
RooRealVar p2("p2","p2", 5e-4, 4e-4, 6e-4) ; 
RooPolynomial BackPol("BackPol","BackPol", Phi_M, RooArgList(p2), 2);
RooRealVar B_Phi("Bkg","B", 100, 10., 920, "Bkg Events");
RooAbsPdf * bPDF1 = new RooExtendPdf("bPDF1","bPDF1", BackPol, B_Phi);

// Jpsi models
// signal
//RooRealVar     a(    "#alpha",    "a",   2.7,    1,    5);
//RooRealVar     n(         "n",    "n",     1,  0.1,    5);
//RooRealVar  sigJ("#sigma_{G}", "sigJ", 15.64,14.77,16.41);
//RooRealVar    NJ(     "S_{G}",   "NJ",   210,  196,  224);
RooRealVar  sigJ("#sigma_{G2}", "sigJ", 9.43,1,95, "MeV");
RooRealVar    NJ(     "S_{G}",   "NJ",   150,  10,  920, "Events");
RooRealVar    mJ(     "M_{0}(J/#psi)",   "mJ",  3098.4, 3005, 3505);
//RooCBShape    cb(         "cb",  "cb",Jpsi_M,  mJ, sigJ, a, n);
RooGaussian   g2( "g2",  "g2", Jpsi_M, mJ, sigJ);
// PDF def.
RooAddPdf JpsiPDF("JpsiPDF","JpsiPDF",    RooArgList(g2), RooArgList(NJ));
//RooAddPdf JpsiPDF("JpsiPDF","JpsiPDF",    RooArgList(cb), RooArgList(NJ));
// Background component
RooRealVar  s("Exp param J/#psi", "s", -3.25e-3, -10, 1, "MeV^{-1}") ;
RooExponential ExpJpsi("ExpJpsi","ExpJpsi", Jpsi_M, s);
RooRealVar C("J/#psi B_{Exp}","C", 1, 0., 9e2, "Bkg Events");
RooAbsPdf * bPDF2 = new RooExtendPdf("bPDF2","bPDF2", ExpJpsi, C);

//RooRealVar q0("q0","q0",  0,  -90,  90) ;
//RooRealVar q1("q1","q1",  0,  -90,  90) ; 
//RooRealVar q2("q2","q2",  0,  -90,  90) ; 
//RooPolynomial BackPol2("BackPol2","BackPol2", Jpsi_M, RooArgList(q0,q1), 0);
//RooRealVar C("Bkg","C", 8, 0., 9e2, "Bkg Events");
//RooAbsPdf * bPDF2 = new RooExtendPdf("bPDF2","bPDF2", BackPol2, C);

// Build your PDF as signal + bkg + reflection!
//RooAbsPdf * JpsiPDFTotal = new RooAddPdf("JpsiPDFTotal","JpsiPDFTotal", RooArgList(JpsiPDF, *bPDF2));
RooAbsPdf * JpsiPDFTotal = new RooAddPdf("JpsiPDFTotal","JpsiPDFTotal", RooArgList(JpsiPDF, PhiPDF));
RooAbsPdf * PhiPDFTotal  = new RooAddPdf( "PhiPDFTotal","JpsiPDFTotal", RooArgList(*bPDF1));
//RooAbsPdf * PhiPDFTotal  = new RooAddPdf( "PhiPDFTotal","JpsiPDFTotal", RooArgList(PhiPDF));
RooAbsPdf * PDF = new RooAddPdf("PDF","PDF", RooArgList(*JpsiPDFTotal, *PhiPDFTotal));
//RooAbsPdf * PDF = new RooAddPdf("PDF","PDF", RooArgList(JpsiPDF, PhiPDF, *bPDF1));
// Roofit fit to data
//RooFitResult * res = PDF->fitTo(data,Hesse(true),Strategy(2), Save(true), Verbose(0), PrintLevel(-1), Warnings(0), PrintEvalErrors(-1), Extended(kTRUE));
RooFitResult * res = PDF->fitTo(data,Hesse(true),Strategy(2), Save(true), Extended(kTRUE));
//RooFitResult * res = PDF->fitTo(data,Extended(kTRUE));
// Frames and Draws
RooPlot* frame = Jpsi_M.frame();
data.plotOn(frame, MarkerSize(1));
JpsiPDFTotal->plotOn(frame, Components(JpsiPDF), LineWidth(4), LineStyle(1), LineColor(kBlue));  
//JpsiPDFTotal->plotOn(frame, Components(*bPDF2), LineWidth(4), LineStyle(1), LineColor(kViolet));  
JpsiPDFTotal->plotOn(frame, Name("mycurve"), LineWidth(8), LineStyle(9), LineColor(kRed));  
JpsiPDFTotal->paramOn(frame,Label(""),Format("NELU",AutoPrecision(2)));
// TCanvas to draw
TCanvas * canvas = new TCanvas("canvas", "canvas",1);
canvas->cd();
// Pads to fitted histo and pull
pad1 = new TPad("pad1","pad1",0.00,0.2,1,1);
pad2 = new TPad("pad2","pad2",0.00,0.0,1,0.2);
pad1->Draw();
pad2->Draw();
pad1->cd();
frame->Draw();
RooPlot* frame2 = Jpsi_M.frame() ; // same way you made 'frame' 
frame2->addObject(frame->pullHist(),"BE0X0") ; 
frame2->SetMinimum(-2); 
frame2->SetMaximum(+2); 
pad2->cd();
frame2->Draw() ; 
canvas->Print("Jpsi.png");

h1 = new TH1F("h1", "M(KK) [MeV]", nbin, xmin, xmax);
h1->SetMarkerStyle(20);
h1->GetXaxis()->SetTitle("M(KK) [MeV]");
h1->GetYaxis()->SetTitle("Events");
h1->SetLineWidth(3);
t->Project("h1", "Phi_M", "");
RooDataHist databin("databin","dataset with Phi_M", Phi_M, h1) ;

// Frames and Draws
RooPlot* frame3 = Phi_M.frame();
databin.plotOn(frame3, MarkerSize(1));
PhiPDFTotal->plotOn(frame3, Components(PhiPDF), LineWidth(4), LineStyle(1), LineColor(kBlue));  
PhiPDFTotal->plotOn(frame3, Components(*bPDF1), LineWidth(4), LineStyle(1), LineColor(kViolet));  
PhiPDFTotal->plotOn(frame3, Name("mycurve"), LineWidth(8), LineStyle(9), LineColor(kRed));  
PhiPDFTotal->paramOn(frame3,Label(""),Format("NELU",AutoPrecision(2)));
// TCanvas to draw
TCanvas * canvas2 = new TCanvas("canvas2", "canvas2",1);
canvas2->cd();
// Pads to fitted histo and pull
pad3 = new TPad("pad3","pad3",0.00,0.2,1,1);
pad4 = new TPad("pad4","pad4",0.00,0.0,1,0.2);
pad3->Draw();
pad4->Draw();
pad3->cd();
frame3->Draw();
RooPlot* frame4 = Phi_M.frame() ; // same way you made 'frame' 
frame4->addObject(frame3->pullHist(),"BE0X0") ; 
frame4->SetMinimum(-2); 
frame4->SetMaximum(+2); 
pad4->cd();
frame4->Draw() ; 
canvas2->Print("Phi.png");
}

