// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Player Controller Begin Play"));

	MyTank = GetControlledTank();

	if (MyTank != nullptr)
	{
		FString TankName = MyTank->GetName();
		UE_LOG(LogTemp, Warning, TEXT("My Tank Name %s"), *TankName);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("I don't have a tank!  Why!? I want a tank!"));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank * ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank())
	{
		return;
	}

	FVector HitLocation; // Out paramater

	if (GetSightlyRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());

		// Tell controlled tank to aim at this point.
	}	
}

// Get world location of linetrace through crosshair, true if hits landscape.
bool ATankPlayerController::GetSightlyRayHitLocation(FVector & OutHitLocation) const
{
	OutHitLocation = FVector(0.0);
	return true;
}
