#pragma once

#include <frc2/command/SubsystemBase.h>

#include <AHRS.h>
#include <ctre/phoenix.h>
#include <frc/drive/MecanumDrive.h>

#include "Constants.h"

using namespace controllerConstants;
using namespace drivetrainConstants;

class drivetrain : public frc2::SubsystemBase {
 public:
  drivetrain();

  /**
   * Gives us field persistent controls. Wrapped around the existing 
   * mecanum drive class; modifies the inputs before they are fed to 
   * driveCartesian.
   * @param xSpeed The x-speed of the robot (relative to the driver).
   * @param ySpeed The y-speed of the robot (relative to the driver).
   * @param zRotation The z-rotation of the robot (about its center).
   */
  void BootlegSwerve(double xSpeed, double ySpeed, double zRotation);

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  /**
   * Will be called periodically whenever the CommandScheduler runs during
   * simulation.
   */
  void SimulationPeriodic() override;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  WPI_TalonFX m_motorFrontLeft{motorFrontLeft};
  WPI_TalonFX m_motorFrontRight{motorFrontRight};
  WPI_TalonFX m_motorRearLeft{motorRearLeft};
  WPI_TalonFX m_motorRearRight{motorRearRight};

  TalonFXConfiguration m_talonFXConfiguration{};

  frc::MecanumDrive m_mecanumDrive{m_motorFrontLeft, m_motorRearLeft, m_motorFrontRight, m_motorRearRight};

  double m_adjXSpeed{0};
  double m_adjYSpeed{0};
  double m_adjYaw{0};

  AHRS m_navX{frc::SPI::kMXP};
};
