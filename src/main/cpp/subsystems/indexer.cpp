#include <subsystems/indexer.h>

indexer::indexer() {
  // Implementation of subsystem constructor goes here.
  m_motorIndexer.ConfigFactoryDefault();
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
        throw std::invalid_argument("Invalid IndexerDirection.\n");
    }
}

void indexer::Periodic() {
  // Implementation of subsystem periodic method goes here.

}

void indexer::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
  
}