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

  m_mecanumDrive.SetDeadband(motorDeadband);
  m_mecanumDrive.SetMaxOutput(motorMaxOutput);

  m_navX.ZeroYaw();
}

void drivetrain::MecanumDriveJoystick(double xSpeed, double ySpeed, double zRotation, bool fieldOriented) {
  double m_a = driveScalingCoefficient;
  // We need to invert input from joystick. -1 is forward with raw input.
  ySpeed = -ySpeed;
  zRotation = -zRotation;

  xSpeed = (m_a * pow(xSpeed, 3)) + ((1 - m_a) * xSpeed);
  ySpeed = (m_a * pow(ySpeed, 3)) + ((1 - m_a) * ySpeed);
  zRotation = (m_a * pow(zRotation, 3)) + ((1 - m_a) * zRotation);
  
  if (fieldOriented) {
    // Converts yaw from degrees to radians.
    m_adjYaw = (m_navX.GetYaw() * 3.14159265358979323846 / 180);
  
    // DON'T TOUCH IF YOU DON'T UNDERSTAND THE TRIG:
    m_adjXSpeed = xSpeed*cos(m_adjYaw)-ySpeed*sin(m_adjYaw);
    m_adjYSpeed = ySpeed*cos(m_adjYaw)+xSpeed*sin(m_adjYaw);
  }
  // Alternate: m_mecanumDrive.DriveCartesian(m_adjXSpeed, m_adjYSpeed, zRotation);
  // m_mecanumDrive.DriveCartesian(m_adjYSpeed, m_adjXSpeed, zRotation);
  MecanumDrive(xSpeed, ySpeed, zRotation);

}

void drivetrain::MecanumDrive(double x, double y, double z) {
  double FL, BL, FR, BR;

  

}

void drivetrain::NormalizeWheelSpeeds(double FL, double BL, double FR, double BR) {

}

void drivetrain::Periodic() {
  // Implementation of subsystem periodic method goes here.


}

void drivetrain::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
  
}