#include "PhysicsList.hh"

#include <G4EmStandardPhysics.hh>
#include <G4DecayPhysics.hh> 
#include <G4ProductionCutsTable.hh>
#include <G4SystemOfUnits.hh>
#include <G4EmLivermorePhysics.hh>
#include <G4EmExtraPhysics.hh>
#include <G4EmExtraPhysics.hh>
#include <G4HadronElasticPhysics.hh>
#include <G4HadronPhysicsFTFP_BERT.hh>

// Task 3b.1: Include header for G4EmLivermorePhysics
// Task 3b.2: Include header for G4EmExtraPhysics
// Task 3b.3: Include headers for hadronic physics

PhysicsList::PhysicsList() : G4VModularPhysicsList()
{
  // Standard EM physics 
  // Task 3b.1: Replace G4EmStandardPhysics with G4EmLivermorePhysics
  RegisterPhysics(new G4EmStandardPhysics());
  // RegisterPhysics(new G4EmLivermorePhysics);
 
  // Default Decay Physics
  RegisterPhysics(new G4DecayPhysics());

  // Task 3b.2 (add G4EmExtraPhysics)
  RegisterPhysics(new G4EmExtraPhysics());
  // Task 3b.3: Add hadronic physics  
  RegisterPhysics(new G4HadronElasticPhysics());
  RegisterPhysics(new G4HadronPhysicsFTFP_BERT());
}

void PhysicsList::SetCuts()
{
  // The method SetCuts() is mandatory in the interface. Here, one just use 
  // the default SetCuts() provided by the base class.
  G4VUserPhysicsList::SetCuts();
  
  // Task 3c.1: Temporarily update the production cuts table energy range
   G4ProductionCutsTable::GetProductionCutsTable()->SetEnergyRange(100*eV,100.*GeV);
  // In addition, dump the full list of cuts for the materials used in 
  // the setup
  DumpCutValuesTable();  
}
