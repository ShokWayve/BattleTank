// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

ATank * ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Player Controller Being Play"));

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

