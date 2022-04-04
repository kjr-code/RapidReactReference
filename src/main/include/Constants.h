#pragma once

#include <wpi/numbers>
#include <frc/geometry/Translation2d.h>
#include <frc/trajectory/TrapezoidProfile.h>
#include <frc/controller/ProfiledPIDController.h>
#include <frc/kinematics/MecanumDriveKinematics.h>
#include <units/acceleration.h>
#include <units/angle.h>
#include <units/angular_velocity.h>
#include <units/length.h>
#include <units/time.h>
#include <units/velocity.h>
#include <units/voltage.h>
#include <wpi/numbers>

/**
 * This header contains hold robot-wide numerical or boolean constants ONLY.
 * 
 * Place constants into subsystem/command -specific NAMESPACES within this
 * header, which can then be included (where they are needed).
 */

const int PLACEHOLDER_INT = 0;

namespace controllerConstants {

    //USB port addresses on drivestation PC.
    const int controllerMain = 0;
    const int controllerAux = 1;

}

namespace drivetrainConstants {
    using radians_per_second_squared_t = units::compound_unit<units::radians,
                                                                units::inverse<units::squared<units::second>>>;

    //CAN IDs
    const int motorFrontRight = 0;
    const int motorRearRight = 1;
    const int motorFrontLeft = 2;
    const int motorRearLeft = 3;

    const double motorMaxOutput = 0.5;
    const double motorDeadband = 0.05;

    const double driveScalingCoefficient = 0.6;

    const bool fieldOriented = false;

    const double xRateLimit = 1;
    const double yRateLimit = 1;
    const double zRateLimit = 1;

    const bool voltageComp = true;
    const double satVoltage = 10;

    const bool driveMotorSaftey = false;

    const double shootAdjustmentkP = 0.1;
    const double drivetrainCenteringSpeed = 0.1;

    const double wheelDiameterMeters = 0.2032;
    const double falconCountsPerRevolution = 2048;
    const double falconDistancePerPulse = (wheelDiameterMeters * wpi::numbers::pi) / falconCountsPerRevolution;

    const units::inch_t wheelBase = 0_in;
    const units::inch_t trackWidth = 0_in;
    const frc::MecanumDriveKinematics m_kinematics{frc::Translation2d(wheelBase / 2, trackWidth / 2),
                                            frc::Translation2d(wheelBase / 2, -trackWidth / 2),
                                            frc::Translation2d(-wheelBase / 2, trackWidth / 2),
                                            frc::Translation2d(-wheelBase / 2, -trackWidth / 2)};
    const auto autoMaxSpeed = units::meters_per_second_t(3);
    const auto autoMaxAcceleration = units::meters_per_second_squared_t(3);
constexpr auto maxAngularSpeed = units::radians_per_second_t(3);
constexpr auto maxAngularAcceleration = units::unit_t<radians_per_second_squared_t>(3);

    const auto driveks = 0_V;
    const auto drivekv = 0 * 1_V * 1_s / 1_m;
    const auto driveka = 0 * 1_V * 1_s * 1_s / 1_m;

    const double kPXController = 0;
    const double kPYController = 0;
    const double kPThetaController = 0;
    extern const frc::TrapezoidProfile<units::radians>::Constraints kThetaControllerConstraints;

    const double kPFrontLeftVel = 0.5;
    const double kPFrontRightVel = 0.5;
    const double kPRearLeftVel = 0.5;
    const double kPRearRightVel = 0.5;

}

namespace harvesterConstants {

    //CAN ID
    const int PHID = 8;
    const int motorHarvester = 4;

    const double motorMaxOutput = 0.5;

    //Solenoid Ports
    const int solenoidForward = 4;
    const int solenoidReverse = 6;

}

namespace indexerConstants {

    //CAN ID
    const int motorIndexer = 5;

    const double motorMaxOutput = 1;

    const bool indexerInverted = false;
    const double satVoltage = 10;
    const bool voltageComp = false;

}

namespace shooterConstants {

    //CAN ID
    const int motorShooter = 7;

    const double nominalVoltage = 11;

    const double lowSpeedBase = 5; //base values are for testing purposes with smart dashboard
    const double highSpeedBase = 7;

    const double shootLowSpeed = 0;

    const double shooterkP = 5.2183E-05; //suggested by sysID tool
    const double shooterkI = 0;
    const double shooterkD = 0;
    const double shooterFF = 0; //pid max output divided by free speed

    const double maxDistanceFromTargetIn = 10000000;
    const double minDistanceFromTargetIn = 0;
    const double maxAimDeviationDEG = 2;

    const double targetHeightIn = 101;
    const double limelightHeightIn = 31.5;
    const double limelightAngleDEG = 35;
    
    const auto shootks = 0_V;
    const auto shootkv = 0 * 1_V * 1_s / 1_m;
    const auto shootka = 0 * 1_V * 1_s * 1_s / 1_m;

    const double shooterInverted = true;



}

namespace climberConstants {

    //CAN ID
    const int PHID = 8;

    //Solenoid Ports
    const int solenoidForwardLeft = 2;
    const int solenoidReverseLeft = 3;
    const int solenoidForwardRight = 0;
    const int solenoidReverseRight = 5;

}