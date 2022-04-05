#include "RobotContainer.h"
#include <frc2/command/button/JoystickButton.h>

RobotContainer::RobotContainer() : m_Autonomous(&m_climber,
                                                &m_drivetrain,
                                                &m_harvester,
                                                &m_shooter,
                                                &m_indexer) {
  // Initialize all of your commands and subsystems here INVESTIGATE

  const frc::TrapezoidProfile<units::radians>::Constraints kThetaControllerConstraints{maxAngularSpeed, maxAngularAcceleration};

  // Configure the button bindings
  ConfigureButtonBindings();

  m_drivetrain.SetDefaultCommand(Drive(
    &m_drivetrain,
    [this] { return m_controllerMain.GetRawAxis(frc::XboxController::Axis::kLeftX); },
    [this] { return m_controllerMain.GetRawAxis(frc::XboxController::Axis::kLeftY); },
    [this] { return m_controllerMain.GetRawAxis(frc::XboxController::Axis::kRightX); }));

  m_harvester.SetDefaultCommand(Harvester(
    &m_harvester, harvester::HarvesterDirection::kOff
  ));

  m_climber.SetDefaultCommand(Climb(
    &m_climber, climber::ClimbDirection::kDown
  ));

  //m_indexer.SetDefaultCommand(Index(
    //&m_indexer, indexer::IndexerDirection::kOff
  //));
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here

  frc2::JoystickButton(&m_controllerMain, frc::XboxController::Button::kA).WhenHeld(
    Harvester(&m_harvester, harvester::HarvesterDirection::kForward)); 

  frc2::JoystickButton(&m_controllerMain, frc::XboxController::Button::kB).WhenHeld(
    Harvester(&m_harvester, harvester::HarvesterDirection::kReverse));

  frc2::JoystickButton(&m_controllerMain, frc::XboxController::Button::kX).WhenHeld(
    Index(&m_indexer, indexer::IndexerDirection::kForward));
  
  frc2::JoystickButton(&m_controllerMain, frc::XboxController::Button::kY).WhenHeld(
    Index(&m_indexer, indexer::IndexerDirection::kReverse));

  frc2::Trigger leftTrigger ([&] {return m_controllerMain.GetRawAxis(frc::XboxController::Axis::kLeftTrigger) >= 0.75;});
  leftTrigger.WhileActiveContinous(ShootLow(&m_shooter));

  frc2::Trigger rightTrigger ([&] {return m_controllerMain.GetRawAxis(frc::XboxController::Axis::kRightTrigger) >= 0.75;});
  rightTrigger.WhileActiveContinous(ShootHigh(&m_shooter, &m_drivetrain));


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
/*
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
*/
frc2::Command* RobotContainer::GetAutonomousCommand() {
  // Set up config for trajectory
  /*
  frc::TrajectoryConfig config(autoMaxSpeed,
                               autoMaxAcceleration);
  // Add kinematics to ensure max speed is actually obeyed
  config.SetKinematics(m_kinematics);

  // An example trajectory to follow.  All units in meters.
  auto exampleTrajectory = frc::TrajectoryGenerator::GenerateTrajectory(
      // Start at the origin facing the +X direction
      frc::Pose2d(0_m, 0_m, frc::Rotation2d(0_deg)),
      // Pass through these two interior waypoints, making an 's' curve path
      {frc::Translation2d(1_m, 1_m), frc::Translation2d(2_m, -1_m)},
      // End 3 meters straight ahead of where we started, facing forward
      frc::Pose2d(3_m, 0_m, frc::Rotation2d(0_deg)),
      // Pass the config
      config);

  frc2::MecanumControllerCommand mecanumControllerCommand(
      exampleTrajectory, [this]() { return m_drivetrain.GetPose(); },

      frc::SimpleMotorFeedforward<units::meters>(driveks, drivekv, driveka),
      m_kinematics,

      frc2::PIDController(kPXController, 0, 0),
      frc2::PIDController(kPYController, 0, 0),
      frc::ProfiledPIDController<units::radians>(
          kPThetaController, 0, 0,
          frc::TrapezoidProfile<units::radians>::Constraints(maxAngularSpeed, maxAngularAcceleration)),
  
      autoMaxSpeed,

      [this]() {
        return frc::MecanumDriveWheelSpeeds{
            units::meters_per_second_t(m_drivetrain.GetVelocity(drivetrain::MotorLocation::kFL)),
            units::meters_per_second_t(m_drivetrain.GetVelocity(drivetrain::MotorLocation::kFR)),
            units::meters_per_second_t(m_drivetrain.GetVelocity(drivetrain::MotorLocation::kBL)),
            units::meters_per_second_t(m_drivetrain.GetVelocity(drivetrain::MotorLocation::kBR))};
      },

      frc2::PIDController(kPFrontLeftVel, 0, 0),
      frc2::PIDController(kPRearLeftVel, 0, 0),
      frc2::PIDController(kPFrontRightVel, 0, 0),
      frc2::PIDController(kPRearRightVel, 0, 0),

      [this](units::volt_t frontLeft, units::volt_t rearLeft,
             units::volt_t frontRight, units::volt_t rearRight) {
        m_drivetrain.SetDriveMotorVoltage(frontLeft, rearLeft, frontRight, rearRight);
      },

      {&m_drivetrain});
  // An example command will be run in autonomous
  m_drivetrain.ResetOdometry(exampleTrajectory.InitialPose());

  // no auto 
  /*
  return new frc2::SequentialCommandGroup(
    frc2::ParallelRaceGroup(
      std::move(mecanumControllerCommand)
      //Harvester(&m_harvester, harvester::HarvesterDirection::kForward)
      ),
    frc2::ParallelCommandGroup(
      frc2::InstantCommand([this]() { m_drivetrain.MecanumDrive(0, 0, 0); }, {})
      //frc2::InstantCommand([this]() { m_harvester.RunHarvester(harvester::HarvesterDirection::kOff); }, {}))
    ));
  return new frc2::SequentialCommandGroup(
    std::move(mecanumControllerCommand),
    frc2::InstantCommand([this]() { m_drivetrain.MecanumDrive(0, 0, 0);}, {}));
    */

  return new frc2::SequentialCommandGroup (
    frc2::ParallelDeadlineGroup(
      Timer(units::second_t(3)),
      frc2::InstantCommand([this]() { m_drivetrain.MecanumDrive(0.2, 0, 0);}, {})
    ),
    frc2::ParallelDeadlineGroup(
      Timer(units::second_t(7)),
      ShootHigh(&m_shooter, &m_drivetrain),
      frc2::SequentialCommandGroup (
        Timer(units::second_t(1.5)),
        frc2::InstantCommand([this]() { m_indexer.RunIndexer(indexer::IndexerDirection::kForward);}, {})
      )
    ),
    frc2::InstantCommand([this]() { m_indexer.RunIndexer(indexer::IndexerDirection::kOff);}, {})
  );
}
