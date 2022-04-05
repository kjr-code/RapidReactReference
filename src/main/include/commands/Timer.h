// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc/Timer.h>

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class Timer
    : public frc2::CommandHelper<frc2::CommandBase, Timer> {
 public:
  Timer(units::second_t waitTime);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:

  frc::Timer time;
  bool finished;
  units::second_t currentTime{0_s}, 
                  startTime{0_s},
                  m_waitTime{0_s};
};
