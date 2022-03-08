#include "commands/ShootHigh.h"

ShootHigh::ShootHigh(shooter* shooter)
    : m_shooter{shooter} {
        SetName("ShootHigh");
        AddRequirements({m_shooter});
    }

void ShootHigh::Initialize() { printf("ShootHigh initialized.\n"); }

void ShootHigh::Execute() {
    m_shooter->RunShooter(shooter::ShooterBehavior::kOn, shooterConstants::motorMaxOutput);
    printf("Kobe.\n");}

void ShootHigh::End(bool interrupted) {
    m_shooter->RunShooter(shooter::ShooterBehavior::kOff);
}

bool ShootHigh::IsFinished() { return true; }