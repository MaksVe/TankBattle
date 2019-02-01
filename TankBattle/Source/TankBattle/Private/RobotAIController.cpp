// Fill out your copyright notice in the Description page of Project Settings.

#include "RobotAIController.h"

#include "Robot.h"
#include "Engine/World.h"
#include "Engine/LocalPlayer.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Controller.h"

void ARobotAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ARobotAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerRobot = Cast<ARobot>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledRobot = Cast<ARobot>(GetPawn());

	if (PlayerRobot)
	{
		// TODO Move towards player

		// Aim towards the player
		ControlledRobot->AimAt(PlayerRobot->GetActorLocation());
		ControlledRobot->Fire(); // TODO don't fire every frame

	}
}