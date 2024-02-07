// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_MainCharacter.h"


// Sets default values
ACPP_MainCharacter::ACPP_MainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_MainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_MainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPP_MainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

int32 ACPP_MainCharacter::ColorToInt32(FLinearColor Color)
{
	float H, S, V, A;
	UKismetMathLibrary::RGBToHSV(Color, H, S, V, A);
	
	return UKismetMathLibrary::FTrunc((H / 360.0 * 254.0 + 1.0));
}

void ACPP_MainCharacter::DetectForward(UPARAM(ref)TMap<AActor*, float>& DetectedActors, UPARAM(ref)AActor*& CloseDetectedActor, UPARAM(ref)TArray<AActor*>& DisableActors, int DetectionAccuracy, UArrowComponent* HeadDetectArrow, UArrowComponent* FeetDetectArrow, USphereComponent* CancelCollision, int DetectRange, FLinearColor OutlineColor)
{
	TArray<FVector> DetectionPointArray;

	DetectedActors.Empty();
	DetectionPointArray.Empty();
	CloseDetectedActor = nullptr;

	
	for (int index = 0; index <= DetectionAccuracy; index++)
	{
		float Magnification = (1 / static_cast<float>(DetectionAccuracy)) * index;
		FVector HeadVector = HeadDetectArrow->GetComponentLocation();
		FVector FeetVector = FeetDetectArrow->GetComponentLocation();

		DetectionPointArray.Add((HeadVector - FeetVector) * Magnification + FeetVector);
	}

	TArray<UPrimitiveComponent*> CancelCollisionOverlapping;
	CancelCollision->GetOverlappingComponents(CancelCollisionOverlapping);
	CancelCollision->GetOverlappingActors(DisableActors);
	for (UPrimitiveComponent*& component : CancelCollisionOverlapping)
	{
		component->SetRenderCustomDepth(false);
	}

	for (auto& DetectionPoint:DetectionPointArray)
	{
		FVector BaseVector = DetectionPoint;
		FVector StartVector = BaseVector;

		FVector EndVector = GetActorForwardVector() * DetectRange + StartVector;
		FHitResult Result;

		TArray<AActor*> IgnoreActors;
		UKismetSystemLibrary::LineTraceSingle(this, StartVector, EndVector, ETraceTypeQuery::TraceTypeQuery1, false, IgnoreActors, EDrawDebugTrace::None, Result, true);

		AActor* HitActor = Result.GetActor();
		if (IsValid(HitActor))
		{
			DetectedActors.Add((HitActor), Result.Distance);
		}
	}

	TArray<AActor*> DetectedActorsKeys;
	DetectedActors.GetKeys(DetectedActorsKeys);
	for (AActor* DetectedActorKey : DetectedActorsKeys)
	{
		if (IsValid(CloseDetectedActor))
		{
			// Closest bigger than current
			if (DetectedActors.Find(DetectedActorKey) < DetectedActors.Find(CloseDetectedActor))
			{
				CloseDetectedActor = DetectedActorKey;
			}
		}
		else
		{
			CloseDetectedActor = DetectedActorKey;
		}
	}

	if (IsValid(CloseDetectedActor))
	{
		TSet<UActorComponent*> Components = CloseDetectedActor->GetComponents();
		for (UActorComponent* Component : Components)
		{
			UPrimitiveComponent* PrimitiveComponent = Cast<UPrimitiveComponent>(Component);
			if (IsValid(PrimitiveComponent))
			{
				PrimitiveComponent->SetRenderCustomDepth(true);
				PrimitiveComponent->SetCustomDepthStencilValue(ColorToInt32(OutlineColor));
			}
			
		}
	}
	
}


