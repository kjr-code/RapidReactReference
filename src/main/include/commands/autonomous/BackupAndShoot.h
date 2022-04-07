// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "commands/ShootHigh.h"
#include "subsystems/drivetrain.h"
#include "subsystems/indexer.h"
#include "subsystems/shooter.h"

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/ParallelRaceGroup.h>
#include <frc2/command/ParallelDeadlineGroup.h>
#include <frc2/command/ParallelCommandGroup.h>
#include <frc2/command/WaitCommand.h>

class BackupAndShoot
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 BackupAndShoot> {
 public:
  BackupAndShoot(drivetrain* drivetrain, shooter* shooter, indexer* indexer);

 private:

  indexer* m_indexer;
  drivetrain* m_drivetrain;
  shooter* m_shooter;
};
