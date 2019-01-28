// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Robot.h"

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RobotPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TANKBATTLE_API ARobotPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ARobot* GetControlledRobot() const;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	void AimTowardsController();
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector &HitLocation) const;

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.33333;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000;
};
