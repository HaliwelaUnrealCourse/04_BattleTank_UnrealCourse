// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Curves/CurveFloat.h"
#include "CombustionEngine.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UCombustionEngine : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCombustionEngine();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle, float& Dummy);

	UFUNCTION(BlueprintCallable, Category = Input)
	void GetEngineTorque();

	void UpdateThrottle(float DeltaTime);

	void GetThrottle(float& EngineThrottle);

	void UpdateEngineTorque();

	UPROPERTY(EditDefaultsOnly, Category = Curve)
	UCurveFloat* EngineTorqueCurve;

	UPROPERTY(Transient)
	float EngineTorque;

private:
	UPROPERTY(Transient)
	float InputThrottle;

	UPROPERTY(Transient)
	float EngineThrottle;

};
