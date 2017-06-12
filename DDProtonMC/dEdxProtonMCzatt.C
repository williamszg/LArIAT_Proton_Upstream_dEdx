#define ProtonMC_cxx
#include "ProtonMC.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <TVector3.h>

//=================================================================================|
//===============                                                   ===============|
//===                         Histograms Defined Here                           ===|
//===============                                                   ===============|
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




//--- Initial Kinetic Energy ---|
TH1D *hMCTrueInitialKE = new TH1D("hMCTrueInitialKE", "Initial Kinetic Energy (MC Truth)", 1100, -100, 1000);

//--- Energy Loss in the Upstream Region of the Beamline ---|
TH1D *hMCTrueELossUpstream = new TH1D("hMCTrueELossUpstream", "Energy Loss Prior to Entering the TPC (MC Truth)", 1100, -100, 1000);

//--- Energy Loss in the TPC ---|
TH1D *hMCTrueELossInTPC = new TH1D("hMCTrueELossInTPC", "Energy Loss Inside the TPC (MC Truth)", 1100, -100, 1000);

//--- Final Kinetic Energy in the TPC ---|
TH1D *hMCTrueERemain = new TH1D("hMCTrueERemain", "Remaining Energy (MC Truth)", 1000, -50, 50);

//--- Energy Loss Upstream of the TPC ---|
TH2D *hELossXvsY = new TH2D("hELossXvsY", "Energy Loss X vs Y", 200, 0, 50, 200, -25, 25);

//--- Energy Loss Upstream of the Flux TPC ---|
TH2D *hELossXvsYFlux = new TH2D("hELossXvsYFlux", "Energy Loss X vs Y", 200, 0, 50, 200, -25, 25);

//--- Divided Energy Loss ---|
TH2D *hELossXvsYDivide = new TH2D("hELossXvsYDivide", "Energy Loss X vs Y", 200, 0, 50, 200, -25, 25);

//--- MC Theta ---|
TH1D *hMCThetaAtFrontFace = new TH1D("hMCThetaAtFrontFace", "#theta at the Front Face of the TPC", 80, -10, 30);

//--- MC Phi ---|
TH1D *hMCPhiAtFrontFace = new TH1D("hMCPhiAtFrontFace", "#phi at the Front Face of the TPC", 360, 0, 360);

//--- Phi vs Theta Energy Loss ---|
TH2D *hPhivsThetaELoss = new TH2D("hPhivsThetaELoss", "#phi vs #theta Energy Loss", 360, 0, 360, 40, -10, 30);

//--- Phi vs Theta Energy Loss Flux ---|
TH2D *hPhivsThetaELossFlux = new TH2D("hPhivsThetaELossFlux", "#phi vs #theta Energy Loss", 360, 0, 360, 40, -10, 30);

//--- Phi vs Theta Energy Loss Divided ---|
TH2D *hPhivsThetaELossDivide = new TH2D("hPhivsThetaELossDivide", "#phi vs #theta Energy Loss", 360, 0, 360, 40, -10, 30);

//--- Energy Loss Upstream vs Particle Pz ---|
TH2D *hMCPrimaryPzvsELossUpstream = new TH2D("hMCPrimaryPzvsELossUpstream", "Energy Loss Upstream vs Primary Particle P_{z}", 250, 0, 2500, 1100, -100, 1000);




//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|
//+++ Not Weird Energy Loss Peak Two Dimensional Histograms +++|
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|

//--- Not Weird Energy Loss Peak X vs Z ---|
TH2D *hMCPrimaryXvsZNotWeirdPeak = new TH2D("hMCPrimaryXvsZNotWeirdPeak", "X vs Z", 200, -100, 10, 120, -10, 50);
//--- Not Weird Energy Loss Peak Y vs Z ---|
TH2D *hMCPrimaryYvsZNotWeirdPeak = new TH2D("hMCPrimaryYvsZNotWeirdPeak", "Y vs Z", 200, -100, 10, 40, -20, 20);

