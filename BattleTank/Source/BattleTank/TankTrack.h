// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Curves/CurveFloat.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// Set throttle input from the user
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);

	// Engine torque curve
	UPROPERTY(EditDefaultsOnly, Category = EngineCurve)
	UCurveFloat* EngineTorqueCurve;

private:
	// The input the player set
	UPROPERTY(Transient)
	float RawThrottleInput;

	UPROPERTY()
	float EngineThrottle = 100000.0f;
};
