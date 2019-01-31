// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "RobotTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class TANKBATTLE_API URobotTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// max downward speed is -1
	// max up movement +1
	void Rotate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 10;
};
