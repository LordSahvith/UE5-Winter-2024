// Coder: Lord Savith

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class GDT_OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditAnywhere, Category="Moving Platform")
	FVector PlatformVelocity = FVector(100, 0, 0);

	FVector StartLocation;

	UPROPERTY(EditAnywhere, Category="Moving Platform")
	float DistanceToMove = 100;

	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);

	bool ShouldPlatformReturn() const;
	float GetDistancedMoved() const;
};
