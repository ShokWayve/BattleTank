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
};
