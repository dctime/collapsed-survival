// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class CollapsedSurvivalTarget : TargetRules
{
	public CollapsedSurvivalTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V4;
		ExtraModuleNames.Add("CollapsedSurvival");
        ExtraModuleNames.Add("CircuitSim");
        ExtraModuleNames.Add("DesignLuminaCircuit");
    }
}
