#include "subsystems/harvester.h"

harvester::harvester() {
  // Implementation of subsystem constructor goes here.
  m_motorHarvester.ConfigFactoryDefault();
}

void harvester::RunHarvester(const HarvesterDirection& direction) {
  switch(direction) {
    case HarvesterDirection::kForward :
      MoveHarvester(PneumaticsDirection::kOut);
      m_motorHarvester.Set(harvesterConstants::motorMaxOutput);
      break;
    case HarvesterDirection::kReverse :
      MoveHarvester(PneumaticsDirection::kOut);
      m_motorHarvester.Set(-harvesterConstants::motorMaxOutput);
      break;
    case HarvesterDirection::kOff :
      MoveHarvester(PneumaticsDirection::kIn);
      m_motorHarvester.Set(0);
      break;
    default :
      MoveHarvester(PneumaticsDirection::kIn);
      m_motorHarvester.Set(0);
      throw std::invalid_argument("Invalid HarvesterDirection.\n");
  }
}

void harvester::MoveHarvester(const PneumaticsDirection& direction) {
  switch(direction) {
    case PneumaticsDirection::kOut :
      m_doubleSolenoidLeft.Set(frc::DoubleSolenoid::Value::kForward);
      m_doubleSolenoidRight.Set(frc::DoubleSolenoid::Value::kForward);
      break;
    case PneumaticsDirection::kIn :
      m_doubleSolenoidLeft.Set(frc::DoubleSolenoid::Value::kReverse);
      m_doubleSolenoidRight.Set(frc::DoubleSolenoid::Value::kReverse);
      break;
    default :
      m_doubleSolenoidLeft.Set(frc::DoubleSolenoid::Value::kOff);
      m_doubleSolenoidRight.Set(frc::DoubleSolenoid::Value::kOff);
      throw std::invalid_argument("Invalid PneumaticsDirection.\n");
  }
}

void harvester::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void harvester::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}
