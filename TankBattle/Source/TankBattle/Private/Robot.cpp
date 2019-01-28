// Fill out your copyright notice in the Description page of Project Settings.

#include "Robot.h"

// Sets default values
ARobot::ARobot()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RobotAimingComponent = CreateDefaultSubobject<URobotAimingComponent>(FName("Aiming Component"));
}

void ARobot::AimAt(FVector HitLocation)
{
	RobotAimingComponent->AimAt(HitLocation);
}

void ARobot::SetBarrelReference(UStaticMeshComponent * BarrelToSet)
{
	RobotAimingComponent->SetBarrelReference(BarrelToSet);
}

// Called when the game starts or when spawned
void ARobot::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARobot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARobot::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

