// Fill out your copyright notice in the Description page of Project Settings.

#include "Survival.h"
#include "GameObjective.h"


// Sets default values
AGameObjective::AGameObjective()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AGameObjective::BeginPlay()
{
	 Super::BeginPlay();
	
}

// Called every frame
void AGameObjective::Tick(float DeltaTime)
{
	 Super::Tick(DeltaTime);

}

