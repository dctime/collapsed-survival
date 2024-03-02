// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/KismetSystemLibrary.h"
#include "CPP_PC_DesignLuminaCircuit.generated.h"
/**
 * 
 */
UCLASS(Blueprintable)
class DESIGNLUMINACIRCUIT_API ACPP_PC_DesignLuminaCircuit : public APlayerController
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void Move(float UpPositiveValue = 0, float RightPositiveValue = 0, float Speed = 1);

	UFUNCTION(BlueprintCallable)
	void PlaceComponent(float DetectionRange);
};
