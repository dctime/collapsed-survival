// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Math/Vector.h"
#include <cmath>
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "CPP_VectorFunctions.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class COLLAPSEDSURVIVAL_API UCPP_VectorFunctions : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	static float GetAngleBetweenTwoVector(UClass* Class, FVector VectorStd, FVector VectorMeasure);
};
