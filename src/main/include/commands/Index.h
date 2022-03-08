#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/indexer.h"

/**
 * The command that controls our Indexing.
 */
class Index
    : public frc2::CommandHelper<frc2::CommandBase, Index> {
 public:
  /**
   * Creates a new instance of Index command.
   *
   * @param indexer The subsystem used by this command.
   * @param direction The direction to index.
   */
  explicit Index(indexer* indexer, const indexer::IndexerDirection& direction);
  
  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  indexer* m_indexer;
  const indexer::IndexerDirection& m_direction;
};
