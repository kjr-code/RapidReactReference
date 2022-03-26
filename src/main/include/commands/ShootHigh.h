#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/shooter.h"
#include "subsystems/drivetrain.h"

/**
 * The command that shoots at the 2pt. goal.
 */
class ShootHigh
    : public frc2::CommandHelper<frc2::CommandBase, ShootHigh> {
 public:
  /**
   * Creates a new instance of ShootHigh command.
   *
   * @param shooter The subsystem used by this command.
   */
  explicit ShootHigh(shooter* shooter, drivetrain* drivetrain);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  shooter* m_shooter;
  drivetrain* m_drivetrain;
};
