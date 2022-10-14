#include "commands/ShootHigh.h"

ShootHigh::ShootHigh(shooter* shooter, drivetrain* drivetrain)
    : m_shooter{shooter},
    m_drivetrain{drivetrain} {
        SetName("ShootHigh");
        AddRequirements({m_shooter, m_drivetrain});
    }

void ShootHigh::Initialize() { 
    m_drivetrain->SetBrakeMode(true);
    printf("ShootHigh initialized.\n"); 
    }

void ShootHigh::Execute() {

    
    m_shooter->RunShooter(shooter::ShooterBehavior::kHigh);

    if (maxAimDeviationDEG < abs(m_shooter->GetError())) {
        m_drivetrain->Center(m_shooter->GetError());
    } else {
        m_drivetrain->MecanumDrive(0,0,0);
    }

    //m_shooter->RunShooter(shooter::ShooterBehavior::kHigh);
    //printf("Kobe.\n");
    }

void ShootHigh::End(bool interrupted) {
    m_shooter->RunShooter(shooter::ShooterBehavior::kOff);
}

bool ShootHigh::IsFinished() { return false; }