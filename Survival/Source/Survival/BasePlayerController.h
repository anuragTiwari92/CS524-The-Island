// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TeamMember.h"
#include "BasePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SURVIVAL_API ABasePlayerController : public APlayerController ,
	public ITeamMember
{
	GENERATED_BODY()

public:

	ABasePlayerController();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseLookUpRate;

	/** Team Member */
	UPROPERTY(BlueprintReadOnly,Category=Team)
	class ATeamInfo*	Team;

	// Returns the team
	FORCEINLINE class ATeamInfo* GetTeam() const override { return Team; }

protected:

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/**
	* Called via input to turn at a given rate.
	* @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	*/
	void TurnAtRate(float Rate);

	/**
	* Called via input to turn look up/down at a given rate.
	* @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	*/
	void LookUpAtRate(float Rate);

	/**
	*	Called via input to start jumping
	*/
	void Jump();

	/**
	*	Called via input to stop jumping
	*/
	void StopJumping();

	/**
	*	Called to set up input component
	*/
	virtual void SetupInputComponent() override;
	
	
	
};
