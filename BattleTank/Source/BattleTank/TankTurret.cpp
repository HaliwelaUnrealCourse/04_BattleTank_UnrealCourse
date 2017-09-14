// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine/World.h"



void UTankTurret::Rotate(float RelativeSpeed)
{
	// Move the turret the right amount this frame
	// Given a max rotation speed, and the frame time
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto NewRotation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, NewRotation, 0));
}
