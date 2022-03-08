#include "RobotContainer.h"
#include <frc2/command/button/JoystickButton.h>

RobotContainer::RobotContainer() : m_Autonomous(&m_climber,
                                                &m_drivetrain,
                                                &m_harvester,
                                                &m_shooter,
                                                &m_indexer) {
  // Initialize all of your commands and subsystems here INVESTIGATE

  // Configure the button bindings
  ConfigureButtonBindings();

  m_drivetrain.SetDefaultCommand(Drive(
    &m_drivetrain,
    [this] { return m_controllerMain.GetX(); },
    [this] { return m_controllerMain.GetY(); },
    [this] { return m_controllerMain.GetZ(); }));

  m_harvester.SetDefaultCommand(Harvester(
    &m_harvester, harvester::HarvesterDirection::kOff
  ));

  m_climber.SetDefaultCommand(Climb(
    &m_climber, climber::ClimbDirection::kDown
  ));

  m_indexer.SetDefaultCommand(Index(
    &m_indexer, indexer::IndexerDirection::kOff
  ));
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  frc2::JoystickButton(&m_controllerMain, 1).WhenPressed(
    ShootHigh(&m_shooter));

  (frc2::JoystickButton(&m_controllerMain, 1)
    && frc2::JoystickButton(&m_controllerMain, 2)).WhenActive(
      ShootLow(&m_shooter));
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_Autonomous;
}
