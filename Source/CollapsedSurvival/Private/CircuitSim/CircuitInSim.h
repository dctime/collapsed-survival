// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include <Eigen/Dense>
#include "CircuitComponentAbstract.h"

/**
 * 
 */
class CircuitInSim
{
public:
	CircuitInSim();
	CircuitInSim(std::vector<CircuitComponentAbstract*>& Components);
	~CircuitInSim();
	Eigen::MatrixXd* GetConductanceMatrix();


private:
	int VoltageSourceCount = 0;
	int NodeCount = 0;
	int NextNodeID = 0;
	TMap<int, int> MatrixIDToRealID;

	Eigen::MatrixXd* ConductanceMatrix;
	std::vector<CircuitComponentAbstract*> Components;
};


