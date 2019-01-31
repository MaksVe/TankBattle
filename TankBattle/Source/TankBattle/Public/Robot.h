// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Robot.generated.h"

class URobotBarrel;
class URobotTurret;
class URobotAimingComponent;
class AProjectile;

UCLASS()
class TANKBATTLE_API ARobot : public APawn
{
	GENERATED_BODY()

public:	
	// Sets default values for this pawn's properties
	ARobot();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable)
	void Fire();

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(URobotBarrel* BarrelToSet);
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(URobotTurret* TurretToSet);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	URobotAimingComponent* RobotAimingComponent = nullptr;

private:
	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 100000.f; // TODO find sensible default

	UPROPERTY(EditAnywhere, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint; // https://docs.unrealengine.com/en-US/Programming/UnrealArchitecture/TSubclassOf

	// Local barrel reference for spawning projectile
	URobotBarrel* Barrel = nullptr;
};
