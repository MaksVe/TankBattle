// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "RobotBarrel.generated.h"

/**
 * 
 */
UCLASS( meta = (BlueprintSpawnableComponent) )
class TANKBATTLE_API URobotBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// max downward speed is -1
	// max up movement +1
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDegreesPerSecond = 10; 

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxElevationDegrees = 20;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MinElevationDegrees = 20;
};
