#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/DoubleSolenoid.h>

#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>
#include "Constants.h"

class harvester : public frc2::SubsystemBase {
 public:
  harvester();

  enum class HarvesterDirection {kForward, kReverse, kOff};
  void RunHarvester(const HarvesterDirection& direction);

  enum class PneumaticsDirection {kIn, kOut};
  void MoveHarvester(const PneumaticsDirection& direction);
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
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX m_motorHarvester{harvesterConstants::motorHarvester};
  frc::DoubleSolenoid m_doubleSolenoidLeft{harvesterConstants::PHID, frc::PneumaticsModuleType::REVPH,
                                           harvesterConstants::solenoidForwardLeft, harvesterConstants::solenoidReverseLeft};
  frc::DoubleSolenoid m_doubleSolenoidRight{harvesterConstants::PHID, frc::PneumaticsModuleType::REVPH,
                                            harvesterConstants::solenoidForwardRight, harvesterConstants::solenoidReverseRight};

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