//--- Not Weird Energy Loss Peak X vs Z Flux ---|
TH2D *hMCPrimaryXvsZNotWeirdPeakFlux = new TH2D("hMCPrimaryXvsZNotWeirdPeakFlux", "X vs Z", 200, -100, 10, 120, -10, 50);
//--- Not Weird Energy Loss Peak Y vs Z Flux ---|
TH2D *hMCPrimaryYvsZNotWeirdPeakFlux = new TH2D("hMCPrimaryYvsZNotWeirdPeakFlux", "Y vs Z", 200, -100, 10, 40, -20, 20);

//--- Not Weird Energy Loss Peak X vs Z Divide ---|
TH2D *hMCPrimaryXvsZNotWeirdPeakDivide = new TH2D("hMCPrimaryXvsZNotWeirdPeakDivide", "X vs Z", 200, -100, 10, 120, -10, 50);
//--- Not Weird Energy Loss Peak Y vs Z Divide ---|
TH2D *hMCPrimaryYvsZNotWeirdPeakDivide = new TH2D("hMCPrimaryYvsZNotWeirdPeakDivide", "Y vs Z", 200, -100, 10, 40, -20, 20);

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|




//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++|
//+++ Weird Energy Loss Peak Two Dimensional Histograms +++|
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++|

//--- Weird Energy Loss Peak X vs Z ---|
TH2D *hMCPrimaryXvsZWeirdPeak = new TH2D("hMCPrimaryXvsZWeirdPeak", "X vs Z", 200, -100, 10, 120, -10, 50);
//--- Weird Energy Loss Peak Y vs Z ---|
TH2D *hMCPrimaryYvsZWeirdPeak = new TH2D("hMCPrimaryYvsZWeirdPeak", "Y vs Z", 200, -100, 10, 40, -20, 20);

//--- Weird Energy Loss Peak X vs Z Flux ---|
TH2D *hMCPrimaryXvsZWeirdPeakFlux = new TH2D("hMCPrimaryXvsZWeirdPeakFlux", "X vs Z", 200, -100, 10, 120, -10, 50);
//--- Weird Energy Loss Peak Y vs Z Flux ---|
TH2D *hMCPrimaryYvsZWeirdPeakFlux = new TH2D("hMCPrimaryYvsZWeirdPeakFlux", "Y vs Z", 200, -100, 10, 40, -20, 20);

//--- Weird Energy Loss Peak X vs Z Divide ---|
TH2D *hMCPrimaryXvsZWeirdPeakDivide = new TH2D("hMCPrimaryXvsZWeirdPeakDivide", "X vs Z", 200, -100, 10, 120, -10, 50);
//--- Weird Energy Loss Peak Y vs Z Divide ---|
TH2D *hMCPrimaryYvsZWeirdPeakDivide = new TH2D("hMCPrimaryYvsZWeirdPeakDivide", "Y vs Z", 200, -100, 10, 40, -20, 20);

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++|




//------------------------------------------------------------------|
//--- Phi vs Theta Loss for Different Cuts (Top, Middle, Bottom) ---|
//------------------------------------------------------------------|

//++++++++++++++++++++++++++++++++++++++++++++++|
//+++ Phi vs Theta Loss for -15cm < Y < -5cm +++|
//++++++++++++++++++++++++++++++++++++++++++++++|

//--- Phi vs Theta Energy Loss Bottom ---|
TH2D *hPhivsThetaELossBottom = new TH2D("hPhivsThetaELossBottom", "#phi vs #theta Energy Loss Bottom", 72, 0, 360, 8, -10, 30);
//--- Phi vs Theta Energy Loss Flux Bottom ---|
TH2D *hPhivsThetaELossFluxBottom = new TH2D("hPhivsThetaELossFluxBottom", "#phi vs #theta Energy Loss Flux Bottom", 72, 0, 360, 8, -10, 30);
//--- Phi vs Theta Energy Loss Divide Bottom ---|
TH2D *hPhivsThetaELossDivideBottom = new TH2D("hPhivsThetaELossDivideBottom", "#phi vs #theta Energy Loss Divide Bottom", 72, 0, 360, 8, -10, 30);

