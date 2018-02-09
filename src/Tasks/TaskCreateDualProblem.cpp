/*
 * TaskCreateDualProblem.cpp
 *
 *  Created on: Apr 1, 2015
 *      Author: alundell
 */

#include "TaskCreateDualProblem.h"

TaskCreateDualProblem::TaskCreateDualProblem(IMIPSolver *MIPSolver)
{
	this->MIPSolver = MIPSolver;

	ProcessInfo::getInstance().startTimer("Reformulation");

	ProcessInfo::getInstance().outputDebug("Creating dual problem");

	MIPSolver->createLinearProblem(ProcessInfo::getInstance().originalProblem);

	MIPSolver->initializeSolverSettings();

	if (Settings::getInstance().getBoolSetting("Debug.Enable", "Output"))
	{
		MIPSolver->writeProblemToFile(Settings::getInstance().getStringSetting("Debug.Path", "Output") + "/lp0.lp");
	}

	ProcessInfo::getInstance().outputDebug("Dual problem created");
	ProcessInfo::getInstance().stopTimer("Reformulation");

}

TaskCreateDualProblem::~TaskCreateDualProblem()
{
	// TODO Auto-generated destructor stub
}

void TaskCreateDualProblem::run()
{
}

std::string TaskCreateDualProblem::getType()
{
	std::string type = typeid(this).name();
	return (type);

}
