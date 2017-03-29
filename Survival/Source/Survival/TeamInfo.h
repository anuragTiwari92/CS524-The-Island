// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "TeamInfo.generated.h"

UCLASS()
class SURVIVAL_API ATeamInfo : public AActor
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly,Category=Team,meta=(AllowPrivateAccess=true))
	class AController * TeamLeader;

	UPROPERTY(BlueprintReadOnly, Category = Team, meta = (AllowPrivateAccess = true))
	TArray<class AController*> TeamMembers;	
	
public:	

	// Sets default values for this actor's properties
	ATeamInfo();

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Adds to the team
	void AddToTeam(class AController* NewMember);

	// Removes from team
	void RemoveFromTeam(class AController* Member);

	// Sets the team leader
	void SetTeamLeader(AController* NewLeader);

	// Returns the team leader
	FORCEINLINE class AController* GetTeamLeader() const { return TeamLeader; }
	
private:

	// Chooses the team leader
	void ChooseTeamLeader();

};
