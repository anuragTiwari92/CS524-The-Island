// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Survival.h"
#include "SurvivalGameMode.h"
#include "BaseCharacter.h"
#include "BasePlayerController.h"

ASurvivalGameMode::ASurvivalGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Game/Blueprints/BP_Character")); // (TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default player controller class
	PlayerControllerClass = ABasePlayerController::StaticClass();
}
