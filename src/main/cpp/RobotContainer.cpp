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
    [this] { return m_controllerMain.GetLeftX(); },
    [this] { return m_controllerMain.GetLeftY(); },
    [this] { return m_controllerMain.GetRightX(); }));

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

  frc2::JoystickButton(&m_controllerAux, 1).WhenActive(
    Harvester(&m_harvester, harvester::HarvesterDirection::kForward));

  frc2::JoystickButton(&m_controllerAux, 2).WhenActive(
    Harvester(&m_harvester, harvester::HarvesterDirection::kReverse));

  if (m_controllerAux.GetRightTriggerAxis() >= 0.75) {
    frc2::Trigger().WhenActive(ShootHigh(&m_shooter, &m_drivetrain));
  }
  
  if (m_controllerAux.GetLeftTriggerAxis() >= 0.75) {
    frc2::Trigger().WhenActive(ShootLow(&m_shooter));
  }
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_Autonomous;
}
