// Fill out your copyright notice in the Description page of Project Settings.

#include "CombustionEngine.h"


// Sets default values for this component's properties
UCombustionEngine::UCombustionEngine()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCombustionEngine::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCombustionEngine::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UpdateThrottle(DeltaTime);
	UpdateEngineTorque();
}

void UCombustionEngine::SetThrottle(float Throttle, float & Dummy)
{
	Throttle = InputThrottle;
}

void UCombustionEngine::UpdateThrottle(float DeltaTime)
{
	bool bPickA;
	float A = 1.0f;
	float B = -2.0f;
	if (InputThrottle != 0.0f) 
	{ 
		bPickA = true;
		float A = 1.0f;
		EngineThrottle = A * DeltaTime + FMath::Clamp<float>(EngineThrottle, 0.0f, 1.0f);
	}
	else 
	{ 
		float B = -2.0f;
		EngineThrottle = B * DeltaTime + FMath::Clamp<float>(EngineThrottle, 0.0f, 1.0f);
	}
}

void UCombustionEngine::GetThrottle(float& EngineThrottle)
{
	EngineThrottle = EngineThrottle;
}

void UCombustionEngine::UpdateEngineTorque()
{
	EngineTorque = EngineTorqueCurve->GetFloatValue(0.0f) * EngineThrottle * 10000.0f;
}

void UCombustionEngine::GetEngineTorque()
{
	EngineTorque = EngineTorque;
}

