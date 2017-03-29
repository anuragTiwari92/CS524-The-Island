// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"


USTRUCT(BlueprintType)
struct FAIPerceptionInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = AI, meta = (AllowPrivateAccess = true))
	float SightDistance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = AI, meta = (AllowPrivateAccess = true))
	float SightFOV;

};


UCLASS(config=Game)
class ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	/** Behavior Tree */
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=AI,meta=(AllowPrivateAccess="true"))
	class UBehaviorTree* BehaviorTree;

	/** Perception Info */
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=AI,meta=(AllowPrivateAccess=true))
	struct FAIPerceptionInfo	PerceptionInfo;

	/** Default Behavior */
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=AI,meta=(AllowPrivateAccess=true))
	TSubclassOf<class UAIBehaviorState>	DefaultBehaviorClass;

	/** All of the supported behaviors */
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=AI,meta=(AllowPrivateAccess=true))
	TArray<TSubclassOf<class UAIBehaviorState>>	CharacterBehaviors;

	// The Defense Point
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = AI, meta = (AllowPrivateAccess = true))
	class ADefensePoint*	DefensePoint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = AI, meta = (AllowPrivateAccess = true))
	class APatrolRoute*		PatrolRoute;

public:
	
	ABaseCharacter();

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	/** Returns BehaviorTree subobject **/
	FORCEINLINE class UBehaviorTree* GetBehaviorTree() const { return BehaviorTree; }
	/** Returns Perception Info */
	FORCEINLINE const FAIPerceptionInfo& GetPerceptionInfo() const { return PerceptionInfo; }
	/** Returns Default behavior class */
	FORCEINLINE const TSubclassOf<class UAIBehaviorState>& GetDefaultBehavior() const { return DefaultBehaviorClass; }
	/** Checks if supports the behavior */
	UFUNCTION(BlueprintCallable,Category=AI)
	bool HasBehavior(const TSubclassOf<class UAIBehaviorState>& BehaviorClass) const;

	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	virtual bool ShouldTakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) const override;
	virtual float ReceiveHealing(float HealAmount, AController* EventInstigator, AActor* Healer);
	virtual bool ShouldReceiveHealing(float HealAmount, AController* EventInstigator, AActor* Healer) const;

protected:

	friend class ABaseAIController;

	/** Called to initialize the blackboard */
	virtual void InitializeBlackboard(class UBlackboardComponent& BlackboardComp);
};

