// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CircuitComponentAbstract.h"

/**
 * 
 */
class VoltageSource : public CircuitComponentAbstract
{
public:
	VoltageSource(int ID, float Voltage, int LowVoltageNodeID, int HighVoltageNodeID);
	float GetVoltage();
	int GetLowVoltageNodeID();
	int GetHighVoltageNodeID();
};
