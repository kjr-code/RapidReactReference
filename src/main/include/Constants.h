#pragma once

#include <wpi/numbers>
#include <units/voltage.h>
#include <units/time.h>
#include <units/length.h>

/**
 * This header contains hold robot-wide numerical or boolean constants ONLY.
 * 
 * Place constants into subsystem/command -specific NAMESPACES within this
 * header, which can then be included (where they are needed).
 */

constexpr int PLACEHOLDER_INT = 0;

namespace controllerConstants {

    //USB port addresses on drivestation PC.
    constexpr int controllerMain = 0;
    constexpr int controllerAux = 1;

}

namespace drivetrainConstants {

    //CAN IDs
    constexpr int motorFrontRight = 0;
    constexpr int motorRearRight = 1;
    constexpr int motorFrontLeft = 2;
    constexpr int motorRearLeft = 3;

    constexpr double motorMaxOutput = 0.5;
    constexpr double motorDeadband = 0.05;

    constexpr double driveScalingCoefficient = 0.6;

    constexpr bool fieldOriented = false;

    constexpr double xRateLimit = 1;
    constexpr double yRateLimit = 1;
    constexpr double zRateLimit = 1;

    constexpr bool voltageComp = true;
    constexpr double satVoltage = 10;

    constexpr bool driveMotorSaftey = false;

    constexpr double shootAdjustmentkP = 0.1;
    constexpr double drivetrainCenteringSpeed = 0.05;

    constexpr double wheelDiameterMeters = 0.2032;
    constexpr double falconCountsPerRevolution = 2048;
    constexpr double falconDistancePerPulse = (wheelDiameterMeters * wpi::numbers::pi) / falconCountsPerRevolution;
    constexpr double trackWidth = 0;

    constexpr auto driveks = 0_V;
    constexpr auto drivekv = 0 * 1_V * 1_s / 1_m;
    constexpr auto driveka = 0 * 1_V * 1_s * 1_s / 1_m;

}

namespace harvesterConstants {

    //CAN ID
    constexpr int PHID = 8;
    constexpr int motorHarvester = 4;

    constexpr double motorMaxOutput = 0.5;

    //Solenoid Ports
    constexpr int solenoidForward = 4;
    constexpr int solenoidReverse = 6;

}

namespace indexerConstants {

    //CAN ID
    constexpr int motorIndexer = 5;

    constexpr double motorMaxOutput = 1;

    constexpr bool indexerInverted = false;
    constexpr double satVoltage = 10;
    constexpr bool voltageComp = false;

}

namespace shooterConstants {

    //CAN ID
    constexpr int motorShooter = 7;

    constexpr double nominalVoltage = 11;

    constexpr double lowSpeedBase = 5; //base values are for testing purposes with smart dashboard
    constexpr double highSpeedBase = 7;

    constexpr double shootLowSpeed = 0;

    constexpr double shooterkP = 5.2183E-05; //suggested by sysID tool
    constexpr double shooterkI = 0;
    constexpr double shooterkD = 0;
    constexpr double shooterFF = 0; //pid max output divided by free speed

    constexpr double maxDistanceFromTargetIn = 10000000;
    constexpr double minDistanceFromTargetIn = 0;
    constexpr double maxAimDeviationDEG = 2;

    constexpr double targetHeightIn = 101;
    constexpr double limelightHeightIn = 31.5;
    constexpr double limelightAngleDEG = 35;
    
    constexpr auto shootks = 0_V;
    constexpr auto shootkv = 0 * 1_V * 1_s / 1_m;
    constexpr auto shootka = 0 * 1_V * 1_s * 1_s / 1_m;

    constexpr double shooterInverted = true;



}

namespace climberConstants {

    //CAN ID
    constexpr int PHID = 8;

    //Solenoid Ports
    constexpr int solenoidForwardLeft = 2;
    constexpr int solenoidReverseLeft = 3;
    constexpr int solenoidForwardRight = 0;
    constexpr int solenoidReverseRight = 5;

}