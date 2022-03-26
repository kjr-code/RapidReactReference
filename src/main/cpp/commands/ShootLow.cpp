#include "commands/ShootLow.h"

ShootLow::ShootLow(shooter* shooter)
    : m_shooter{shooter} {
        SetName("ShootLow");
        AddRequirements({m_shooter});
    }

void ShootLow::Initialize() { printf("ShootLow initialized.\n"); }

void ShootLow::Execute() { 
    
    m_shooter->RunShooter(shooter::ShooterBehavior::kLow);

    printf("Better than nothing, I guess.\n"); }

void ShootLow::End(bool interrupted) {
    m_shooter->RunShooter(shooter::ShooterBehavior::kOff);
}

bool ShootLow::IsFinished() { return false; }