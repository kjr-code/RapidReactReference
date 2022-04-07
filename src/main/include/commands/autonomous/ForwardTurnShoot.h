// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "subsystems/shooter.h"
#include "subsystems/drivetrain.h"
#include "subsystems/harvester.h"
#include "subsystems/indexer.h"
#include "commands/ShootHigh.h"

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/ParallelRaceGroup.h>
#include <frc2/command/ParallelDeadlineGroup.h>
#include <frc2/command/ParallelCommandGroup.h>
#include <frc2/command/WaitCommand.h>

class ForwardTurnShoot
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 ForwardTurnShoot> {
 public:
  ForwardTurnShoot(shooter* shooter, drivetrain* drivetrain, harvester* harvester, indexer* indexer);

 private:

  shooter* m_shooter;
  drivetrain* m_drivetrain;
  harvester* m_harvester;
  indexer* m_indexer;
};
