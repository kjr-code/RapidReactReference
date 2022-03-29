#include "commands/Index.h"

Index::Index(indexer* indexer, const indexer::IndexerDirection& direction)
    : m_indexer{indexer},
      m_direction{direction} {
        SetName("Index");
        AddRequirements({m_indexer});
}

void Index::Initialize() { printf("Index initialized.\n"); }

void Index::Execute() {
    m_indexer->RunIndexer(m_direction);
}

void Index::End(bool interrupted) { 
  m_indexer->RunIndexer(indexer::IndexerDirection::kOff);
  printf("**Index has been interrupted!**\n"); }

bool Index::IsFinished() { return false; }