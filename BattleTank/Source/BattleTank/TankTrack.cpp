// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"


void UTankTrack::SetThrottle(float Throttle)
{
	// Calculate the throttle input, engine throttle and engine torque curve to get the engine torque.
	RawThrottleInput = FMath::Clamp<float>(Throttle, 0.0f, 1.0f);
	auto EngineTorque = EngineTorqueCurve->GetFloatValue(0.0f) * EngineThrottle * RawThrottleInput;

	// Applying the engine torque to the sprocket
	auto TorqueApplied = GetForwardVector() * EngineTorque * 0.5f;
	auto TorqueLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(TorqueApplied, TorqueLocation);
}