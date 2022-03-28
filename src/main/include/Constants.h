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

    constexpr double motorMaxOutput = 1;
    constexpr double motorDeadband = 0.05;

    constexpr double driveScalingCoefficient = 0.8;

    constexpr bool fieldOriented = false;

    constexpr double xRateLimit = 1;
    constexpr double yRateLimit = 1;
    constexpr double zRateLimit = 1;

    constexpr bool voltageComp = true;
    constexpr double satVoltage = 10;

    constexpr bool driveMotorSaftey = false;

    constexpr double shootAdjustmentkP = 0.1;
    constexpr double drivetrainCenteringSpeed = 0.25;

    constexpr double wheelDiameterMeters = 0.2032;
    constexpr double falconCountsPerRevolution = 2048;
    constexpr double falconDistancePerPulse = (wheelDiameterMeters * wpi::numbers::pi) / falconCountsPerRevolution;
    constexpr double trackWidth = 0;

    constexpr auto ks = 0_V;
    constexpr auto kv = 0 * 1_V * 1_s / 1_m;
    constexpr auto ka = 0 * 1_V * 1_s * 1_s / 1_m;

}

namespace harvesterConstants {

    //CAN ID
    constexpr int PHID = 8;
    constexpr int motorHarvester = 4;

    constexpr double motorMaxOutput = 0.5;

    //Solenoid Ports
    constexpr int solenoidForward = 0;
    constexpr int solenoidReverse = 1;

}

namespace indexerConstants {

    //CAN ID
    constexpr int motorIndexer = 5;

    constexpr double motorMaxOutput = 0.5;

    constexpr bool indexerInverted = false;
    constexpr double satVoltage = 10;
    constexpr bool voltageComp = true;

}

namespace shooterConstants {

    //CAN ID
    constexpr int motorShooter = 7;

    constexpr double nominalVoltage = 11;

    constexpr double lowSpeedBase = 1500; //base values are for testing purposes with smart dashboard
    constexpr double highSpeedBase = 2500;

    constexpr double shootLowSpeed = 0;

    constexpr double shooterkP = 0;
    constexpr double shooterkI = 0;
    constexpr double shooterkD = 0;
    constexpr double shooterFF = 0;

    constexpr double maxDistanceFromTargetIn = 10000000;
    constexpr double minDistanceFromTargetIn = 0;
    constexpr double maxAimDeviationDEG = 1;

    constexpr double targetHeightIn = 0;
    constexpr double limelightHeightIn = 0;
    constexpr double limelightAngleDEG = 0;



}

namespace climberConstants {

    //CAN ID
    constexpr int PHID = 8;

    //Solenoid Ports
    constexpr int solenoidForwardLeft = 2;
    constexpr int solenoidReverseLeft = 3;
    constexpr int solenoidForwardRight = 4;
    constexpr int solenoidReverseRight = 5;

}