// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_StartMain.h"

TArray<FIconLevelPair> ACPP_StartMain::CalcalateIconsForRender(UPARAM(ref)FHungerStats& HungerStats)
{
	TArray<FIconLevelPair> CalculatedIconsAndLevels;

	// HUNGER

	int WarningHungerValue, FatalHungerValue;
	WarningHungerValue = HungerStats.WarningHungerValue;
	FatalHungerValue = HungerStats.FatalHungerValue;

	if (HungerStats.FatalHungerValue > HungerStats.WarningHungerValue)
	{
		WarningHungerValue = HungerStats.FatalHungerValue;
		FatalHungerValue = HungerStats.FatalHungerValue;
	}

	FIconLevelPair HungerPair;
	HungerPair.IconType = StatsIcon::Hunger;
	if (HungerStats.CurrentHunger <= WarningHungerValue)
	{
		if (HungerStats.CurrentHunger <= FatalHungerValue)
		{
			// Hunger Value in Fatal
			HungerPair.IconLevel = StatsIconLevel::Fatal;
			CalculatedIconsAndLevels.Emplace(HungerPair);
		}
		else
		{
			// Hunger Value in Warning
			HungerPair.IconLevel = StatsIconLevel::Warning;
			CalculatedIconsAndLevels.Emplace(HungerPair);
		}
	}

	return CalculatedIconsAndLevels;
}
