#include "RobotContainer.h"
#include <frc2/command/button/JoystickButton.h>

RobotContainer::RobotContainer() : m_Autonomous(&m_climber,
                                                &m_drivetrain,
                                                &m_harvester,
                                                &m_shooter,
                                                &m_indexer) {
  // Initialize all of your commands and subsystems here INVESTIGATE
  bool condition;
  frc2::Trigger exampleTrigger([&condition] {return condition;});

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

  frc2::JoystickButton(&m_controllerMain, frc::XboxController::Button::kA).WhileActiveContinous  (
    Harvester(&m_harvester, harvester::HarvesterDirection::kForward)); 

  frc2::JoystickButton(&m_controllerMain, frc::XboxController::Button::kB).WhileActiveContinous(
    Harvester(&m_harvester, harvester::HarvesterDirection::kReverse));

  frc2::JoystickButton(&m_controllerMain, frc::XboxController::Button::kX).WhileActiveContinous(
    Index(&m_indexer, indexer::IndexerDirection::kForward));
  
  frc2::JoystickButton(&m_controllerMain, frc::XboxController::Button::kY).WhileActiveContinous(
    Index(&m_indexer, indexer::IndexerDirection::kReverse));

  frc2::JoystickButton(&m_controllerMain, frc::XboxController::Axis::kLeftTrigger).WhileActiveContinous(
    ShootLow(&m_shooter));

  frc2::JoystickButton(&m_controllerMain, frc::XboxController::Axis::kRightTrigger).WhileActiveContinous(
    ShootHigh(&m_shooter, &m_drivetrain));


  //bool shootHighCondition = TriggerPressed(true, true);
  //frc2::Trigger highTrigger([&shootHighCondition] {return shootHighCondition;});
  //highTrigger.WhileActiveContinous(ShootHigh(&m_shooter, &m_drivetrain));

  //bool shootLowCondition = TriggerPressed(false, true);
  //frc2::Trigger lowTrigger([&shootLowCondition] {return shootLowCondition;});
  //lowTrigger.WhileActiveContinous(ShootLow(&m_shooter));

/*
  if (m_controllerAux.GetLeftTriggerAxis() >= 0.75) {
    frc2::Trigger().WhileActiveContinous(ShootLow(&m_shooter));
  }
*/
}

bool RobotContainer::TriggerPressed(bool right, bool driveController) {

  if (right) {
    if (driveController) {
      return (m_controllerMain.GetRightTriggerAxis() >= 0.75);
    } else {
      return (m_controllerAux.GetRightTriggerAxis() >= 0.75);
    }
  } else {
    if (driveController) {
      return (m_controllerMain.GetLeftTriggerAxis() >= 0.75);
    } else {
      return (m_controllerAux.GetLeftTriggerAxis() >= 0.75);
    }
  }

}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_Autonomous;
}
