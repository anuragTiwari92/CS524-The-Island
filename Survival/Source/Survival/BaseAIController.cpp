// Fill out your copyright notice in the Description page of Project Settings.

#include "Survival.h"
#include "BaseAIController.h"
#include "BaseCharacter.h"
#include "PatrolRoute.h"
#include "DefensePoint.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"




ABaseAIController::ABaseAIController()
{
	BaseCharacter = nullptr;
}

void ABaseAIController::Possess(APawn* InPawn)
{
	 Super::Possess(InPawn);
	 BaseCharacter = Cast<ABaseCharacter>(GetCharacter());
	 UBehaviorTree* BehaviorTree = BaseCharacter != nullptr ? BaseCharacter->GetBehaviorTree() : nullptr;
	 
	 if (BehaviorTree != nullptr &&
		 BehaviorTree->BlackboardAsset != nullptr)
	 {
		 RunBehaviorTree(BehaviorTree);

		 //initialize the character
		 BaseCharacter->InitializeBlackboard(*Blackboard);
	 }
}

void ABaseAIController::UnPossess()
{
	 Super::UnPossess();
	 BaseCharacter = nullptr;

	 UBehaviorTreeComponent* BTComponent = Cast<UBehaviorTreeComponent>(BrainComponent);

	 if (BTComponent != nullptr)
	 {
		 BTComponent->StopTree();
	 }
}

bool ABaseAIController::InitializeBlackboard(UBlackboardComponent& BlackboardComp, UBlackboardData& BlackboardAsset)
{
	 if(!Super::InitializeBlackboard(BlackboardComp,BlackboardAsset))
	 {
		 return false;
	 }

	 return true;
}

void ABaseAIController::SetTarget(class AActor* Other)
{
	 if(Target != Other)
	 {
		 Target = Other;

		 // update the blackboard
		 if (Blackboard != nullptr)
		 {
			 if (Target != nullptr)
				 Blackboard->SetValueAsObject(TEXT("Target"), Target);
			 else
				 Blackboard->ClearValue(TEXT("Target"));
		 }
	 }
}

void ABaseAIController::SetMoveTarget(class AActor* Other)
{
	 if(MoveTarget != Other)
	 {
		 MoveTarget = Other;
		 
		 // update the blackboard
		 if (Blackboard != nullptr)
		 {
			 if (MoveTarget != nullptr)
				 Blackboard->SetValueAsObject(TEXT("MoveTarget"), MoveTarget);
			 else
				 Blackboard->ClearValue(TEXT("MoveTarget"));
		 }
	 }
}

void ABaseAIController::SetEnemy(class ABaseCharacter* NewEnemy)
{
	 if(Enemy != NewEnemy &&  CanTargetAsEnemy(NewEnemy))
	 {
		 NewEnemy = Enemy;

		 // update the blackboard
		 if (Blackboard != nullptr)
		 {
			 if (Enemy != nullptr)
				 Blackboard->SetValueAsObject(TEXT("Enemy"), Enemy);
			 else
				 Blackboard->ClearValue(TEXT("Enemy"));
		 }
	 }
}

// Sets the patrol route
void ABaseAIController::SetPatrolRoute(class APatrolRoute* NewPatrolRoute)
{
	 if(PatrolRoute != NewPatrolRoute)
	 {
		 PatrolRoute = NewPatrolRoute;

		 // update the blackboard
		 if (Blackboard != nullptr)
		 {
			 if (PatrolRoute != nullptr)
				 Blackboard->SetValueAsObject(TEXT("PatrolRoute"), PatrolRoute);
			 else
				 Blackboard->ClearValue(TEXT("PatrolRoute"));
		 }
	 }
}

// Sets the defense point
void ABaseAIController::SetDefensePoint(class ADefensePoint* NewDefensePoint)
{
	 if(DefensePoint != NewDefensePoint)
	 {
		 DefensePoint = NewDefensePoint;

		 // update the blackboard
		 if (Blackboard != nullptr)
		 {
			 if (DefensePoint != nullptr)
				 Blackboard->SetValueAsObject(TEXT("DefensePoint"), DefensePoint);
			 else
				 Blackboard->ClearValue(TEXT("DefensePoint"));
		 }
	 }
}

bool ABaseAIController::CanTargetAsEnemy(const ABaseCharacter* Other) const
{
	if (BaseCharacter == nullptr ||
		BaseCharacter == Other)
	{
		return false;
	}


	 return false;
}

// Checks if can see
bool ABaseAIController::CanSee(const AActor* Other) const
{
	if (BaseCharacter == nullptr ||
		Other)
	{
		return false;
	 }

	FVector TargetDirection = Other->GetActorLocation() - GetCharacter()->GetActorLocation();
	float Distance = TargetDirection.Size();
	TargetDirection /= Distance;

	// check sight distance
	if (Distance > BaseCharacter->GetPerceptionInfo().SightDistance)
	{
		return false;
	}

	const float viewDotProduct = FVector::DotProduct(TargetDirection, GetCharacter()->GetActorForwardVector());
	const float cosFOV = FMath::Cos(BaseCharacter->GetPerceptionInfo().SightFOV);

	// check view angle
	if (viewDotProduct < cosFOV)
	{
		return false;
	}

	// check line of sight
	return LineOfSightTo(Other);
}

// Checks if can see location
bool ABaseAIController::CanSeeLocation(const FVector& TargetLocation) const
{
	 if(BaseCharacter == nullptr)
	 {
		 return false;
	 }

	 FVector TargetDirection = TargetLocation - GetCharacter()->GetActorLocation();
	 float Distance = TargetDirection.Size();
	 TargetDirection /= Distance;

	 // check sight distance
	 if (Distance > BaseCharacter->GetPerceptionInfo().SightDistance)
	 {
		 return false;
	 }

	 const float viewDotProduct = FVector::DotProduct(TargetDirection, GetCharacter()->GetActorForwardVector());
	 const float cosFOV = FMath::Cos(BaseCharacter->GetPerceptionInfo().SightFOV);

	 // check view angle
	 if (viewDotProduct < cosFOV)
	 {
		 return false;
	 }

	 // check line of sight
	 FVector ViewPoint;
	 FRotator ViewRotation;
	 GetActorEyesViewPoint(ViewPoint, ViewRotation);

	 static FName NAME_LineOfSight = FName(TEXT("LineOfSight"));

	 FCollisionQueryParams CollisionParams(NAME_LineOfSight, true, this->GetPawn());

	 bool bHit = GetWorld()->LineTraceTestByChannel(ViewPoint, TargetLocation, ECC_Visibility, CollisionParams);
	 if (!bHit)
	 {
		 return true;
	 }

	 return false;
}

bool ABaseAIController::SetBehaviorState(const TSubclassOf<class UAIBehaviorState>& NewState)
{
	 // must have a character , and it must support the state
	 if(BaseCharacter == nullptr ||
		 !BaseCharacter->HasBehavior(NewState))
	 {
		 return false;
	 }

	 // attempting to go into the same state
	 if (BehaviorState == NewState)
	 {
		 return true;
	 }

	 BehaviorState = NewState;

	 // update the blackboard
	 if (Blackboard != nullptr)
	 {
		 if (BehaviorState != nullptr)
		 {
			 Blackboard->SetValueAsObject(TEXT("BehaviorState"), BehaviorState->GetDefaultObject());
		 }
		 else
		 {
			 Blackboard->ClearValue(TEXT("BehaviorState"));
		 }
	 }

	 return true;
}

void ABaseAIController::UpdateKnownEnemies()
{

}