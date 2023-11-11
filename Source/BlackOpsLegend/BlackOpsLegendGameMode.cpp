// Copyright Epic Games, Inc. All Rights Reserved.

#include "BlackOpsLegendGameMode.h"
#include "BlackOpsLegendCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABlackOpsLegendGameMode::ABlackOpsLegendGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
