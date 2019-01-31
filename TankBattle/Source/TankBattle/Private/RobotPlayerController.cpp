// Fill out your copyright notice in the Description page of Project Settings.


#include "RobotPlayerController.h"
#include "Robot.h"
#include "Engine/World.h"

void ARobotPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledRobot = GetControlledRobot();
	if (!ControlledRobot)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing a robot"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possesing %s"), *ControlledRobot->GetName());
	}
	UE_LOG(LogTemp, Warning, TEXT("PlayerController begin play"));
}

void ARobotPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsController();
}

void ARobotPlayerController::AimTowardsController()
{
	if (!GetControlledRobot()) { return; }
	
	FVector HitLocation; // OUT parameter
	if (GetSightRayHitLocation(HitLocation))
	{
		GetControlledRobot()->AimAt(HitLocation);
	}
}

bool ARobotPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const
{
	// Find the crosshair position
	// Deproject the position of the crosshair to a world direction
	
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);

	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		// Line-trace along that direction and see if we hit anything (up to max range)
		GetLookVectorHitLocation(LookDirection, OutHitLocation);
	}

	return true;
}

bool ARobotPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const
{
	FVector CameraWorldLocation; // To be discarded
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}

bool ARobotPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + LookDirection * LineTraceRange;
	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility)
		)
	{
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;
}

ARobot* ARobotPlayerController::GetControlledRobot() const
{
	return Cast<ARobot>(GetPawn());
}


