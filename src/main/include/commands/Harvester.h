#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/harvester.h"

/**
 * The command that controls our harvester behavior. Takes argument for toggle between on/off and reverse.
 */
class Harvester
    : public frc2::CommandHelper<frc2::CommandBase, Harvester> {
 public:
  /**
   * Creates a new instance of Harvester command.
   *
   * @param harvester The subsystem used by this command.
   * @param direction The direction to run the harvester.
   */
  explicit Harvester(harvester* harvester, const harvester::HarvesterDirection& direction);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  harvester* m_harvester;
  const harvester::HarvesterDirection m_direction;
};
