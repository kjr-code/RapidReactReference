#include "subsystems/shooter.h"

shooter::shooter() {
  // Implementation of subsystem constructor goes here.
  m_motorShooter.EnableVoltageCompensation(nominalVoltage);
  m_PIDShooter.SetP(shooterkP);
  m_PIDShooter.SetI(shooterkI);
  m_PIDShooter.SetD(shooterkD);
  m_PIDShooter.SetFF(shooterFF); 
}

void shooter::RunShooter(const ShooterBehavior& behavior) {
  switch(behavior) {
    case ShooterBehavior::kHigh :
      m_PIDShooter.SetReference(frc::SmartDashboard::GetNumber("ShootHighSpeed", highSpeedBase), 
                                rev::CANSparkMax::ControlType::kVelocity);
      //ShootHigh();
      break;
    case ShooterBehavior::kLow :
      m_PIDShooter.SetReference(frc::SmartDashboard::GetNumber("ShootLowSpeed", lowSpeedBase), 
                                rev::CANSparkMax::ControlType::kVelocity);
      //m_motorShooter.Set(shootLowSpeed);
      break;
    case ShooterBehavior::kOff :
      m_PIDShooter.SetReference(0, rev::CANSparkMax::ControlType::kVelocity);
      break;
    default :
      m_PIDShooter.SetReference(0, rev::CANSparkMax::ControlType::kVelocity);
      throw std::invalid_argument("Invalid ShooterBehavior.\n");
  }
}

void shooter::ShootHigh() {
  m_distanceToTargetIn = DistanceToTargetIn();

  m_RPM = 0; // need to use a spreadsheet to calculate shoot function based on distance and add that function here

  m_PIDShooter.SetReference(m_RPM, rev::CANSparkMax::ControlType::kVelocity);
}

double shooter::DistanceToTargetIn() {
  double distance;
  m_targetAngle = ty;

  m_totalAngleToTargetRAD = (m_targetAngle + m_limelightAngle) * (M_PI / 180);

  distance = (targetHeightIn - limelightHeightIn) / tan(m_totalAngleToTargetRAD);

  m_distanceToTargetIn = distance;

  return distance;
}

double shooter::GetError() {
  return -tx;
}

bool shooter::Goldilocks() {

  if (minDistanceFromTargetIn <= DistanceToTargetIn() && DistanceToTargetIn() <= maxDistanceFromTargetIn) {
    return true;
  } else {
    return false;
  }

}

void shooter::Periodic() {
  // Implementation of subsystem periodic method goes here.
  tx = nt::NetworkTableInstance::GetDefault().GetTable("limelight")->GetNumber("tx",0.0);
  ty = nt::NetworkTableInstance::GetDefault().GetTable("limelight")->GetNumber("ty",0.0);

  frc::SmartDashboard::PutNumber("Distance From Target Inches", m_distanceToTargetIn);
  frc::SmartDashboard::PutNumber("Calculated RPM", m_RPM);
}

void shooter::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}