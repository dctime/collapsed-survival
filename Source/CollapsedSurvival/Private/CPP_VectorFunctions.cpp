// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_VectorFunctions.h"


float UCPP_VectorFunctions::GetAngleBetweenTwoVector(UClass* Class, FVector VectorStd, FVector VectorMeasure)
{
	float U1, U2, V1, V2;
	U1 = VectorStd.Y;
	U2 = VectorStd.X;
	V1 = VectorMeasure.Y;
	V2 = VectorMeasure.X;
	float ULength = sqrt(pow(U1, 2) + pow(U2, 2));
	float VLength = sqrt(pow(V1, 2) + pow(V2, 2));

	float Angle;
	if ((ULength * VLength) == 0)
	{
		Angle = 0;
	}
	else
	{
		float Temp = (U1 * V1 + U2 * V2) / (ULength * VLength);
		Temp = UKismetMathLibrary::FClamp(Temp, -1, 1);
		Angle = acos(Temp)/PI*180;
	} 

	float delta = U1 * V2 - U2 * V1;
	
	if (delta > 0)
	{
		// V is at the left hand side of U
		Angle = -Angle;
	}

	return Angle;
}

FVector UCPP_VectorFunctions::GetHundredFloorXY(FVector InputVector)
{
	int X = static_cast<int>(InputVector.X/100)*100;
	int Y = static_cast<int>(InputVector.Y/100)*100;
	float Z = InputVector.Z;


	return FVector(X, Y, Z);
}

int UCPP_VectorFunctions::IntTest()
{
	return 0;
}


