// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "Engine/World.h"

#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// UPhysicsHandleComponent MUST be set on the Actor as a Component or it will be a nullptr, causing system crash
	UPhysicsHandleComponent *PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();

	if (PhysicsHandle != nullptr)
	{
		UE_LOG(LogTemp, Display, TEXT("Physics Handle Present: %s"), *PhysicsHandle->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No Physics Handle on the actor (via bp?)."));
	}
}

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UPhysicsHandleComponent *PhysicsHandle = GetPhysicsHandle();
	if (PhysicsHandle == nullptr)
		return;

	FVector TargetLocation = GetComponentLocation() + GetForwardVector() * HoldDistance;
	PhysicsHandle->SetTargetLocationAndRotation(TargetLocation, GetComponentRotation());
}

void UGrabber::Grab()
{
	UPhysicsHandleComponent *PhysicsHandle = GetPhysicsHandle();
	if (PhysicsHandle == nullptr)
		return;

	FVector LineStart = GetComponentLocation();
	FVector LineEnd = LineStart + GetForwardVector() * MaxGrabDistance;
	FCollisionShape Sphere = FCollisionShape::MakeSphere(GrabRadius);
	FHitResult HitResult;
	
	bool bHasHit = GetWorld()->SweepSingleByChannel(
		HitResult,
		LineStart,
		LineEnd,
		FQuat::Identity,
		ECC_GameTraceChannel2,
		Sphere);

	if (bHasHit)
	{
		PhysicsHandle->GrabComponentAtLocationWithRotation(
			HitResult.GetComponent(),
			NAME_None,
			HitResult.ImpactPoint,
			GetComponentRotation());
	}
}

void UGrabber::Release()
{
	UE_LOG(LogTemp, Warning, TEXT("Release()"));
}

UPhysicsHandleComponent *UGrabber::GetPhysicsHandle() const
{
	UPhysicsHandleComponent *PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (PhysicsHandle == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Grabber requires a UPhysicsHandleComponent."));
	}

	return PhysicsHandle;
}
