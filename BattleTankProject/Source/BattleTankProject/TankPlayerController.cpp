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
		// UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *HitLocation.ToString());

		// Tell controlled tank to aim at this point.
	}	
}

// Get world location of linetrace through crosshair, true if hits landscape.
bool ATankPlayerController::GetSightlyRayHitLocation(FVector & OutHitLocation) const
{
	OutHitLocation = FVector(0.0);

	// Find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation;
	float CrosshairX = ViewportSizeX * CrosshairXLocation;
	float CrosshairY = ViewportSizeY * CrosshairYLocation;
	ScreenLocation = FVector2D(CrosshairX, CrosshairY);

	// "De-project" screen position of the crosshair to a world direction
	FVector LookLocation = FVector(0.0f);
	bool LookDirectionFound = GetLookDirection(ScreenLocation, LookLocation);

	// Linetrace along that look direction, and see what we hit (up to some max range)
	if (LookDirectionFound == true)
	{
		GetLookVectorHitLocation(LookLocation, OutHitLocation);
	}

	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const
{
	// "De-project" screen position of the crosshair to a world direction
	FVector WorldLocation = FVector(0.0f); // To be discarded.
	bool DeProjectResult = DeprojectScreenPositionToWorld(ScreenLocation.X,
		ScreenLocation.Y, WorldLocation, LookDirection);

	if (DeProjectResult == true)
	{
		//UE_LOG(LogTemp, Warning, TEXT("World Direction: %s"), *LookDirection.ToString());
		return DeProjectResult;
	}
	else
		//UE_LOG(LogTemp, Warning, TEXT("No World Location O Great One."));
		return DeProjectResult;

	return DeProjectResult;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookLocation, FVector & HitLocation) const
{
	FHitResult HitResult;
	FVector StartLocation = PlayerCameraManager->GetCameraLocation();	
	FVector EndLocation = StartLocation + (LookLocation * LineTraceRange);
	bool HitSuccessful = GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation,
		ECC_Visibility);

	if (HitSuccessful == true)
	{
		HitLocation = HitResult.Location;
		FString HitItemName = HitResult.GetActor()->GetName();
		FString HitResultLocation = HitResult.Location.ToString();
		UE_LOG(LogTemp, Warning, TEXT("I Hit: %s at Location: %s"), *HitItemName, *HitResultLocation);
	}
	else
	{
		HitLocation = FVector(0.0f);
		UE_LOG(LogTemp, Warning, TEXT("I Hit Nothing :-( at Location: %s"), *HitLocation.ToString());
		return HitSuccessful;		
	}

	return HitSuccessful;
}
