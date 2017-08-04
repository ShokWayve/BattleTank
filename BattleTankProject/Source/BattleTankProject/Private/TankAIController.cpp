// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	MyTank = GetControlledTank();

	if (MyTank != nullptr)
	{
		FString TankName = MyTank->GetName();
		//UE_LOG(LogTemp, Warning, TEXT("My AI Tank Name %s"), *TankName);
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("I, AI Overlord, don't have a tank! I demand a tank!"));
	}

	GetPlayerTank();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ATank * PlayerTank = nullptr;
	ATank * TankUnderMyControl = nullptr;
	PlayerTank = GetPlayerTank();
	TankUnderMyControl = GetControlledTank();

	if ((TankUnderMyControl != nullptr) && (PlayerTank != nullptr))
	{
		// TODO: Move towards the player

		// Aim towards the player
		TankUnderMyControl->AimAt(PlayerTank->GetActorLocation());

		// Fire if ready.
	}
}

ATank * ATankAIController::GetPlayerTank() const
{
	ATank * PlayerTank = nullptr;

	PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (PlayerTank != nullptr)
	{
		FString TankName = PlayerTank->GetName();
		//UE_LOG(LogTemp, Warning, TEXT("I found the player tank controller! Player name is %s"), *TankName);
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("AI Status: I can't find the player. No player, no game!"));		
	}

	return PlayerTank;
}


