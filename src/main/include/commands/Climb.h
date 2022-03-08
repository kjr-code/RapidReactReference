#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/climber.h"

/**
 * The command that controls our Climb.
 */
class Climb
    : public frc2::CommandHelper<frc2::CommandBase, Climb> {
 public:
  /**
   * Creates a new instance of Climb command.
   *
   * @param climber The subsystem used by this command.
   * @param direction The direction to climb.
   */
  explicit Climb(climber* climber, const climber::ClimbDirection& direction);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  climber* m_climber;
  const climber::ClimbDirection&  m_direction;
};
