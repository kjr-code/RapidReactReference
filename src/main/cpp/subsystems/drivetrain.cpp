#include "subsystems/drivetrain.h"

drivetrain::drivetrain() {
  // Implementation of subsystem constructor goes here.
  /*
  m_motorFrontLeft.ConfigAllSettings(m_talonFXConfiguration);
  m_motorRearLeft.ConfigAllSettings(m_talonFXConfiguration);
  m_motorFrontRight.ConfigAllSettings(m_talonFXConfiguration);
  m_motorRearRight.ConfigAllSettings(m_talonFXConfiguration);
  */

  //Inversion may be necessary this year because of changes to WPILib for 2022.
  //https://docs.wpilib.org/en/stable/docs/yearly-overview/yearly-changelog.html
  //m_motorFrontRight.SetInverted(true);
  //m_motorRearRight.SetInverted(true);

  m_motorFrontLeft.SetInverted(TalonFXInvertType::Clockwise);
  m_motorRearLeft.SetInverted(TalonFXInvertType::Clockwise);
  m_motorFrontRight.SetInverted(TalonFXInvertType::CounterClockwise);
  m_motorRearRight.SetInverted(TalonFXInvertType::CounterClockwise);

  m_motorFrontLeft.ConfigVoltageCompSaturation(satVoltage);
  m_motorFrontLeft.EnableVoltageCompensation(voltageComp);  
  m_motorRearLeft.ConfigVoltageCompSaturation(satVoltage);
  m_motorRearLeft.EnableVoltageCompensation(voltageComp);
  m_motorFrontRight.ConfigVoltageCompSaturation(satVoltage);
  m_motorFrontRight.EnableVoltageCompensation(voltageComp);
  m_motorRearRight.ConfigVoltageCompSaturation(satVoltage);
  m_motorRearRight.EnableVoltageCompensation(voltageComp);

  m_motorFrontLeft.SetSafetyEnabled(driveMotorSaftey);
  m_motorRearLeft.SetSafetyEnabled(driveMotorSaftey);
  m_motorFrontRight.SetSafetyEnabled(driveMotorSaftey);
  m_motorRearRight.SetSafetyEnabled(driveMotorSaftey);



  //m_mecanumDrive.SetDeadband(motorDeadband);
  //m_mecanumDrive.SetMaxOutput(motorMaxOutput);

  m_gyro.ZeroYaw();
}

void drivetrain::MecanumDriveJoystick(double xSpeed, double ySpeed, double zRotation) {
  double m_a = driveScalingCoefficient;
  // We need to invert input from joystick. -1 is forward with raw input.
  ySpeed = -ySpeed;
  zRotation = -zRotation;

  xSpeed = (m_a * pow(xSpeed, 3)) + ((1 - m_a) * xSpeed);
  ySpeed = (m_a * pow(ySpeed, 3)) + ((1 - m_a) * ySpeed);
  zRotation = (m_a * pow(zRotation, 3)) + ((1 - m_a) * zRotation);
  
  if (fieldOriented) {
    // Converts yaw from degrees to radians.
    m_adjYaw = (m_gyro.GetYaw() * 3.14 / 180);
  
    // DON'T TOUCH IF YOU DON'T UNDERSTAND THE TRIG:
    m_adjXSpeed = xSpeed*cos(m_adjYaw)-ySpeed*sin(m_adjYaw);
    m_adjYSpeed = ySpeed*cos(m_adjYaw)+xSpeed*sin(m_adjYaw);

    xSpeed = m_adjXSpeed;
    ySpeed = m_adjYSpeed;
  }
  // Alternate: m_mecanumDrive.DriveCartesian(m_adjXSpeed, m_adjYSpeed, zRotation);
  // m_mecanumDrive.DriveCartesian(m_adjYSpeed, m_adjXSpeed, zRotation);
  MecanumDrive(xSpeed, ySpeed, zRotation);

}

