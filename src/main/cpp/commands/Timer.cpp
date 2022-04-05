// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Timer.h"

Timer::Timer(units::second_t waitTime) {
  // Use addRequirements() here to declare subsystem dependencies.
  m_waitTime = waitTime;
}

// Called when the command is initially scheduled.
void Timer::Initialize() {
  time.Reset();
  time.Start();
  startTime = time.Get();
  finished = false;
}

// Called repeatedly when this Command is scheduled to run
void Timer::Execute() {
  currentTime = time.Get();
  if ((currentTime - startTime) > m_waitTime) {
    finished = true;
  } else {
    finished = false;
  }
}

// Called once the command ends or is interrupted.
void Timer::End(bool interrupted) {}

// Returns true when the command should end.
bool Timer::IsFinished() {
  return finished;
}