//++++++++++++++++++++++++++++++++++++++++++++++|

//++++++++++++++++++++++++++++++++++++++++++++++|
//+++  Phi vs Theta Loss for -5cm < Y < 5cm  +++|
//++++++++++++++++++++++++++++++++++++++++++++++|

//--- Phi vs Theta Energy Loss Middle ---|
TH2D *hPhivsThetaELossMid = new TH2D("hPhivsThetaELossMid", "#phi vs #theta Energy Loss Middle", 72, 0, 360, 8, -10, 30);
//--- Phi vs Theta Energy Loss Flux Middle ---|
TH2D *hPhivsThetaELossFluxMid = new TH2D("hPhivsThetaELossFluxMid", "#phi vs #theta Energy Loss Flux Middle", 72, 0, 360, 8, -10, 30);
//--- Phi vs Theta Energy Loss Divide Middle ---|
TH2D *hPhivsThetaELossDivideMid = new TH2D("hPhivsThetaELossDivideMid", "#phi vs #theta Energy Loss Divide Middle", 72, 0, 360, 8, -10, 30);

//++++++++++++++++++++++++++++++++++++++++++++++|

//++++++++++++++++++++++++++++++++++++++++++++++|
//+++  Phi vs Theta Loss for 5cm < Y < 15cm  +++|
//++++++++++++++++++++++++++++++++++++++++++++++|

//--- Phi vs Theta Energy Loss Top ---|
TH2D *hPhivsThetaELossTop = new TH2D("hPhivsThetaELossTop", "#phi vs #theta Energy Loss Top", 72, 0, 360, 8, -10, 30);
//--- Phi vs Theta Energy Loss Flux Top ---|
TH2D *hPhivsThetaELossFluxTop = new TH2D("hPhivsThetaELossFluxTop", "#phi vs #theta Energy Loss Flux Top", 72, 0, 360, 8, -10, 30);
//--- Phi vs Theta Energy Loss Divide Top ---|
TH2D *hPhivsThetaELossDivideTop = new TH2D("hPhivsThetaELossDivideTop", "#phi vs #theta Energy Loss Divide Top", 72, 0, 360, 8, -10, 30);

//++++++++++++++++++++++++++++++++++++++++++++++|

//------------------------------------------------------------------|




//--- Energy Loss in the Upstream Region of the Beamline ---|
TH1D *hMCELossUpstreamLookUp = new TH1D("hMCELossUpstreamLookUp", "Energy Loss Prior to Entering the TPC (Map)", 1100, -100, 1000);

//--- Final Kinetic Energy in the TPC Using Map ---|
TH1D *hERemainMCMap = new TH1D("hERemainMCMap", "Remaining Energy from MC Map", 1000, -75, 75);

//--- Delta Energy Loss Between True and Map ---|
TH1D *hDeltaEnergyLossTruevsMap = new TH1D("hDeltaEnergyLossTruevsMap", "#Delta Energy Loss Upstream (True - Map)", 1000, -75, 75);

//--- Energy Loss in the Upstream Region of the Beamline Flat Method ---|
TH1D *hMCELossUpstreamFlat = new TH1D("hMCELossUpstreamFlat", "Energy Loss Prior to Entering the TPC (Flat 66.6 MeV)", 1100, -100, 1000);

//--- Final Kinetic Energy in the TPC Using Map ---|
TH1D *hERemainMCFlat = new TH1D("hERemainMCFlat", "Remaining Energy from MC Using Flat 66.6 MeV", 1000, -75, 75);




