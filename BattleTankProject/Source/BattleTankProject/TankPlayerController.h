// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKPROJECT_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank * GetControlledTank() const;
	ATank * MyTank = nullptr;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	int TickCount = 0;

	// Start the tank moving the barrel so that a shot would it where the
	// crosshair intersects the world.
	void AimTowardsCrosshair();
	bool GetSightlyRayHitLocation(FVector & OutHitLocation) const;
};
