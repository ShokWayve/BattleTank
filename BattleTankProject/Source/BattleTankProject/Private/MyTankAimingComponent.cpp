// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTankAimingComponent.h"
#include "../Public/MyTankAimingComponent.h"


// Sets default values for this component's properties
UMyTankAimingComponent::UMyTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UMyTankAimingComponent::SetBarrelReference(UStaticMeshComponent * BarrelToSet)
{
	Barrel = BarrelToSet;
}


// Called when the game starts
void UMyTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMyTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UMyTankAimingComponent::AimLogging(FString AimingTankName, FVector Location)
{
	auto OwnerTankName = GetOwner()->GetName();
	auto BarrelLocation = Barrel->GetComponentLocation();
	UE_LOG(LogTemp, Warning, TEXT("%s is aiming at %s from %s"), *OwnerTankName, *Location.ToString(), *BarrelLocation.ToString());
}

