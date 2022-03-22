#pragma once

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

    constexpr double wheelDiameterInch = 8;

    constexpr bool voltageComp = true;
    constexpr double satVoltage = 10;

    constexpr bool driveMotorSaftey = false;

}

namespace harvesterConstants {

    //CAN ID
    constexpr int PHID = 8;
    constexpr int motorHarvester = 4;

    constexpr double motorMaxOutput = 0.5;

    //Solenoid Ports
    constexpr int solenoidForward = PLACEHOLDER_INT;
    constexpr int solenoidReverse = PLACEHOLDER_INT;

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

    constexpr double lowSpeedBase = 1500;
    constexpr double highSpeedBase = 2500;

    constexpr double shooterkP = 0;
    constexpr double shooterkI = 0;
    constexpr double shooterkD = 0;
    constexpr double shooterFF = 0;

    constexpr double maxDistanceFromTarget = 0;
    constexpr double minDistanceFromTarget = 0;
    constexpr double maxAimDeviation = 0;

    constexpr double targetHeightMeters = 0;
    constexpr double limelightHeightMeters = 0;
    constexpr double limelightAngleDEG = 0;



}

namespace climberConstants {

    //CAN ID
    constexpr int PHID = 8;

    //Solenoid Ports
    constexpr int solenoidForwardLeft = PLACEHOLDER_INT;
    constexpr int solenoidReverseLeft = PLACEHOLDER_INT;
    constexpr int solenoidForwardRight = PLACEHOLDER_INT;
    constexpr int solenoidReverseRight = PLACEHOLDER_INT;

}