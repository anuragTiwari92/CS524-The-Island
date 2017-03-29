// Fill out your copyright notice in the Description page of Project Settings.

#include "Survival.h"
#include "UsableActor.h"


// Sets default values
AUsableActor::AUsableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AUsableActor::BeginPlay()
{
	 Super::BeginPlay();
	
}

// Called every frame
void AUsableActor::Tick(float DeltaTime)
{
	 Super::Tick(DeltaTime);

}

bool AUsableActor::UseActor(class ABaseCharacter* Target)
{
	  check(Target);

	  return true;
}

