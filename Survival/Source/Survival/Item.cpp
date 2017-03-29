// Fill out your copyright notice in the Description page of Project Settings.

#include "Survival.h"
#include "Item.h"
#include "BaseCharacter.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


bool AItem::AddToInventory(class ABaseCharacter* NewOwner)
{
	check(!InventoryOwner.Get());
	check(NewOwner != nullptr);

	InventoryOwner = NewOwner;
	return true;
}

/**
*	called when removed from the owner
*/
void AItem::RemovedFromInventory()
{
	check(InventoryOwner.Get());

	InventoryOwner = nullptr;
}

/**
*	called to set the inventory owner
*/
void AItem::SetInventoryOwner(class ABaseCharacter* NewOwner)
{
	InventoryOwner = NewOwner;
}