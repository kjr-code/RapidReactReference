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

    constexpr double motorMaxOutput = 0.5;
    constexpr double motorDeadband = 0.1;

}

namespace harvesterConstants {

    //CAN ID
    constexpr int PHID = 8;
    constexpr int motorHarvester = 4;

    constexpr double motorMaxOutput = 0.5;

    //Solenoid Ports
    constexpr int solenoidForwardLeft = PLACEHOLDER_INT;
    constexpr int solenoidReverseLeft = PLACEHOLDER_INT;
    constexpr int solenoidForwardRight = PLACEHOLDER_INT;
    constexpr int solenoidReverseRight = PLACEHOLDER_INT;

}

namespace indexerConstants {

    //CAN ID
    constexpr int motorIndexer = 5;

    constexpr double motorMaxOutput = 0.5;

}

namespace shooterConstants {

    //CAN ID
    constexpr int motorShooter = 7;

    constexpr double motorMaxOutput = 0.5;

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