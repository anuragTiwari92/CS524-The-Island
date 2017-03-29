// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TeamMember.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UTeamMember : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

/**
 * 
 */
class SURVIVAL_API ITeamMember
{
	GENERATED_IINTERFACE_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	// Returns the team member
	virtual class ATeamInfo* GetTeam() const = 0;
};
