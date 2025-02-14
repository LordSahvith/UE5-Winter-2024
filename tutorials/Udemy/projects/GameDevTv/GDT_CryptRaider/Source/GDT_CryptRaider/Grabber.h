// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"

#include "Grabber.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class GDT_CRYPTRAIDER_API UGrabber : public USceneComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void Grab();

	UFUNCTION(BlueprintCallable)
	void Release();

private:
	UPROPERTY(EditAnywhere)
	float MaxGrabDistance = 800.0; // 1 unit = 1 cm : 400 cm = 4 m

	UPROPERTY(EditAnywhere)
	float HoldDistance = 200.0; // 1 unit = 1 cm : 200 cm = 2 m

	UPROPERTY(EditAnywhere)
	float GrabRadius = 100.0;

	UPROPERTY(EditAnywhere)
	float InterpSpeed = 10.0;

	UPhysicsHandleComponent *GetPhysicsHandle() const;

	bool GetGrabbableInReach(FHitResult &OutHitResult) const;

	void HoldGrabbable() const;

	bool bIsGrabbed = false;
};
