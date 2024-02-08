// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/PrimitiveComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/SphereComponent.h"
#include "Engine/World.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/Actor.h"
#include "CPP_MainCharacter.generated.h"


UCLASS(Blueprintable)
class COLLAPSEDSURVIVAL_API ACPP_MainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACPP_MainCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	int32 ColorToInt32(FLinearColor Color);

	UFUNCTION(BlueprintCallable)
	void DetectForward(UPARAM(ref)TMap<AActor*, float>& DetectedActors, UPARAM(ref)AActor*& CloseDetectedActor, UPARAM(ref)TArray<AActor*>& DisableActors, int DetectionAccuracy, UArrowComponent* HeadDetectArrow, UArrowComponent* FeetDetectArrow, USphereComponent* CancelCollision, int DetectRange, FLinearColor OutlineColor);

};
