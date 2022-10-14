#include "subsystems/climber.h"

climber::climber() {
  // Implementation of subsystem constructor goes here.
}

void climber::RunClimb(const ClimbDirection& direction) {
  switch(direction) {
    case ClimbDirection::kUp :
      m_doubleSolenoid.Set(frc::DoubleSolenoid::Value::kForward);
      break;
    case ClimbDirection::kDown :
      m_doubleSolenoid.Set(frc::DoubleSolenoid::Value::kReverse);
      break;
    default :
      m_doubleSolenoid.Set(frc::DoubleSolenoid::Value::kOff);
      throw std::invalid_argument("Invalid ClimbDirection.\n");
      break;
  }
}

void climber::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void climber::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}
