#include "commands/ShootHigh.h"

ShootHigh::ShootHigh(shooter* shooter, drivetrain* drivetrain)
    : m_shooter{shooter},
    m_drivetrain{drivetrain} {
        SetName("ShootHigh");
        AddRequirements({m_shooter});
    }

void ShootHigh::Initialize() { 
    m_drivetrain->SetBrakeMode(true);
    printf("ShootHigh initialized.\n"); 
    }

void ShootHigh::Execute() {

    if (maxAimDeviationDEG < m_shooter->GetError()) {
        m_drivetrain->Center(m_shooter->GetError());
    } else if (m_shooter->Goldilocks()) {
        m_shooter->RunShooter(shooter::ShooterBehavior::kHigh);
        m_drivetrain->MecanumDrive(0,0,0);
    } else {
        m_shooter->RunShooter(shooter::ShooterBehavior::kOff);
    }

    //m_shooter->RunShooter(shooter::ShooterBehavior::kHigh);
    printf("Kobe.\n");
    }

void ShootHigh::End(bool interrupted) {
    m_shooter->RunShooter(shooter::ShooterBehavior::kOff);
}

bool ShootHigh::IsFinished() { return true; }