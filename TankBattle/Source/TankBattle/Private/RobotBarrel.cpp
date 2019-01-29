// Fill out your copyright notice in the Description page of Project Settings.

#include "RobotBarrel.h"

void URobotBarrel::Elevate(float DegreesPerSecond)
{
	UE_LOG(LogTemp, Warning, TEXT("Barrel->Elevate() called at speed %f"), DegreesPerSecond);
}