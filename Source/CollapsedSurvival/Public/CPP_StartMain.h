// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Containers/EnumAsByte.h"
#include "CPP_StartMain.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FHungerStats
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CurrentHunger;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int WarningHungerValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int FatalHungerValue;
};



UENUM(BlueprintType)
enum StatsIcon
{
	None,
	Hunger
};

UENUM(BlueprintType)
enum StatsIconLevel
{
	Normal,
	Warning,
	Fatal
};

USTRUCT(BlueprintType)
struct FIconLevelPair
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<StatsIcon> IconType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<StatsIconLevel> IconLevel;
};

UCLASS(Blueprintable)
class COLLAPSEDSURVIVAL_API ACPP_StartMain : public APlayerState
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	TArray<FIconLevelPair> CalcalateIconsForRender(UPARAM(ref)FHungerStats& HungerStats);
};
