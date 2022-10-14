#include <subsystems/indexer.h>

indexer::indexer() {
  // Implementation of subsystem constructor goes here.
  m_motorIndexer.SetInverted(indexerConstants::indexerInverted);
  m_motorIndexer.ConfigVoltageCompSaturation(indexerConstants::satVoltage);
  m_motorIndexer.SetNeutralMode(ctre::phoenix::motorcontrol::Brake);
  m_motorIndexer.EnableVoltageCompensation(indexerConstants::voltageComp);
}

void indexer::RunIndexer(const IndexerDirection& direction) {
    switch(direction) {
      case IndexerDirection::kForward :
        m_motorIndexer.Set(indexerConstants::motorMaxOutput);
        break;
      case IndexerDirection::kReverse :
        m_motorIndexer.Set(-indexerConstants::motorMaxOutput);
        break;
      case IndexerDirection::kOff :
        m_motorIndexer.Set(0);
        break;
      default :
        m_motorIndexer.Set(0);
        break;
    }
}

void indexer::Periodic() {
  // Implementation of subsystem periodic method goes here.

}

void indexer::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
  
}