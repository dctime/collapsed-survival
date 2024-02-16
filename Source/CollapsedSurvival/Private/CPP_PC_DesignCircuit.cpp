// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_PC_DesignCircuit.h"

void ACPP_PC_DesignCircuit::PreviewComponentOnTheBoard(UClass* ComponentClass, UClass* BoardClass)
{
	FVector StartTrace;
	FVector EndTrace;
	FVector DirTrace;

	DeprojectMousePositionToWorld(StartTrace, DirTrace);
	EndTrace = StartTrace + DirTrace * TraceLength;

	FHitResult TraceResult;
	TArray<AActor*> IgnoreActors;

	if (IsValid(PreviewedActor))
	{
		IgnoreActors.Add(PreviewedActor);
	}
	UKismetSystemLibrary::LineTraceSingle(this, StartTrace, EndTrace, ETraceTypeQuery::TraceTypeQuery1, false, IgnoreActors, EDrawDebugTrace::None, TraceResult, true);

	AActor* HitActor = TraceResult.GetActor();
	FVector HitLocation = TraceResult.ImpactPoint;

	if (IsValid(PreviewedActor) && PreviewedActor->GetActorLocation() != HitLocation)
	{
		PreviewedActor->Destroy();
		PreviewedActor = nullptr;
	}
	
	if (UGameplayStatics::ObjectIsA(HitActor, BoardClass))
	{
		UWorld* World = GetWorld();
		

		if (PreviewedActor == nullptr)
		{
			PreviewedActor = World->SpawnActor<AActor>(ComponentClass, HitLocation, FRotator(0, 0, 0));
			TArray<AActor*> Overlapping;
			PreviewedActor->GetOverlappingActors(Overlapping);
			if (Overlapping.Num() > 0)
			{
				PreviewedActor->Destroy();
				PreviewedActor = nullptr;
			}
		}
	}

}
