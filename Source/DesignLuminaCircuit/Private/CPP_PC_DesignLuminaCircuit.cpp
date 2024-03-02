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

	FVector OriginalLocation(CurrentTransform.GetLocation().X, CurrentTransform.GetLocation().Y, CurrentTransform.GetLocation().Z);
	FVector NewLocation(NewX, NewY, NewZ);

	FVector Displacement = NewLocation - OriginalLocation;
	
	for (int i = 1; i <= 1000; ++i)
	{
		FVector SettingLocation = (Displacement / 1000) * i + OriginalLocation;
		ControlledPawn->SetActorLocation(SettingLocation);
	}
}

void ACPP_PC_DesignLuminaCircuit::PlaceComponent(float DetectionRange)
{
	FVector ClickFromPosition;
	FVector ClickDirection;
	if (DeprojectMousePositionToWorld(ClickFromPosition, ClickDirection))
	{
		UKismetSystemLibrary::PrintString(this, "ClickFromPosition: " + ClickFromPosition.ToString());
		

		FHitResult ClickResult;
		FVector EndPosition = ClickFromPosition + ClickDirection * DetectionRange;
		TArray<AActor*> IgnoreActors;
		if (UKismetSystemLibrary::LineTraceSingle(this, ClickFromPosition, EndPosition, 
			ETraceTypeQuery::TraceTypeQuery1, false, IgnoreActors, EDrawDebugTrace::ForDuration,
			ClickResult, true))
		{
			FVector HitPosition = static_cast<FVector>(ClickResult.ImpactPoint);
			UKismetSystemLibrary::DrawDebugPoint(this, HitPosition, 1, FColor(255, 255, 255), 10);
			UKismetSystemLibrary::PrintString(this, "HitPosition: " + HitPosition.ToString());
		}
	}

}

