// Fill out your copyright notice in the Description page of Project Settings.


#include "CircuitSim/CircuitComponentAbstract.h"

CircuitComponentAbstract::CircuitComponentAbstract(int ID, int NodeInID, int NodeOutID, int ComponentValue)
{
	this->ID = ID;
	this->NodeInID = NodeInID;
	this->NodeOutID = NodeOutID;
	this->ComponentValue = ComponentValue;
}

int CircuitComponentAbstract::GetID()
{
	return this->ID;
}

