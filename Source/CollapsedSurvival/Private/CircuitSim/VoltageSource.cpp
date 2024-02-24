// Fill out your copyright notice in the Description page of Project Settings.


#include "CircuitSim/VoltageSource.h"
#include <Eigen/Dense>

VoltageSource::VoltageSource(int ID, float Voltage, int LowVoltageNodeID, int HighVoltageNodeID)
	:CircuitComponentAbstract(ID, LowVoltageNodeID, HighVoltageNodeID, Voltage)
{
	
}

float VoltageSource::GetVoltage()
{
	return this->ComponentValue;
}

int VoltageSource::GetLowVoltageNodeID()
{
	return this->NodeInID;
}

int VoltageSource::GetHighVoltageNodeID()
{
	return this->NodeOutID;
}

