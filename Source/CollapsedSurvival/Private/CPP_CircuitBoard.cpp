// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_CircuitBoard.h"


// Sets default values
ACPP_CircuitBoard::ACPP_CircuitBoard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_CircuitBoard::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_CircuitBoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

TArray<FVector> ACPP_CircuitBoard::CalculateInputLocations(int BoardSize, int InputAmount)
{
	TArray<FVector> ReturnLocations;
	int X = (- (BoardSize - 1) / 2);
	InputAmount = UKismetMathLibrary::Clamp(InputAmount, 0, BoardSize);

	float Spacing = ((BoardSize * 1.0) / InputAmount);
	for (int i = 1; i <= InputAmount; i++)
	{
		ReturnLocations.Add(FVector(X*100, static_cast<int>(floor((X - 1) + (i * Spacing)))*100, 0));
	}
	return ReturnLocations;
}

TArray<FVector> ACPP_CircuitBoard::CalculateOutputLocations(int BoardSize, int OutputAmount) //9 2
{
	TArray<FVector> ReturnLocations;
	int X = ((BoardSize-1) / 2); //4
	OutputAmount = UKismetMathLibrary::Clamp(OutputAmount, 0, BoardSize);//2

	float Spacing = ((BoardSize * 1.0) / (OutputAmount)); //3
	for (int i = 1; i <= OutputAmount; i++)// 1 2
	{
		ReturnLocations.Add(FVector(X*100, static_cast<int>(floor((-X-1) + (i * Spacing)))*100, 0));
	}
	return ReturnLocations;
}

