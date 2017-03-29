// Fill out your copyright notice in the Description page of Project Settings.

#include "Survival.h"
#include "BTTask_FindNextPatrolPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BaseAIController.h"
#include "BaseCharacter.h"
#include "PatrolRoute.h"






UBTTask_FindNextPatrolPoint::UBTTask_FindNextPatrolPoint()
{
	TargetLocation.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UBTTask_FindNextPatrolPoint, TargetLocation));
	PatrolRoute.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UBTTask_FindNextPatrolPoint, PatrolRoute), APatrolRoute::StaticClass());

}

/** initialize memory block */
void UBTTask_FindNextPatrolPoint::InitializeMemory(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, EBTMemoryInit::Type InitType) const
{
	Super::InitializeMemory(OwnerComp, NodeMemory, InitType);

	FBTFindNextPatrolPointMemory* pTaskMemory = reinterpret_cast<FBTFindNextPatrolPointMemory*>(NodeMemory);
	pTaskMemory->PatrolIndex = INDEX_NONE;
}

/** starts this task, should return Succeeded, Failed or InProgress
*  (use FinishLatentTask() when returning InProgress)
* this function should be considered as const (don't modify state of object) if node is not instanced! */
EBTNodeResult::Type UBTTask_FindNextPatrolPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	ABaseAIController* AI = Cast<ABaseAIController>(OwnerComp.GetAIOwner());
	ABaseCharacter* Character = AI != nullptr ? AI->GetBaseCharacter() : nullptr;
	APatrolRoute* TargetPatrolRoute = Cast<APatrolRoute>(BlackboardComp->GetValueAsObject(PatrolRoute.SelectedKeyName));

	if (Character == nullptr ||
		TargetPatrolRoute == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	// get the spline component
	USplineComponent* Spline = TargetPatrolRoute->GetSplineComponent();
	const int32 SplineCount = Spline->GetNumberOfSplinePoints();

	// no spline points
	if (SplineCount == 0)
	{
		return EBTNodeResult::Failed;
	}

	FBTFindNextPatrolPointMemory* pTaskMemory = reinterpret_cast<FBTFindNextPatrolPointMemory*>(NodeMemory);

	FVector CharacterLocation = Character->GetActorLocation();

	// this is a new patrol
	if (pTaskMemory->PatrolIndex == INDEX_NONE)
	{
		int32 ClosestSplinePoint = 0;
		float SmallestDistance = FVector::DistSquared(CharacterLocation, Spline->GetWorldLocationAtSplinePoint(0));

		for (int32 i = 1; i < SplineCount; i++)
		{
			float Distance = FVector::DistSquared(CharacterLocation, Spline->GetWorldLocationAtSplinePoint(i));
			if (Distance < SmallestDistance)
			{
				ClosestSplinePoint = i;
				SmallestDistance = Distance;
			}
		}

		pTaskMemory->PatrolIndex = ClosestSplinePoint;
	}
	else
	{
		pTaskMemory->PatrolIndex = (pTaskMemory->PatrolIndex + 1) % SplineCount;
	}

	BlackboardComp->SetValueAsVector(TargetLocation.SelectedKeyName, Spline->GetWorldLocationAtSplinePoint(pTaskMemory->PatrolIndex));

	return EBTNodeResult::Succeeded;
}