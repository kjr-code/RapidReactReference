#include "subsystems/shooter.h"

shooter::shooter() {
  // Implementation of subsystem constructor goes here.
  m_motorShooter.RestoreFactoryDefaults();
}

void shooter::RunShooter(const ShooterBehavior& behavior, double percentOut) {
  switch(behavior) {
    case ShooterBehavior::kOn :
      m_motorShooter.Set(percentOut);
      break;
    case ShooterBehavior::kOff :
      m_motorShooter.Set(0);
      break;
    default :
      m_motorShooter.Set(0);
      throw std::invalid_argument("Invalid ShooterBehavior.\n");
  }
}

int shooter::Goldilocks() {

  return 1;
  
}

void shooter::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void shooter::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}