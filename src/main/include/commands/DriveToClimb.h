#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/drivetrain.h"

/**
 * The command that takes the robot from its current position to the (?) hangar.
 */
class DriveToClimb
    : public frc2::CommandHelper<frc2::CommandBase, DriveToClimb> {
 public:
  /**
   * Creates a new instance of DriveToClimb command.
   *
   * @param drivetrain The subsystem used by this command.
   */
  explicit DriveToClimb(drivetrain* drivetrain);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  drivetrain* m_drivetrain;
};