void drivetrain::MecanumDrive(double x, double y, double z) {
  double FL, BL, FR, BR, optimize;

  FL = x + y + z;
  BL = x - y + z;
  FR = x - y - z;
  BR = x + y - z;

  optimize = std::max(FL, std::max(BL, std::max(FR, std::max(BR, 1.00))));

  FL = FL / optimize;
  BL = BL / optimize;
  FR = FR / optimize;
  BR = BR / optimize;

  m_motorFrontLeft.Set(ControlMode::PercentOutput, FL);
  m_motorRearLeft.Set(ControlMode::PercentOutput, BL);
  m_motorFrontRight.Set(ControlMode::PercentOutput, FR);
  m_motorRearRight.Set(ControlMode::PercentOutput, BR);
}

void drivetrain::Center(double angleXOff) {
  double kP = shootAdjustmentkP; // for proportional centering movement to be implemented later

  if (angleXOff > 0) {
    MecanumDrive(0, drivetrainCenteringSpeed, 0);
  } else if (angleXOff < 0) {
    MecanumDrive(0, -drivetrainCenteringSpeed, 0);
  } else {
    MecanumDrive(0, 0, 0);
  }
}

void drivetrain::ZeroDriveEncoders() {
  m_motorFrontLeft.SetSelectedSensorPosition(0);
  m_motorRearLeft.SetSelectedSensorPosition(0);
  m_motorFrontRight.SetSelectedSensorPosition(0);
  m_motorRearRight.SetSelectedSensorPosition(0);
}

void drivetrain::SetBrakeMode(bool brake) {
  if (brake) {
    m_motorFrontLeft.SetNeutralMode(NeutralMode::Brake);
    m_motorRearLeft.SetNeutralMode(NeutralMode::Brake);
    m_motorFrontRight.SetNeutralMode(NeutralMode::Brake);
    m_motorRearRight.SetNeutralMode(NeutralMode::Brake);
  } else {
    m_motorFrontLeft.SetNeutralMode(NeutralMode::Coast);
    m_motorRearLeft.SetNeutralMode(NeutralMode::Coast);
    m_motorFrontRight.SetNeutralMode(NeutralMode::Coast);
    m_motorRearRight.SetNeutralMode(NeutralMode::Coast);
  }
}

void drivetrain::ZeroGyroYaw() {
  m_gyro.ZeroYaw();
}

void drivetrain::Periodic() {
  // Implementation of subsystem periodic method goes here.
  m_odometry.Update(m_gyro.GetRotation2d(),
                    units::meter_t(GetEncoderDistance(true)),
                    units::meter_t(GetEncoderDistance(false)));

}

void drivetrain::TankDriveVolts(double left, double right) {
  m_leftMotors.SetVoltage(units::volt_t(left));
  m_rightMotors.SetVoltage(units::volt_t(right));
}

double drivetrain::GetEncoderDistance(bool left) {
  double distance;
  if (left) {
    distance = 0.5 * (m_motorFrontLeft.GetSelectedSensorPosition() + m_motorRearLeft.GetSelectedSensorPosition()) * falconDistancePerPulse;
  } else {
    distance = 0.5 * (m_motorFrontRight.GetSelectedSensorPosition() + m_motorRearRight.GetSelectedSensorPosition()) * falconDistancePerPulse;
  }
  return distance;
}

double drivetrain::GetEncoderRate(bool left) {
  double rate;
  if (left) {
    rate = (0.5 * (m_motorFrontLeft.GetSelectedSensorVelocity() + m_motorRearLeft.GetSelectedSensorVelocity()) * 10) * falconDistancePerPulse;
  } else {
    rate = (0.5 * (m_motorFrontLeft.GetSelectedSensorVelocity() + m_motorRearLeft.GetSelectedSensorVelocity()) * 10) * falconDistancePerPulse;
  }
  return rate;
}

void drivetrain::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
  
}