// Fill out your copyright notice in the Description page of Project Settings.

#include "Survival.h"
#include "BT_CanSee.h"
#include "BaseAIController.h"
#include "BaseCharacter.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "BehaviorTree/BlackboardComponent.h"

UBT_CanSee::UBT_CanSee()
{
	BlackboardKey.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UBT_CanSee, BlackboardKey), AActor::StaticClass());
	BlackboardKey.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UBT_CanSee, BlackboardKey));
}

bool UBT_CanSee::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	ABaseAIController* AI = Cast<ABaseAIController>(OwnerComp.GetAIOwner());
	ABaseCharacter* Character = AI != nullptr ? AI->GetBaseCharacter() : nullptr;

	if (Character == nullptr)
	{
		return false;
	}

	// check the type
	if (BlackboardKey.SelectedKeyType == UBlackboardKeyType_Object::StaticClass())
	{
		AActor* Target = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(BlackboardKey.SelectedKeyName));

		if (Target != nullptr)
		{
			return AI->CanSee(Target);
		}

	}
	else if (BlackboardKey.SelectedKeyType == UBlackboardKeyType_Vector::StaticClass())
	{
		FVector TargetLocation = OwnerComp.GetBlackboardComponent()->GetValueAsVector(BlackboardKey.SelectedKeyName);

		return AI->CanSeeLocation(TargetLocation);
	}

	return false;
}



