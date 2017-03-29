// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_FindNextPatrolPoint.generated.h"

struct FBTFindNextPatrolPointMemory
{
	int32 PatrolIndex = INDEX_NONE;
};


/**
 * 
 */
UCLASS()
class SURVIVAL_API UBTTask_FindNextPatrolPoint : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:

	UBTTask_FindNextPatrolPoint();

	/** initialize memory block */
	virtual void InitializeMemory(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, EBTMemoryInit::Type InitType) const override;

	/** starts this task, should return Succeeded, Failed or InProgress
	*  (use FinishLatentTask() when returning InProgress)
	* this function should be considered as const (don't modify state of object) if node is not instanced! */
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	virtual uint16 GetInstanceMemorySize() const override { return sizeof(FBTFindNextPatrolPointMemory); }

protected:

	UPROPERTY(EditAnywhere, Category = Blackboard)
	struct FBlackboardKeySelector	TargetLocation;

	UPROPERTY(EditAnywhere, Category = Blackboard)
	struct FBlackboardKeySelector	PatrolRoute;
	
	
	
};
