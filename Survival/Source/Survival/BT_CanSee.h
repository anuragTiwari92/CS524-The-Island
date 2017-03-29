// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/Decorators/BTDecorator_BlackboardBase.h"
#include "BT_CanSee.generated.h"

/**
 * 
 */
UCLASS()
class SURVIVAL_API UBT_CanSee : public UBTDecorator_BlackboardBase
{
	GENERATED_BODY()
	
public:

	UBT_CanSee();

	/** calculates raw, core value of decorator's condition. Should not include calling IsInversed */
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;	
	
};
