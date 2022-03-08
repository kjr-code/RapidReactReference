#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/shooter.h"

/**
 * The command that shoots at the 1pt. goal.
 */
class ShootLow
    : public frc2::CommandHelper<frc2::CommandBase, ShootLow> {
 public:
  /**
   * Creates a new instance of ShootLow command.
   *
   * @param shooter The subsystem used by this command.
   */
  explicit ShootLow(shooter* shooter);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  shooter* m_shooter;
};
