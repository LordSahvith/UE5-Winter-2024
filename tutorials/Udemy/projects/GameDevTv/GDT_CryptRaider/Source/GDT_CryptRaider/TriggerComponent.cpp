// Fill out your copyright notice in the Description page of Project Settings.

#include "TriggerComponent.h"

// Sets default values for this component's properties
UTriggerComponent::UTriggerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UTriggerComponent::SetMover(UMover *NewMover)
{
	Mover = NewMover;
}

void UTriggerComponent::Unlock(AActor *OverlappedActor) const
{
	if (OverlappedActor->ActorHasTag(UnlockTagName))
	{
		UE_LOG(LogTemp, Warning, TEXT("Unlocking Actor: %s"), *GetAcceptableActor()->GetActorNameOrLabel());
		Mover->SetShouldMove(true);
	}
}

void UTriggerComponent::Lock() const
{
	UE_LOG(LogTemp, Warning, TEXT("Locked"));
	Mover->SetShouldMove(false);
}

/*
	FOR REFERENCE: didn't like iterating over list
	and didn't like Tick() constantly checking either
	now the BP's Begin/End Overlap Events calls 
	UnLock() & Lock() appropriately until I learn how 
	to properly handle events in C++
*/

// AActor *UTriggerComponent::GetAcceptableActor() const
// {
// 	TArray<AActor *> Actors;
// 	GetOverlappingActors(Actors);

// 	for (AActor *Actor : Actors)
// 	{
// 		if (Actor->ActorHasTag(UnlockTagName))
// 		{
// 			return Actor;
// 		}
// 	}

// 	return nullptr;
// }
