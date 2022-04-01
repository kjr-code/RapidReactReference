#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableEntry.h> 
#include <networktables/NetworkTableInstance.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/controller/SimpleMotorFeedForward.h>

#include "Constants.h"

using namespace shooterConstants;

class shooter : public frc2::SubsystemBase {
 public:
  shooter();

  enum class ShooterBehavior {kHigh, kLow, kOff};
  void RunShooter(const ShooterBehavior& behavior);

  double GetError();

  double DistanceToTargetIn();

  /**
   * Checks to see if robot is at scoring distance from the target.
   */
  bool Goldilocks();

  void ShootHigh();



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

  
  double tx{0}, ty{0};
  double m_targetHeight{targetHeightIn},
          m_limelightAngle{limelightAngleDEG},
          m_limelightHeight{limelightHeightIn},
          m_targetAngle{0},
          m_distanceToTargetIn{0},
          m_totalAngleToTargetRAD{0},
          m_RPM{0};
};
