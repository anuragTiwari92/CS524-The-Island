// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Item.h"
#include "UsableItem.generated.h"

/**
 * 
 */
UCLASS()
class SURVIVAL_API AUsableItem : public AItem
{
	GENERATED_BODY()
	

public:

	UFUNCTION(BlueprintCallable,Category=Item)
	virtual bool UseItem();	
	
	
};
