// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_PC_DesignLuminaCircuit.h"

void ACPP_PC_DesignLuminaCircuit::Move(float UpPositiveValue, float RightPositiveValue, float Speed)
{
	APawn* ControlledPawn = K2_GetPawn();
	if (!ControlledPawn)
		return;
	
	FTransform CurrentTransform = ControlledPawn->GetTransform();
	float NewX = CurrentTransform.GetLocation().X + RightPositiveValue * Speed;
	float NewY = CurrentTransform.GetLocation().Y;
	float NewZ = CurrentTransform.GetLocation().Z + UpPositiveValue * Speed;
	FVector NewLocation(NewX, NewY, NewZ);
	ControlledPawn->SetActorLocation(NewLocation);

}

