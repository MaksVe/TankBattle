// Fill out your copyright notice in the Description page of Project Settings.

#include "Robot.h"
#include "RobotAimingComponent.h"
#include "RobotBarrel.h"
#include "Projectile.h"
#include "Engine/World.h"

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

void ARobot::Fire()
{
	auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f: Tank fire"), Time);

	if (!Barrel) { return; }
	// Spawn a projectile at the socket location on the barrel
	GetWorld()->SpawnActor<AProjectile>(
		ProjectileBlueprint,
		Barrel->GetSocketLocation(FName("Projectile")),
		Barrel->GetSocketRotation(FName("Projectile"))
		);
}

void ARobot::SetBarrelReference(URobotBarrel * BarrelToSet)
{
	RobotAimingComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}

void ARobot::SetTurretReference(URobotTurret * TurretToSet)
{
	RobotAimingComponent->SetTurretReference(TurretToSet);
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



