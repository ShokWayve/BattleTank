// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "Components/ActorComponent.h"
#include "MyTankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKPROJECT_API UMyTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMyTankAimingComponent();
	void SetBarrelReference(UStaticMeshComponent * BarrelToSet);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UStaticMeshComponent * Barrel = nullptr;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void AimLogging(FString AimingTankName, FVector Location);
};
