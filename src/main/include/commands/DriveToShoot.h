#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/drivetrain.h"

/**
 * The command that takes the robot from its current position to the Goldilocks zone.
 */
class DriveToShoot
    : public frc2::CommandHelper<frc2::CommandBase, DriveToShoot> {
 public:
  /**
   * Creates a new instance of DriveToShoot command.
   *
   * @param drivetrain The subsystem used by this command.
   */
  explicit DriveToShoot(drivetrain* drivetrain);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  drivetrain* m_drivetrain;
};
