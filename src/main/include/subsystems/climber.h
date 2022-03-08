#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/DoubleSolenoid.h>

#include <Constants.h>

class climber : public frc2::SubsystemBase {
 public:
  climber();

  enum class ClimbDirection {kUp, kDown};
  void RunClimb(const ClimbDirection& direction);

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
  frc::DoubleSolenoid m_doubleSolenoidLeft{climberConstants::PHID, frc::PneumaticsModuleType::REVPH,
                                           climberConstants::solenoidForwardLeft, climberConstants::solenoidReverseLeft};
  frc::DoubleSolenoid m_doubleSolenoidRight{climberConstants::PHID, frc::PneumaticsModuleType::REVPH,
                                            climberConstants::solenoidForwardRight, climberConstants::solenoidReverseRight};
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
