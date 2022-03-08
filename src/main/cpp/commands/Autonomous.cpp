#include "commands/Autonomous.h"

Autonomous::Autonomous(climber* climber,
                       drivetrain* drivetrain,
                       harvester* harvester,
                       shooter* shooter,
                       indexer* indexer)
    : m_climber{climber},
      m_drivetrain{drivetrain},
      m_harvester{harvester},
      m_shooter{shooter},
      m_indexer{indexer} {
        SetName("Autonomous Routine");
        AddRequirements({m_climber, m_drivetrain, m_harvester, m_shooter, m_indexer});
      }

void Autonomous::Initialize() { printf("Autonomous intialized.\n"); }

void Autonomous::Execute() {}

void Autonomous::End(bool interrupted) { printf("**Autonomous has been interrutped!**\n"); }

bool Autonomous::IsFinished() { return false; }