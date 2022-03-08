#include "commands/ShootLow.h"

ShootLow::ShootLow(shooter* shooter)
    : m_shooter{shooter} {
        SetName("ShootLow");
        AddRequirements({m_shooter});
    }

void ShootLow::Initialize() { printf("ShootLow initialized.\n"); }

void ShootLow::Execute() { printf("Better than nothing, I guess.\n"); }

void ShootLow::End(bool interrupted) {}

bool ShootLow::IsFinished() { return true; }