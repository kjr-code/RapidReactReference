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
#include "commands/autonomous/BackupAndShoot.h"
#include "commands/autonomous/ForwardTurnShoot.h"
#include "subsystems/climber.h"
#include "subsystems/drivetrain.h"
#include "subsystems/harvester.h"
#include "subsystems/shooter.h"
#include "subsystems/indexer.h"

#include <frc/Joystick.h>
#include <frc/XboxController.h>
#include <frc/controller/ProfiledPIDController.h>
#include <frc/controller/PIDController.h>
#include <frc2/command/MecanumControllerCommand.h>
#include <frc/trajectory/Trajectory.h>
#include <frc/trajectory/TrajectoryConfig.h>
#include <frc/trajectory/TrajectoryGenerator.h>
#include <frc/trajectory/TrajectoryConfig.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/ParallelRaceGroup.h>
#include <frc2/command/ParallelDeadlineGroup.h>
#include <frc2/command/ParallelCommandGroup.h>
#include <frc2/command/WaitCommand.h>
#include <frc/smartdashboard/SendableChooser.h>

using namespace controllerConstants;
using namespace drivetrainConstants;

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

  void PosttoDashboard();

 private:
  // The robot's subsystems and commands are defined here...
  climber m_climber;
  drivetrain m_drivetrain;
  harvester m_harvester;
  shooter m_shooter;
  indexer m_indexer;
  
  Autonomous m_Autonomous;
  BackupAndShoot m_BackupAndShoot;
  ForwardTurnShoot m_ForwardTurnShoot;

  void ConfigureButtonBindings();

  frc::SendableChooser<frc2::SequentialCommandGroup*> m_chooser;

 // bool TriggerPressed(bool right, bool driveController);

  frc::Joystick m_controllerMain{controllerMain};
  frc::Joystick m_controllerAux{controllerAux};
};
