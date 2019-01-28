// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Robot.h"



#include "CoreMinimal.h"
#include "AIController.h"
#include "RobotAIController.generated.h"

/**
 * 
 */
UCLASS()
class TANKBATTLE_API ARobotAIController : public AAIController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	ARobot* GetPlayerRobot() const;
	ARobot* GetControlledRobot() const;
};