//--- "Matched Track" dE/dX ---|
TH1D *hRecoMCdEdX = new TH1D("hRecoMCdEdX", "Matched Track dE/dX", 200, 0, 50);

//--- "Matched Track" Residual Range ---|
TH1D *hRecoMCResidualRange = new TH1D("hRecoMCResidualRange", "Matched Track Residual Range", 400, -100, 100);

//--- "Matched Track" Track Pitch ---|
TH1D *hRecoMCTrkPitch = new TH1D("hRecoMCTrkPitch", "Matched Track Pitch", 1000, 0, 5);

//--- "Matched Track" dE/dX vs RR ---|
TH2D *hRecoMCdEdXvsRR = new TH2D("hRecoMCdEdXvsRR", "dE/dX vs Residual Range", 200, 0, 100, 200, 0, 50);

//--- Energy Loss in the TPC (Reco) ---|
TH1D *hMCELossRecoInTPC = new TH1D("hMCELossRecoInTPC", "Reconstructed Energy Loss Inside the TPC", 1100, -100, 1000);

//--- TPC Track Phi at the Upstream Point ---|
TH1D *hRecoMCTPCPhi = new TH1D("hRecoMCTPCPhi", "TPC Track #phi", 360, 0, 360);
//--- TPC Track Theta at the Upstream Point ---|
TH1D *hRecoMCTPCTheta = new TH1D("hRecoMCTPCTheta", "TPC Track #theta", 180, 0, 90);

//--- Reconstructed Particle Start X Position Inside TPC ---|
TH1D *hRecoMCTPCStartX = new TH1D("hRecoMCTPCStartX", "Reconstructed X_{0} Inside TPC", 200, -50, 50);
//--- Reconstructed Particle Start Y Position Inside TPC ---|
TH1D *hRecoMCTPCStartY = new TH1D("hRecoMCTPCStartY", "Reconstructed Y_{0} Inside TPC", 200, -50, 50);
//--- Reconstructed Particle Start Z Position Inside TPC ---|
TH1D *hRecoMCTPCStartZ = new TH1D("hRecoMCTPCStartZ", "Reconstructed Z_{0} Inside TPC", 600, -120, 180);

//--- Final Kinetic Energy in the TPC Using TPC Reco Only ---|
TH1D *hERemainTPCRecoOnly = new TH1D("hERemainTPCRecoOnly", "Remaining Energy Using TPC Reco Energy", 1000, -75, 75);

//--- Energy Loss in the Upstream Region of the Beamline Using TPC Theta and Phi ---|
TH1D *hMCELossUpstreamTPCRecoMap = new TH1D("hMCELossUpstreamTPCRecoMap", "Energy Loss Prior to Entering the TPC (Using Reco TPC #theta and #phi)", 1100, -100, 1000);

//--- Delta Energy Loss in TPC Between True and dE/dX ---|
TH1D *hDeltaEnergyLossInTPCTruevsReco = new TH1D("hDeltaEnergyLossInTPCTruevsReco", "#Delta Energy Loss in the TPC (True - Reco)", 1000, -75, 75);

//=================================================================================|
//=================================================================================|


