// Coder: Lord Savith

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

USTRUCT(BlueprintType)
struct FMyInterpControlPoint
{
	GENERATED_USTRUCT_BODY()
public:
	// The position of the point 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Location, meta=(MakeEditWidget=true))
	FVector PositionControlPoint;
	
	// Is the location relative to the root components initial location
 	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Location)
 	bool bPositionIsRelative;

	FMyInterpControlPoint()
	{
		PositionControlPoint = FVector::ZeroVector;
		bPositionIsRelative = true;
	}
	FMyInterpControlPoint(FVector InPosition, bool bIsRelative)
	{
		PositionControlPoint = InPosition;
		bPositionIsRelative = bIsRelative;
	}

	float StartTime;
	float DistanceToNext;
	float Percentage;
};

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Moving Platform")
	FVector PlatformVelocity = FVector(100, 0, 0);

	FVector StartLocation;

	UPROPERTY(EditAnywhere, Category="Moving Platform", meta=(MakeEditWidget=true))
	float DistanceToMove = 100;

	/* List of control points to visit. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Moving Platform")
	TArray<FMyInterpControlPoint> ControlPoints;
};
