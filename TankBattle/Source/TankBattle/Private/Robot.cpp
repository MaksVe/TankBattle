// Fill out your copyright notice in the Description page of Project Settings.

#include "Robot.h"
#include "RobotAimingComponent.h"

// Sets default values
ARobot::ARobot()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RobotAimingComponent = CreateDefaultSubobject<URobotAimingComponent>(FName("Aiming Component"));
}

void ARobot::AimAt(FVector HitLocation)
{
	RobotAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ARobot::SetBarrelReference(URobotBarrel * BarrelToSet)
{
	RobotAimingComponent->SetBarrelReference(BarrelToSet);
}

// Called when the game starts or when spawned
void ARobot::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ARobot::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

