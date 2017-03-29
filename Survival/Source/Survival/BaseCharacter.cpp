// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Survival.h"
#include "BaseCharacter.h"
#include "BaseAIController.h"
#include "PatrolRoute.h"
#include "DefensePoint.h"

//////////////////////////////////////////////////////////////////////////
// ABaseCharacter

ABaseCharacter::ABaseCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

												// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

												   // Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
												   // are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)

												   // Set the AI Controller Class
	AIControllerClass = ABaseAIController::StaticClass();


	PerceptionInfo.SightDistance = 15000.0f;
	PerceptionInfo.SightFOV = 90.0f;
}

void ABaseCharacter::InitializeBlackboard(class UBlackboardComponent& BlackboardComp)
{
	ABaseAIController* AI = Cast<ABaseAIController>(Controller);

	if (AI != nullptr)
	{
		AI->SetBehaviorState(DefaultBehaviorClass);
		AI->SetDefensePoint(DefensePoint);
		AI->SetPatrolRoute(PatrolRoute);
	}
}

bool ABaseCharacter::HasBehavior(const TSubclassOf<class UAIBehaviorState>& BehaviorClass) const
{
	for (auto& Behavior : CharacterBehaviors)
	{
		if (Behavior == BehaviorClass)
		{
			return true;
		}
	}
	return false;
}

float ABaseCharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float DamageAmount = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

	if (DamageAmount == 0.0f)
	{
		return 0.0f;
	}

	/*ICombatParticipant* ThisCP = Cast<ICombatParticipant>(Controller);
	UCombatSystemComponent* ThisCS = ThisCP != nullptr ? ThisCP->GetCombatComponent() : nullptr;

	if (ThisCS != nullptr)
	{
		ThisCS->NotifyTakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	}

	ICombatParticipant* OtherCP = Cast<ICombatParticipant>(EventInstigator);
	UCombatSystemComponent* OtherCS = OtherCP != nullptr ? OtherCP->GetCombatComponent() : nullptr;

	if (OtherCS != nullptr)
	{
		OtherCS->NotifyDoDamage(this, DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	}*/

	return DamageAmount;
}

bool ABaseCharacter::ShouldTakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) const
{
	return Super::ShouldTakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
}

float ABaseCharacter::ReceiveHealing(float HealAmount, AController* EventInstigator, AActor* Healer)
{
	if (!ShouldReceiveHealing(HealAmount, EventInstigator, Healer))
	{
		return 0.0f;
	}


	/*ICombatParticipant* ThisCP = Cast<ICombatParticipant>(Controller);
	UCombatSystemComponent* ThisCS = ThisCP != nullptr ? ThisCP->GetCombatComponent() : nullptr;

	if (ThisCS != nullptr)
	{
		ThisCS->NotifyReceiveHealing(HealAmount, EventInstigator, Healer);
	}

	ICombatParticipant* OtherCP = Cast<ICombatParticipant>(EventInstigator);
	UCombatSystemComponent* OtherCS = OtherCP != nullptr ? OtherCP->GetCombatComponent() : nullptr;

	if (OtherCS != nullptr)
	{
		OtherCS->NotifyDoHealing(this, HealAmount, EventInstigator, Healer);
	}*/

	return HealAmount;
}

bool ABaseCharacter::ShouldReceiveHealing(float HealAmount, AController* EventInstigator, AActor* Healer) const
{
	 return true;
}