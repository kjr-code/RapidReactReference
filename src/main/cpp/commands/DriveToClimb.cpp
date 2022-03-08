#include "commands/DriveToClimb.h"

DriveToClimb::DriveToClimb(drivetrain* drivetrain)
    : m_drivetrain{drivetrain} {
        SetName("DriveToClimb");
        AddRequirements({m_drivetrain});
    }

void DriveToClimb::Initialize() {}

void DriveToClimb::Execute() {}

void DriveToClimb::End(bool interrupted) {}

bool DriveToClimb::IsFinished() { return true; }