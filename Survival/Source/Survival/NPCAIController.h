// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseAIController.h"
#include "NPCAIController.generated.h"

USTRUCT(BlueprintType)
struct FNPCEnemyPerceptionInfo
{
	GENERATED_BODY()

	UPROPERTY()
	TWeakObjectPtr<class ABaseCharacter>	Enemy;

	UPROPERTY()
	FVector LastSeenLocation;

	UPROPERTY()
	FVector LastViewLocation;

	UPROPERTY()
	uint32 bLostEnemy : 1;

	UPROPERTY()
	float LastUpdateTime;
};

/**
 * 
 */
UCLASS()
class SURVIVAL_API ANPCAIController : public ABaseAIController
{
	GENERATED_BODY()
	
	UPROPERTY()
	TMap<class ABaseCharacter*,FNPCEnemyPerceptionInfo>	KnownEnemies;

protected:

	virtual void UpdateKnownEnemies() override;
	
	
};
