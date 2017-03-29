// Fill out your copyright notice in the Description page of Project Settings.

#include "Survival.h"
#include "BasePlayerController.h"
#include "BaseCharacter.h"




ABasePlayerController::ABasePlayerController()
{
	// set our turn rates for input
	BaseTurnRate	= 45.f;
	BaseLookUpRate	 = 45.f;
}

void ABasePlayerController::SetupInputComponent()
{
	 Super::SetupInputComponent();

	 InputComponent->BindAction("Jump", IE_Pressed, this, &ABasePlayerController::Jump);
	 InputComponent->BindAction("Jump", IE_Released, this, &ABasePlayerController::StopJumping);

	 InputComponent->BindAxis("MoveForward", this, &ABasePlayerController::MoveForward);
	 InputComponent->BindAxis("MoveRight", this, &ABasePlayerController::MoveRight);

	 // We have 2 versions of the rotation bindings to handle different kinds of devices differently
	 // "turn" handles devices that provide an absolute delta, such as a mouse.
	 // "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	 InputComponent->BindAxis("Turn", this, &ABasePlayerController::AddYawInput);
	 InputComponent->BindAxis("TurnRate", this, &ABasePlayerController::TurnAtRate);
	 InputComponent->BindAxis("LookUp", this, &ABasePlayerController::AddPitchInput);
	 InputComponent->BindAxis("LookUpRate", this, &ABasePlayerController::LookUpAtRate);
}

void ABasePlayerController::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	 if(Rate != 0.0f)
		AddYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ABasePlayerController::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
		if(Rate != 0.0f)
			AddPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ABasePlayerController::MoveForward(float Value)
{
	if ((GetCharacter() != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		GetCharacter()->AddMovementInput(Direction, Value);
	}
}

void ABasePlayerController::MoveRight(float Value)
{
	if ((GetCharacter() != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
	 	GetCharacter()->AddMovementInput(Direction, Value);
	}
}


/**
*	Called via input to start jumping
*/
void ABasePlayerController::Jump()
{
	 if(GetCharacter() != nullptr)
	 {
		 GetCharacter()->Jump();
	 }
}

/**
*	Called via input to stop jumping
*/
void ABasePlayerController::StopJumping()
{
	 if(GetCharacter() != nullptr)
	 {
		 GetCharacter()->StopJumping();
	 }
}