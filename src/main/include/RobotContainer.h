#pragma once

#include <frc2/command/Command.h>

#include "Constants.h"

//Be sure to include all commands and subsystems here.
#include "commands/Autonomous.h"
#include "commands/Drive.h"
#include "commands/DriveToClimb.h"
#include "commands/DriveToShoot.h"
#include "commands/Harvester.h"
#include "commands/ShootHigh.h"
#include "commands/ShootLow.h"
#include "commands/Climb.h"
#include "commands/Index.h"
#include "subsystems/climber.h"
#include "subsystems/drivetrain.h"
#include "subsystems/harvester.h"
#include "subsystems/shooter.h"
#include "subsystems/indexer.h"

#include <frc/Joystick.h>
#include <frc/XboxController.h>

using namespace controllerConstants;

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

 private:
  // The robot's subsystems and commands are defined here...
  climber m_climber;
  drivetrain m_drivetrain;
  harvester m_harvester;
  shooter m_shooter;
  indexer m_indexer;
  
  Autonomous m_Autonomous;

  void ConfigureButtonBindings();

 // bool TriggerPressed(bool right, bool driveController);

  frc::XboxController m_controllerMain{controllerMain};
  frc::XboxController m_controllerAux{controllerAux};
};
