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
   float EnergyLossInside TPC = 0;
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

	    float Momentum_Point1 = ( sqrt((MidPx[iG4][iPriTrj-1]*MidPx[iG4][iPriTrj-1]) +
				      (MidPy[iG4][iPriTrj-1]*MidPy[iG4][iPriTrj-1]) + 
				      (MidPz[iG4][iPriTrj-1]*MidPz[iG4][iPriTrj-1])) )*1000;

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

            

	    }

      //##################################################|

   //**********************************|
   
   //#####################################################################|   
   //#####################################################################|

//===========================|
