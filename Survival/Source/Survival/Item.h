// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class SURVIVAL_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// Returns the inventory owner
	FORCEINLINE class ABaseCharacter* GetInventoryOwner() const { return InventoryOwner.Get(); }

	/**
	*	called to give this item to the owner
	*	@param NewOwner : the new owner
	*/
	UFUNCTION(BlueprintCallable,Category=Item)
	virtual bool AddToInventory(class ABaseCharacter* NewOwner);

	/** 
	*	called when removed from the owner
	*/
	UFUNCTION(BlueprintCallable, Category = Item)
	virtual void RemovedFromInventory();

	/** 
	*	called to set the inventory owner
	*/
	void SetInventoryOwner(class ABaseCharacter* NewOwner);

private:

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category=AI,meta=(AllowPrivateAccess=true))
	TWeakObjectPtr<class ABaseCharacter>	InventoryOwner;	
};
