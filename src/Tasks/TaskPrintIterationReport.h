#pragma once
#include "TaskBase.h"
#include "../ProcessInfo.h"

#include "../OptProblems/OptProblemOriginal.h"

class TaskPrintIterationReport: public TaskBase
{
	public:
		TaskPrintIterationReport();
		virtual ~TaskPrintIterationReport();

		void run();
		virtual std::string getType();
	private:

		SHOTSettings::Settings *settings;
		//ProcessInfo *processInfo;

		double lastDualBound;
		double lastPrimalBound;

		int lastNumHyperplane;
};
