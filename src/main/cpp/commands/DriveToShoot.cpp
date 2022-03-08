#include "commands/DriveToShoot.h"

DriveToShoot::DriveToShoot(drivetrain* drivetrain)
    : m_drivetrain{drivetrain} {
        SetName("DriveToShoot");
        AddRequirements({m_drivetrain});
    }

void DriveToShoot::Initialize() {}

void DriveToShoot::Execute() {}

void DriveToShoot::End(bool interrupted) {}

bool DriveToShoot::IsFinished() { return true; }