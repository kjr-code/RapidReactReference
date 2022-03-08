#pragma once

#include <frc2/command/SubsystemBase.h>

#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>
#include "Constants.h"

class indexer : public frc2::SubsystemBase {
 public:
  indexer();

  enum class IndexerDirection {kForward, kReverse, kOff};
  void RunIndexer(const IndexerDirection& direction);
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
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX m_motorIndexer{indexerConstants::motorIndexer};
};