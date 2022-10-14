// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/autonomous/ForwardTurnShoot.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
ForwardTurnShoot::ForwardTurnShoot(shooter* shooter, drivetrain* drivetrain, harvester* harvester, indexer* indexer) 
                                  : m_shooter{shooter},
                                    m_drivetrain{drivetrain},
                                    m_harvester{harvester},
                                    m_indexer{indexer} {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());

  AddCommands(
    frc2::ParallelDeadlineGroup(
      frc2::WaitCommand(2.5_s),
      frc2::InstantCommand([this]() { m_drivetrain->MecanumDrive(-0.2, 0, 0);}, {}),
      frc2::InstantCommand([this]() { m_harvester->RunHarvester(harvester::HarvesterDirection::kForward);}, {})
      //frc2::InstantCommand([this]() { m_harvester->MoveHarvester(harvester::PneumaticsDirection::kOut);}, {})
    ),
    frc2::ParallelDeadlineGroup(
      frc2::WaitCommand(1.9_s),
      frc2::InstantCommand([this]() { m_drivetrain->MecanumDrive(0, 0, 0.2);}, {}),
      frc2::InstantCommand([this]() { m_harvester->RunHarvester(harvester::HarvesterDirection::kOff);}, {})
    ),
    frc2::ParallelDeadlineGroup(
      frc2::WaitCommand(9_s),
      ShootHigh(m_shooter, m_drivetrain),
      frc2::SequentialCommandGroup (
        frc2::WaitCommand(2_s),
        frc2::InstantCommand([this]() { m_indexer->RunIndexer(indexer::IndexerDirection::kForward);}, {}),
        frc2::InstantCommand([this]() { m_harvester->RunHarvester(harvester::HarvesterDirection::kForward);}, {})
      )
    ),
    frc2::InstantCommand([this]() { m_indexer->RunIndexer(indexer::IndexerDirection::kOff);}, {}),
    frc2::InstantCommand([this]() { m_harvester->RunHarvester(harvester::HarvesterDirection::kOff);}, {})
    );
}
