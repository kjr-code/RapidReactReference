#include "subsystems/shooter.h"

shooter::shooter() {
  // Implementation of subsystem constructor goes here.
  m_PIDShooter.SetP(shooterkP);
  m_PIDShooter.SetI(shooterkI);
  m_PIDShooter.SetD(shooterkD);
  m_PIDShooter.SetFF(shooterFF); 
  m_PIDShooter.SetOutputRange(-1, 1);
  m_motorShooter.SetInverted(shooterInverted);
  //frc::SmartDashboard::PutNumber("ShootLowSpeed", lowSpeedBase);
  //frc::SmartDashboard::PutNumber("ShootHighSpeed", highSpeedBase);
  //frc::SmartDashboard::PutNumber("FF gain", shooterFF);
  //frc::SmartDashboard::PutNumber("P Gain", shooterkP);
  //frc::SmartDashboard::PutNumber("I Gain", shooterkI);
  //frc::SmartDashboard::PutNumber("D Gain", shooterkD);
}

void shooter::RunShooter(const ShooterBehavior& behavior) {
  //int speed = 0;
  switch(behavior) {
    case ShooterBehavior::kHigh :
      //speed = frc::SmartDashboard::GetNumber("ShootHighSpeed", highSpeedBase);
      //m_PIDShooter.SetReference(speed, 
                                //rev::CANSparkMax::ControlType::kVelocity);
      //m_motorShooter.SetVoltage(units::volt_t(speed));
      ShootHigh();
      break;
    case ShooterBehavior::kLow :
      //speed = frc::SmartDashboard::GetNumber("ShootLowSpeed", lowSpeedBase);
      //m_motorShooter.SetVoltage(units::volt_t(speed));
      //m_PIDShooter.SetReference(speed, 
                               // rev::CANSparkMax::ControlType::kVelocity);
      m_motorShooter.SetVoltage(units::volt_t(shootLowSpeed));
      break;
    case ShooterBehavior::kOff :
      //m_PIDShooter.SetReference(0, rev::CANSparkMax::ControlType::kVelocity);
      m_motorShooter.SetVoltage(units::volt_t(0));
      break;
    default :
      m_PIDShooter.SetReference(0, rev::CANSparkMax::ControlType::kVelocity);
  }
}

void shooter::ShootHigh() {
  m_distanceToTargetIn = DistanceToTargetIn();

  m_voltage = 0.426*std::pow(m_distanceToTargetIn, 0.5039); // need to use a spreadsheet to calculate shoot function based on distance and add that function here

  if (m_voltage < 10) {
    //m_PIDShooter.SetReference(m_RPM, rev::CANSparkMax::ControlType::kVelocity);
    m_motorShooter.SetVoltage(units::volt_t(m_voltage)); 
  }
  
}

double shooter::DistanceToTargetIn() {
  double distance;
  m_targetAngle = ty;

  m_totalAngleToTargetRAD = (m_targetAngle + m_limelightAngle) * (3.14 / 180);

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

  frc::SmartDashboard::PutNumber("Distance From Target Inches", DistanceToTargetIn());
  frc::SmartDashboard::PutNumber("Calculated voltage", m_voltage);
  frc::SmartDashboard::PutNumber("currentRPM", m_encoder.GetVelocity());
  m_PIDShooter.SetFF(frc::SmartDashboard::GetNumber("FF Gain", shooterFF));
  m_PIDShooter.SetP(frc::SmartDashboard::GetNumber("P Gain", shooterkP));
  m_PIDShooter.SetI(frc::SmartDashboard::GetNumber("I Gain", shooterkI));
  m_PIDShooter.SetD(frc::SmartDashboard::GetNumber("D Gain", shooterkD));

}

void shooter::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}