// Fill out your copyright notice in the Description page of Project Settings.


#include "CircuitSim/CircuitInSim.h"

CircuitInSim::CircuitInSim()
{
	this->ConductanceMatrix->resize(0, 0);
}

CircuitInSim::CircuitInSim(std::vector<CircuitComponentAbstract*>& Components)
{
	this->Components = Components;
}

CircuitInSim::~CircuitInSim()
{

}

Eigen::MatrixXd* CircuitInSim::GetConductanceMatrix()
{
	return this->ConductanceMatrix;
}
