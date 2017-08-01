// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "Engine.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKPROJECT_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	ATank * GetControlledTank() const;
	ATank * GetPlayerTank() const;
	ATank * MyTank = nullptr;
	virtual void BeginPlay() override;
};