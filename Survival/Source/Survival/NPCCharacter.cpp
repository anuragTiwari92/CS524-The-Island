// Fill out your copyright notice in the Description page of Project Settings.

#include "Survival.h"
#include "NPCCharacter.h"
#include "BaseAIController.h"
#include "TeamInfo.h"
#include "NPCAIController.h"

ANPCCharacter::ANPCCharacter()
{
	//set the ai controller class
	AIControllerClass = ANPCAIController::StaticClass();
}

void ANPCCharacter::PossessedBy(AController* NewController)
{
	 Super::PossessedBy(NewController);

	  if(Team != nullptr &&
		  Controller != nullptr)
	  {
		  Team->AddToTeam(NewController);

		  // set the team leader
		  if (bIsTeamLeader)
		  {
			  Team->SetTeamLeader(NewController);
		  }
	  }
}

void ANPCCharacter::UnPossessed()
{
	 if (Team != nullptr &&
		Controller != nullptr)
	 {
		Team->RemoveFromTeam(Controller);
	 }

	 Super::UnPossessed();
}

void ANPCCharacter::InitializeBlackboard(class UBlackboardComponent& BlackboardComp)
{
	 Super::InitializeBlackboard(BlackboardComp);

	 ABaseAIController* AI = Cast<ABaseAIController>(Controller);

	 AI->SetMoveTarget(FollowTarget);
}