void ProtonMC::Loop()
{

float particle_mass = 938.28;

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

   //#####################################################################|
   //#####################################################################|
   //#########                                                   #########|
   //###                      GEANT 4 Information                      ###|
   //#########                                                   #########|
   //#####################################################################|
   //#####################################################################|

   bool EventsWhereParticleStops = false;

   int nG4Primary = 0;
   int nG4TrajPoints = 0;

   float g4Primary_X0[100] = {0.}, g4Primary_Y0[100] = {0.}, g4Primary_Z0[100] = {0.};
   float g4Primary_Xf[100] = {0.}, g4Primary_Yf[100] = {0.}, g4Primary_Zf[100] = {0.};
   float g4Primary_Px[100] = {0.}, g4Primary_Py[100] = {0.}, g4Primary_Pz[100] = {0.};
   float g4PrimaryEnd_Px[100] = {0.}, g4PrimaryEnd_Py[100] = {0.}, g4PrimaryEnd_Pz[100] = {0.};

   //----------------------------------------------------------------------------|
   //---   Defining Variables for the Momentum at the Front Face of the TPC   ---|
   //----------------------------------------------------------------------------|

   float FrontFace_Px = 0, FrontFace_Py = 0, FrontFace_Pz = 0;

   //----------------------------------------------------------------------------|

   //---------------------------------|
   //--- Variables for Energy Loss ---|
   //---------------------------------|

   float EnergyLossOutsideTPC = 0;
   float EnergyLossInsideTPC = 0;
   float ERemainingMCTrue = 9999;
   float ERemainingMCMap = 9999;
   float ERemainingMCDumbFlat = 9999;
   float RecoEnergyLossInsideTPC = 0;
   float EnergyRemainingRecoTPCOnly = 9999;
   float InitialKineticEnergy = 0;
   float EnergyLossFromMap = 0;

   //---------------------------------|
   
   //**********************************|
   //*** Loop Over All G4 Particles ***|
   //**********************************|

   for (int iG4 = 0; iG4 < geant_list_size; iG4++)
      {
      
      //#################################################################|
      //### Set to True if This Event is a Stopping Proton in the TPC ###|
      //#################################################################|

      if (pdg[iG4] == 2212 && process_primary[iG4] == 1 && NumberDaughters[iG4] == 0 &&
          EndPointz[iG4] > 0 && EndPointz[iG4] < 90 && 
	  EndPointy[iG4] > -20 && EndPointy[iG4] < 20 &&
	  EndPointx[iG4] > 0 && EndPointx[iG4] < 20) {EventsWhereParticleStops = true;}

      else {continue;}

      //--- Recording Information for Use Later ---|
      g4Primary_X0[nG4Primary] = StartPointx[iG4];
      g4Primary_Y0[nG4Primary] = StartPointy[iG4];
      g4Primary_Z0[nG4Primary] = StartPointz[iG4];

      g4Primary_Xf[nG4Primary] = EndPointx[iG4];
      g4Primary_Yf[nG4Primary] = EndPointy[iG4];
      g4Primary_Zf[nG4Primary] = EndPointz[iG4];

      g4Primary_Px[nG4Primary] = Px[iG4] * 1000; //<---Converting to MeV
      g4Primary_Py[nG4Primary] = Py[iG4] * 1000; //<---Converting to MeV
      g4Primary_Pz[nG4Primary] = Pz[iG4] * 1000; //<---Converting to MeV

      //--------------------------|
      //--- Filling Histograms ---|
      //--------------------------|

      hMCPrimaryPxUnWeighted->Fill(g4Primary_Px[nG4Primary]);
      hMCPrimaryPyUnWeighted->Fill(g4Primary_Py[nG4Primary]);
      hMCPrimaryPzUnWeighted->Fill(g4Primary_Pz[nG4Primary]);

      hMCPrimaryStartX->Fill(StartPointx[iG4]);
      hMCPrimaryStartY->Fill(StartPointy[iG4]);
      hMCPrimaryStartZ->Fill(StartPointz[iG4]);

      hMCPrimaryEndX->Fill(EndPointx[iG4]);
      hMCPrimaryEndY->Fill(EndPointy[iG4]);
      hMCPrimaryEndZ->Fill(EndPointz[iG4]);

      hMCPrimaryEndXvsZ->Fill(EndPointz[iG4], EndPointx[iG4]);
      hMCPrimaryEndYvsZ->Fill(EndPointz[iG4], EndPointy[iG4]);

      //--------------------------|

      //#################################################################|

      //#############################################################|
      //### Calculating the Momentum from the MC Primary Particle ###|
      //#############################################################|

      float momentumScale = sqrt( (g4Primary_Px[nG4Primary]*g4Primary_Px[nG4Primary]) +
		                  (g4Primary_Py[nG4Primary]*g4Primary_Py[nG4Primary]) +
				  (g4Primary_Pz[nG4Primary]*g4Primary_Pz[nG4Primary]) );

      InitialKineticEnergy = sqrt( (momentumScale*momentumScale) + 
		                   (particle_mass*particle_mass) ) - particle_mass;

      hMCTrueInitialKE->Fill(InitialKineticEnergy);

      //--- Defining First Point ---|
      float FirstPoint_Z = 999;
      float FirstPoint_Y = 999;
      float FirstPoint_X = 999;

      EnergyLossOutsideTPC = 0;

      //#############################################################|

      //##################################################|
      //### Looping Over All Primary Trajectory Points ###|
      //##################################################|

      for (int iPriTrj = 1; iPriTrj < NTrTrajPts[iG4]; iPriTrj++)
	 {
         
         //--- Only Looking at Points Which Are Upstream of the TPC ---|
	 if (MidPosZ[iG4][iPriTrj] < 0)
            {

	    float Momentum_Point1 = ( sqrt( (MidPx[iG4][iPriTrj-1]*MidPx[iG4][iPriTrj-1]) +
				      (MidPy[iG4][iPriTrj-1]*MidPy[iG4][iPriTrj-1]) + 
				      (MidPz[iG4][iPriTrj-1]*MidPz[iG4][iPriTrj-1]) ) )*1000;

	    float Momentum_Point2 = ( sqrt( (MidPx[iG4][iPriTrj]*MidPx[iG4][iPriTrj]) +
				      (MidPy[iG4][iPriTrj]*MidPy[iG4][iPriTrj]) + 
				      (MidPz[iG4][iPriTrj]*MidPz[iG4][iPriTrj]) ) )*1000;

	    float Energy_UpstreamPoint1 = sqrt( (Momentum_Point1*Momentum_Point1) +
			                        (particle_mass*particle_mass) ) - particle_mass;

	    float Energy_UpstreamPoint2 = sqrt( (Momentum_Point2*Momentum_Point2) +
			                        (particle_mass*particle_mass) ) - particle_mass;

	    EnergyLossOutsideTPC += Energy_UpstreamPoint1 - Energy_UpstreamPoint2;

	    }//<---End looking at energy loss upstream of TPC

	 //--- Only Looking at Points Which Are Inside of the TPC --|
	 if (MidPosZ[iG4][iPriTrj] >= 0 && MidPosZ[iG4][iPriTrj] < 90 &&
	     MidPosY[iG4][iPriTrj] > -20 && MidPosY[iG4][iPriTrj] < 20 &&
	     MidPosX[iG4][iPriTrj] > 0 && MidPosX[iG4][iPriTrj] < 47)
            {

	    float Momentum_Point1 = ( sqrt( (MidPx[iG4][iPriTrj-1]*MidPx[iG4][iPriTrj-1]) +
				      (MidPy[iG4][iPriTrj-1]*MidPy[iG4][iPriTrj-1]) + 
				      (MidPz[iG4][iPriTrj-1]*MidPz[iG4][iPriTrj-1]) ) )*1000;

	    float Momentum_Point2 = ( sqrt( (MidPx[iG4][iPriTrj]*MidPx[iG4][iPriTrj]) +
				      (MidPy[iG4][iPriTrj]*MidPy[iG4][iPriTrj]) + 
				      (MidPz[iG4][iPriTrj]*MidPz[iG4][iPriTrj]) ) )*1000;
           
	    //--- Storing the Upstream Point ---|
	    if (MidPosZ[iG4][iPriTrj] < FirstPoint_Z)
	       {
               FirstPoint_Z = MidPosZ[iG4][iPriTrj];
               FirstPoint_Y = MidPosY[iG4][iPriTrj];
               FirstPoint_X = MidPosX[iG4][iPriTrj];

	       FrontFace_Px = MidPx[iG4][iPriTrj] * 1000;
	       FrontFace_Py = MidPy[iG4][iPriTrj] * 1000;
	       FrontFace_Pz = MidPz[iG4][iPriTrj] * 1000;

	       }

	    float Energy_Point1 = sqrt( (Momentum_Point1*Momentum_Point1) +
			                (particle_mass*particle_mass) ) - particle_mass;

	    float Energy_Point2 = sqrt( (Momentum_Point2*Momentum_Point2) +
			                (particle_mass*particle_mass) ) - particle_mass;

            EnergyLossInsideTPC += Energy_Point1 - Energy_Point2;

	    }

	 }

      //##################################################|

      //--- Filling Initial TPC Information ---|
      hMCPrimaryTPCStartX->Fill(FirstPoint_X);
      hMCPrimaryTPCStartY->Fill(FirstPoint_Y);
      hMCPrimaryTPCStartZ->Fill(FirstPoint_Z);

      //--- Filling Histograms for Energy Loss ---|
      hMCTrueELossUpstream->Fill(EnergyLossOutsideTPC);
      hMCTrueELossInTPC->Fill(EnergyLossInsideTPC);
   
      hELossXvsY->Fill(FirstPoint_X, FirstPoint_Y, EnergyLossOutsideTPC);
      hELossXvsYFlux->Fill(FirstPoint_X, FirstPoint_Y);

      hMCPrimaryPzvsELossUpstream->Fill(momentumScale, EnergyLossOutsideTPC);



      
   //**********************************|

      }
   
   //#####################################################################|   
   //#####################################################################|




   //#####################################################################|
   //#####################################################################|
   //#########                                                   #########|
   //###                 Reconstructed Information                     ###|
   //#########                                                   #########|
   //#####################################################################|
   //#####################################################################|

   bool ReconstructedEvent = true;

   float MCRecodEdx[1000] = {0.};
   int nMCRecoSpts = 0;

   double MCRecoSptsX[1000];
   double MCRecoSptsY[1000];
   double MCRecoSptsZ[1000];

   double MCRecoResRange[1000] = {0.};
   double MCRecoPitch[1000] = {0.};

   double primary_track_length = 0;

   //******************************************|
   //*** Loop Over All Reconstructed Tracks ***|
   //******************************************|

   for (int nTPCtrk = 0; nTPCtrk < ntracks_reco; nTPCtrk++)
      {

      //---------------------------------------------------------------|
      //--- Looping Over the Calorimetry Spacepoints for this Track ---|
      //---------------------------------------------------------------|

      primary_track_length = trklength[nTPCtrk];
      for (int nspts = 0; nspts < ntrkhits[nTPCtrk]; nspts++)
	 {
         MCRecodEdX[nMCRecoSpts] = trkdedx[nTPCtrk][1][nspts];
	 //&&& Fix for Negative dEdX &&&
	 if (MCRecodEdX[nMCRecoSpts] < 0 && nspts < ntrkhits[nTPCtrk] && nspts > 0)
            {
	    MCRecodEdX[nMCRecoSpts] = ( (trkdedx[nTPCtrk][1][nspts - 1] + trkdedx[nTPCtrk][1][nspts + 1]) / 2);
	    }
         //&&& If it Didn't Fix it, Skip it &&&
	 if (MCRecodEdX[nMCRecoSpts] < 0) {continue;}

         }

      //---------------------------------------------------------------|

      }

   //******************************************|

   //#####################################################################|   
   //#####################################################################|

//===========================|





//--- Creating a File to Store the Histograms ---|
TFile myfile("./DDProtonMC_EnergyCalibrationHistograms.root", "CREATE");


//-------------------------------|
//--- Dividing the Histograms ---|
//-------------------------------|



//-------------------------------|


//=========================================|
//=== Writing the Histograms to My File ===|
//=========================================|



//=========================================|

}
