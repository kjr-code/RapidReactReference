#include "commands/Climb.h"

Climb::Climb(climber* climb, const climber::ClimbDirection& direction)
    : m_climber{climb},
      m_direction{direction} {
        SetName("Climb");
        AddRequirements({m_climber});
}

void Climb::Initialize() { printf("Climb initialized.\n"); }

void Climb::Execute() {
    m_climber->RunClimb(m_direction);
}

void Climb::End(bool interrupted) { printf("**Climb has been interrupted!**\n"); }

bool Climb::IsFinished() { return false; }