// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class CircuitComponentAbstract
{
public:
	CircuitComponentAbstract(int ID, int NodeInID, int NodeOutID, int ComponentValue);
	int GetID();
protected:
	int ID = -1;
	int NodeInID = -1;
	int NodeOutID = -1;
	int ComponentValue = -1;

};
