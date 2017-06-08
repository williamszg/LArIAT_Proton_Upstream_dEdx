#define dEdxProtonMCzatt_cxx
#include "ProtonMC.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <TVector3.h>

//=================================================================================|
//===                         Histograms Defined Here                           ===|
//=================================================================================|

//--- Primary Particle Start X Position ---|
TH1D *hMCPrimaryStartX = new TH1D("hMCPrimaryStartX", "Primary Particle X_{0}", 200, -50, 50);
//--- Primary Particle Start Y Position ---|
TH1D *hMCPrimaryStartY = new TH1D("hMCPrimaryStartY", "Primary Particle Y_{0}", 200, -50, 50);
//--- Primary Particle Start Z Position ---|
TH1D *hMCPrimaryStartZ = new TH1D("hMCPrimaryStartZ", "Primary Particle Z_{0}", 600, -120, 180);

//--- Primary Particle End X Position ---|
TH1D *hMCPrimaryEndX = new TH1D("hMCPrimaryEndX", "Primary Particle X_{f}", 120, -10, 50);
//--- Primary Particle End Y Position ---|
TH1D *hMCPrimaryEndY = new TH1D("hMCPrimaryEndY", "Primary Particle Y_{f}", 40, -20, 20);
//--- Primary Particle End Z Position ---|
TH1D *hMCPrimaryEndZ = new TH1D("hMCPrimaryEndZ", "Primary Particle Z_{f}", 200, -10, 90);

//--- Primary Particle End X vs Z Positions ---|
TH2D *hMCPrimaryEndXvsZ = new TH2D("hMCPrimaryEndXvsZ", "X_{f} vs Z_{f}", 200, -10, 90, 120, -10, 50);
//--- Primary Particle End Y vs Z Positions ---|
TH2D *hMCPrimaryEndYvsZ = new TH2D("hMCPrimaryEndYvsZ", "Y_{f} vs Z_{f}", 200, -10, 90, 40, -20, 20);

//--- Primary Particle Start X Position Inside TPC ---|
TH1D *hMCPrimaryTPCStartX = new TH1D("hMCPrimaryTPCStartX", "Primary Particle X_{0} Inside TPC", 200, -50, 50);
//--- Primary Particle Start Y Position Inside TPC ---|
TH1D *hMCPrimaryTPCStartY = new TH1D("hMCPrimaryTPCStartY", "Primary Particle Y_{0} Inside TPC", 200, -50, 50);
//--- Primary Particle Start Z Position Inside TPC ---|
TH1D *hMCPrimaryTPCStartZ = new TH1D("hMCPrimaryTPCStartZ", "Primary Particle Z_{0} Inside TPC", 600, -120, 180);

//--- Primary Particle Initial Px ---|
TH1D *hMCPrimaryPxUnWeighted = new TH1D("hMCPrimaryPxUnWeighted", "Primary Particle P_{x_0}", 300, -150, 150);
//--- Primary Particle Initial Py ---|
TH1D *hMCPrimaryPyUnWeighted = new TH1D("hMCPrimaryPyUnWeighted", "Primary Particle P_{y_0}", 300, -150, 150);
//--- Primary Particle Initial Pz ---|
TH1D *hMCPrimaryPzUnWeighted = new TH1D("hMCPrimaryPzUnWeighted", "Primary Particle P_{z_0}", 250, 0, 2500);

//=================================================================================|


void dEdxProtonMCzatt::Loop()
{

//==========================================|
//=== Counters for Event Reduction Table ===|
//==========================================|

int nTotalEvents = 0;
int TrueStoppingParticle = 0; 
int nRecoEvents = 0;

//==========================================|

//============================================================================|
//=== Fiducial Boundary Cuts (Used for Determining if a Track is Stopping) ===|
//============================================================================|

double XLowerFid = 0;
double XUpperFid = 47;

double YLowerFid = -20;
double YUpperFid = 20;

double ZLowerFid = 0;
double ZUpperFid = 90;

//============================================================================|

//======================================|
//=== Loading the Calibration Tables ===|
//======================================|

TFile *f1 = new TFile("./DataDrivenProtonMC_EnergyCalibrationTable.root");

//======================================|

if (fChain == 0) return;
Long64_t nentries = fChain->GetEntriesFast();
Long64_t nbytes = 0, nb = 0;

//===========================|
//=== Looping Over Events ===|
//===========================|

for (Long64_t jentry=0; jentry<nentries; jentry++)
   {
   Long64_t ientry = LoadTree(jentry);
   if (ientry < 0) break;
   nb = fChain->GetEntry(jentry);   nbytes += nb;

   //-----------------------------|
   //--- Counting Total Events ---|
   //-----------------------------|
   
   nTotalEvents++;

   //-----------------------------|

   //----------------------------------------------|
   //--- Outputting Every nEvents to the Screen ---|
   //----------------------------------------------|

   if(nTotalEvents % 1000 == 0){std::cout<<"Event = "<<nTotalEvents<<std::endl;}

   //----------------------------------------------|

//################################################################################|
//###                      GEANT 4 Information                  ###|

//===========================|
