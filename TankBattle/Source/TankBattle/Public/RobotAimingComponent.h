// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RobotAimingComponent.generated.h"

// Forward Declaration
class URobotBarrel;


// Hold barrels' properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKBATTLE_API URobotAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URobotAimingComponent();

	void AimAt(FVector HitLocation, float LaunchSpeed);
	void SetBarrelReference(URobotBarrel* BarrelToSet);
	// TODO add SetTurretReference
private:
	URobotBarrel* Barrel = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
};
