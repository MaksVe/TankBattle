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
	void Elevate(float DegreesPerSecond);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 10; 

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegrees = 20;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegrees = 20;
};
