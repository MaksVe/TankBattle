// Fill out your copyright notice in the Description page of Project Settings.

#include "RobotAIController.h"

#include "Engine/World.h"
#include "Engine/LocalPlayer.h"
#include "GameFramework/Controller.h"

void ARobotAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledRobot = GetControlledRobot();
	if (!ControlledRobot)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller not possesing a robot"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller possesing %s"), *ControlledRobot->GetName());
	}
	UE_LOG(LogTemp, Warning, TEXT("AI Controller begin play"));

	auto PlayerRobot = GetPlayerRobot();
	if (!PlayerRobot)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player robot not found"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s found a %s"), *ControlledRobot->GetName(), *PlayerRobot->GetName());
	}
}

ARobot * ARobotAIController::GetPlayerRobot() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ARobot>(PlayerPawn);
}

ARobot* ARobotAIController::GetControlledRobot() const
{
	return Cast<ARobot>(GetPawn());
}