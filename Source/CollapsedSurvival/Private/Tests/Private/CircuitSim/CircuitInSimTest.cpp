#include "CircuitSim/CircuitInSim.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestNullConductanceMatrix, "CollapsedSurvivalTest.CircuitSim.CircuitInSimTest.TestNullConductanceMatrix", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestCircuitInSimComponents, "CollapsedSurvivalTest.CircuitSim.CircuitInSimTest.TestComponents", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FTestNullConductanceMatrix::RunTest(const FString& Parameters)
{
	// Make the test pass by returning true, or fail by returning false.
	CircuitInSim NullCircuit;
	int rowCount = static_cast<int>(NullCircuit.GetConductanceMatrix()->rows());
	int columnCount = static_cast<int>(NullCircuit.GetConductanceMatrix()->cols());
	if (rowCount != 0)
	{
		return false;
	}
		
	if (columnCount != 0)
	{
		return false;
	}

	return true;
}

bool FTestCircuitInSimComponents::RunTest(const FString& Parameters)
{
	return false;
}
#endif