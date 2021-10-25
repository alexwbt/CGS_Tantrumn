// Fill out your copyright notice in the Description page of Project Settings.


#include "TantrumnPlayerController.h"
#include "GameFramework/Character.h"

void ATantrumnPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    if (InputComponent)
    {
        InputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &ATantrumnPlayerController::OnJump);
        InputComponent->BindAxis("MoveForward", this, &ATantrumnPlayerController::OnMoveForward);
        InputComponent->BindAxis("MoveRight", this, &ATantrumnPlayerController::OnMoveRight);
        InputComponent->BindAxis("LookUp", this, &ATantrumnPlayerController::OnLookUp);
        InputComponent->BindAxis("LookRight", this, &ATantrumnPlayerController::OnLookRight);
    }
}

void ATantrumnPlayerController::OnJump()
{
    auto character = GetCharacter();
    if (character)
        character->Jump();
}

void ATantrumnPlayerController::OnMoveForward(float value)
{
    if (value)
    {
        auto rotation = GetControlRotation();
        GetPawn()->AddMovementInput(FRotationMatrix(rotation).GetScaledAxis(EAxis::X), value);
    }
}

void ATantrumnPlayerController::OnMoveRight(float value)
{
    if (value)
    {
        auto rotation = GetControlRotation();
        GetPawn()->AddMovementInput(FRotationMatrix(rotation).GetScaledAxis(EAxis::Y), value);
    }
}

void ATantrumnPlayerController::OnLookUp(float value)
{
    AddPitchInput(value * pitch_scale * GetWorld()->GetDeltaSeconds());
}

void ATantrumnPlayerController::OnLookRight(float value)
{
    AddYawInput(value * yaw_scale * GetWorld()->GetDeltaSeconds());
}
