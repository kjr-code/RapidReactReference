#include "commands/Harvester.h"

Harvester::Harvester(harvester* harvester, const harvester::HarvesterDirection& direction)
    : m_harvester{harvester},
      m_direction{direction} {
        SetName("Harvester");
        AddRequirements({m_harvester});
    }

void Harvester::Initialize() {
    printf("harvester initialized");
}

void Harvester::Execute() {
    m_harvester->RunHarvester(m_direction);
}

void Harvester::End(bool interrupted) {
    m_harvester->RunHarvester(harvester::HarvesterDirection::kOff);
    printf("harvester interrupted");
}

bool Harvester::IsFinished() { return false; }