// Fill out your copyright notice in the Description page of Project Settings.

#include "Survival.h"
#include "TeamInfo.h"
#include "BaseAIController.h"
#include "BasePlayerController.h"

// Sets default values
ATeamInfo::ATeamInfo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ATeamInfo::BeginPlay()
{
	 Super::BeginPlay();
	
}

// Called every frame
void ATeamInfo::Tick(float DeltaTime)
{
	 Super::Tick(DeltaTime);

}


// Adds to the team
void ATeamInfo::AddToTeam(class AController* NewMember)
{
	  ITeamMember* TM = Cast<ITeamMember>(NewMember);

	  if (TM != nullptr)
	  {
		  ATeamInfo* OldTeam = TM->GetTeam();

		  if (OldTeam != nullptr)
		  {
			  //remove from the old team
			  if (OldTeam != this)
			  {
				  OldTeam->RemoveFromTeam(NewMember);
			  }
			  else
			  {
				  return;
			  }
		  }

		  ABaseAIController* AI = Cast<ABaseAIController>(NewMember);
		  ABasePlayerController* PC = Cast<ABasePlayerController>(NewMember);

		  if (PC != nullptr)
		  {
			  PC->Team = this;
		  }
		  else if (AI != nullptr)
		  {
			  AI->Team = this;
		  }

		  TeamMembers.Push(NewMember);

		  // update team leader
		  if (TeamLeader == nullptr ||
			  (PC != nullptr &&
				  Cast<ABasePlayerController>(TeamLeader) == nullptr))
		  {
			  TeamLeader = NewMember;
		  }
	  }
}

// Removes from team
void ATeamInfo::RemoveFromTeam(class AController* Member)
{
	if (TeamMembers.Remove(Member) != INDEX_NONE)
	{
		// check if team leader
		if (TeamLeader == Member)
		{
			ChooseTeamLeader();
		}
	 }
}

// Sets the team leader
void ATeamInfo::SetTeamLeader(AController* NewLeader)
{
	 if(NewLeader != nullptr &&
		 TeamLeader != NewLeader &&
		 TeamMembers.Contains(NewLeader))
	 {
		 TeamLeader = NewLeader;
	 }
}

void ATeamInfo::ChooseTeamLeader()
{
	 if(TeamMembers.Num())
	 {
		 // find the first player controller
		 for (auto* Member : TeamMembers)
		 {
			 if (Cast<ABasePlayerController>(Member) != nullptr)
			 {
				 TeamLeader = Member;
				 return;
			 }
		 }

		 //set the first ai
		 TeamLeader = TeamMembers[0];
	 }
	 else
	 {
		 TeamLeader = nullptr;
	 }
}
