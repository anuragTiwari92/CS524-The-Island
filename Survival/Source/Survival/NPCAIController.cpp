// Fill out your copyright notice in the Description page of Project Settings.

#include "Survival.h"
#include "NPCAIController.h"
#include "NPCCharacter.h"



void ANPCAIController::UpdateKnownEnemies()
{
	 //requires a character
	 if (GetBaseCharacter() == nullptr)
	 {
		return;
	 }
	 
	for (auto Iter = GetWorld()->GetPawnIterator(); Iter; ++Iter)
	{
		ABaseCharacter* TargetChar = Cast<ABaseCharacter>(*Iter);

		// check if can target
		if (TargetChar != nullptr &&
			CanTargetAsEnemy(TargetChar))
		{
			// check if can see
			if (CanSee(TargetChar))
			{
				// get the perception info
				FNPCEnemyPerceptionInfo* PerceptionInfo = KnownEnemies.Find(TargetChar);

				// create if necessary
				if (PerceptionInfo == nullptr)
				{
					PerceptionInfo = &KnownEnemies.Add(TargetChar, FNPCEnemyPerceptionInfo());
				
					PerceptionInfo->Enemy = TargetChar;
				}

				PerceptionInfo->LastSeenLocation = TargetChar->GetActorLocation();
				PerceptionInfo->LastViewLocation = GetBaseCharacter()->GetActorLocation();
				PerceptionInfo->LastUpdateTime = GetWorld()->TimeSeconds;				
			}
		}
	}
}