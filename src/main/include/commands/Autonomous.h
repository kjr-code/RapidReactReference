#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/climber.h"
#include "subsystems/drivetrain.h"
#include "subsystems/harvester.h"
#include "subsystems/shooter.h"
#include "subsystems/indexer.h"

/**
 * The command that controls our autonomous routine.
 */
class Autonomous
    : public frc2::CommandHelper<frc2::CommandBase, Autonomous> {
 public:
  /**
   * Creates a new instance of Autonomous command.
   *
   * @param climber A subsystem used by this command.
   * @param drivetrain A subsystem used by this command.
   * @param harvester A subsystem used by this command.
   * @param shooter A subsystem used by this command.
   * @param indexer A subsystem used by this command.
   */
  explicit Autonomous(climber* climber, drivetrain* drivetrain, harvester* harvester, shooter* shooter, indexer* indexer);
  
  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  climber* m_climber;
  drivetrain* m_drivetrain;
  harvester* m_harvester;
  shooter* m_shooter;
  indexer* m_indexer;
};
