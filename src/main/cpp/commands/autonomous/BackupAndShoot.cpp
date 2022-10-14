// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/autonomous/BackupAndShoot.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
BackupAndShoot::BackupAndShoot(drivetrain* drivetrain, shooter* shooter, indexer* indexer)
                              : m_drivetrain{drivetrain},
                                m_shooter{shooter},
                                m_indexer{indexer} {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());

  AddCommands(
    frc2::ParallelDeadlineGroup(
      frc2::WaitCommand(2.5_s),
      frc2::InstantCommand([this]() { m_drivetrain->MecanumDrive(0.2, 0, 0);}, {})
    ),
    frc2::ParallelDeadlineGroup(
      frc2::WaitCommand(7_s),
      ShootHigh(m_shooter, m_drivetrain),
      frc2::SequentialCommandGroup (
        frc2::WaitCommand(3_s),
        frc2::InstantCommand([this]() { m_indexer->RunIndexer(indexer::IndexerDirection::kForward);}, {})
      )
    ),
    frc2::InstantCommand([this]() { m_indexer->RunIndexer(indexer::IndexerDirection::kOff);}, {})
    );
}
