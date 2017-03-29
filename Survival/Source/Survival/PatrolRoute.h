// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Components/SplineComponent.h"
#include "PatrolRoute.generated.h"

UCLASS()
class SURVIVAL_API APatrolRoute : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category=Route,meta=(AllowPrivateAccess=true))
	class USplineComponent*	SplineComponent;

public:	

	// Sets default values for this actor's properties
	APatrolRoute();

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Returns the spline component
	FORCEINLINE class USplineComponent* GetSplineComponent() const { return SplineComponent; }


	
	
};
