#include "CircuitSim/VoltageSource.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestVoltageSourceInit, "CollapsedSurvivalTest.CircuitSim.VoltageSourceTest.Init", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FTestVoltageSourceInit::RunTest(const FString& Parameters)
{
	bool FindError = false;
	CircuitComponentAbstract* v1 = new VoltageSource(5, 5.0, 3, 4);
	VoltageSource* v1source = static_cast<VoltageSource*>(v1);

	if (v1source)
	{
		if (v1source->GetVoltage() != 5)
			FindError = true;
		if (v1source->GetLowVoltageNodeID() != 3)
			FindError = true;
		if (v1source->GetHighVoltageNodeID() != 4)
			FindError = true;
		if (v1source->GetID() != 5)
			FindError = true;
	}
	else
	{
		FindError = true;
	}
	
	delete v1;
	return !FindError;
}
#endif