// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "AIBehaviorState.h"
#include  "TeamMember.h"
#include "BaseAIController.generated.h"

/**
 * 
 */
UCLASS()
class SURVIVAL_API ABaseAIController : public AAIController ,
	public ITeamMember
{
	GENERATED_BODY()
	
	// The Base Character
	class ABaseCharacter*	BaseCharacter;

	// The Move Target
	UPROPERTY(BlueprintReadOnly,Category=AI,meta=(AllowPrivateAccess=true))
	class AActor* MoveTarget;

	// The Target
	UPROPERTY(BlueprintReadOnly,Category=AI,meta=(AllowPrivateAccess="true"))
	class AActor*	Target;

	// The Enemy
	UPROPERTY(BlueprintReadOnly,Category=AI,meta=(AllowPrivateAccess="true"))
	class ABaseCharacter* Enemy;

	// The Patrol Route
	UPROPERTY(BlueprintReadOnly, Category = AI, meta = (AllowPrivateAccess = "true"))
	class APatrolRoute*		PatrolRoute;

	// The Defense Point
	UPROPERTY(BlueprintReadOnly, Category = AI, meta = (AllowPrivateAccess = "true"))
	class ADefensePoint*	DefensePoint;

	// The current behavior state
	UPROPERTY(BlueprintReadOnly,Category=AI,meta=(AllowPrivateAccess=true))
	TSubclassOf<class UAIBehaviorState> BehaviorState;

public:

	ABaseAIController();

	// Returns the base character
	UFUNCTION(BlueprintCallable,Category=AI)
	FORCEINLINE class ABaseCharacter* GetBaseCharacter() const { return BaseCharacter;}

	// Returns the move target
	FORCEINLINE class AActor* GetMoveTarget() const { return MoveTarget; }

	// Returns the target
	FORCEINLINE class AActor* GetTarget() const { return Target; }

	// Returns the enemy
	FORCEINLINE class ABaseCharacter* GetEnemy() const { return Enemy; }

	// Returns the defense point
	FORCEINLINE class ADefensePoint* GetDefensePoint() const { return DefensePoint; }

	// Returns the patrol route
	FORCEINLINE class APatrolRoute* GetPatrolRoute() const { return PatrolRoute; }

	// Returns the behavior state
	FORCEINLINE const TSubclassOf<class UAIBehaviorState>& GetBehaviorState() const { return BehaviorState; }
	
	// Sets the behavior state
	UFUNCTION(BlueprintCallable,Category=AI)
	bool SetBehaviorState(const TSubclassOf<class UAIBehaviorState>& NewState);

	// Sets the target
	UFUNCTION(BlueprintCallable,Category=AI)
	void SetTarget(class AActor* Other);

	// Sets the move target
	UFUNCTION(BlueprintCallable,Category=AI)
	void SetMoveTarget(class AActor* Other);

	// Sets the enemy
	UFUNCTION(BlueprintCallable,Category=AI)
	void SetEnemy(class ABaseCharacter* NewEnemy);

	// Sets the patrol route
	UFUNCTION(BlueprintCallable, Category = AI)
	void SetPatrolRoute(class APatrolRoute* NewPatrolRoute);

	// Sets the defense point
	UFUNCTION(BlueprintCallable,Category=AI)
	void SetDefensePoint(class ADefensePoint* NewDefensePoint);

	// Checks if can set as enemy
	UFUNCTION(BlueprintCallable,Category=AI)
	bool CanTargetAsEnemy(const ABaseCharacter* Other) const;

	// Checks if can see
	UFUNCTION(BlueprintCallable,Category=AI)
	bool CanSee(const AActor* Other) const;

	// Checks if can see location
	UFUNCTION(BlueprintCallable,Category=AI)
	bool CanSeeLocation(const FVector& TargetLocation) const;
	
	/** Team Member */
	UPROPERTY(BlueprintReadOnly,Category=Team)
	class ATeamInfo*	Team;

	// Returns the team
	FORCEINLINE class ATeamInfo* GetTeam() const override { return Team; }

protected:

	virtual void Possess(APawn* InPawn) override;
	virtual void UnPossess() override;
	virtual bool InitializeBlackboard(UBlackboardComponent& BlackboardComp, UBlackboardData& BlackboardAsset) override;

	UFUNCTION(BlueprintCallable,Category=AI)
	virtual void UpdateKnownEnemies();	
};
