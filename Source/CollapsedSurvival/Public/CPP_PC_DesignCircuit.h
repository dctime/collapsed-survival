// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "CPP_VectorFunctions.h"
#include "CPP_PC_DesignCircuit.generated.h"

/**
 * 
 */
UCLASS()
class COLLAPSEDSURVIVAL_API ACPP_PC_DesignCircuit : public APlayerController
{
	GENERATED_BODY()

private:
	float Rotation = 0.0;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AActor* PreviewedActor;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float TraceLength = 10000.0;


public:
	UFUNCTION(BlueprintCallable)
	void PreviewComponentOnTheBoard(UClass* ComponentClass, UClass* BoardClass);
	UFUNCTION(BlueprintCallable)
	void RotatePreviewQuarter();
	
};
