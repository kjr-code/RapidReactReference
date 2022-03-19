#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>

#include "Constants.h"

class shooter : public frc2::SubsystemBase {
 public:
  shooter();

  enum class ShooterBehavior {kOn, kOff};
  void RunShooter(const ShooterBehavior& behavior, double percentOut = 0);
  /**
   * Checks to see if robot is at scoring distance from the target.
   */
  int Goldilocks();



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
  rev::CANSparkMax m_motorShooter{shooterConstants::motorShooter, rev::CANSparkMax::MotorType::kBrushless};
  rev::SparkMaxPIDController m_PIDShooter{m_motorShooter.GetPIDController()};
};
