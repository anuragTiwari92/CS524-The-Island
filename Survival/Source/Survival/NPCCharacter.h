// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseCharacter.h"
#include "NPCCharacter.generated.h"

/**
 * 
 */
UCLASS()
class SURVIVAL_API ANPCCharacter : public ABaseCharacter
{
	GENERATED_BODY()
	
	UPROPERTY(EditInstanceOnly,Category=Team)
	class ATeamInfo*	Team;

	UPROPERTY(EditInstanceOnly, Category = Team)
	uint32 bIsTeamLeader : 1;

	UPROPERTY(EditInstanceOnly, Category=AI)
	class AActor* FollowTarget;

public:

	ANPCCharacter();

protected:

	virtual void PossessedBy(AController* NewController) override;
	virtual void UnPossessed() override;
	virtual void InitializeBlackboard(class UBlackboardComponent& BlackboardComp) override;
};
