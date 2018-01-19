// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "MurderBegoneGameMode.h"
#include "MurderBegoneHUD.h"
#include "MurderBegoneCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMurderBegoneGameMode::AMurderBegoneGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AMurderBegoneHUD::StaticClass();
}
