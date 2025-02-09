// Copyright Epic Games, Inc. All Rights Reserved.

#include "GDT_CryptRaiderGameMode.h"
#include "GDT_CryptRaiderCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGDT_CryptRaiderGameMode::AGDT_CryptRaiderGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
