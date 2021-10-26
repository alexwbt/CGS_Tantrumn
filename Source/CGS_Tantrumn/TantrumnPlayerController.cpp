// Fill out your copyright notice in the Description page of Project Settings.


#include "TantrumnPlayerController.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

void ATantrumnPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    if (InputComponent)
    {
        InputComponent->BindAxis("MoveForward", this, &ATantrumnPlayerController::OnMoveForward);
        InputComponent->BindAxis("MoveRight", this, &ATantrumnPlayerController::OnMoveRight);
        InputComponent->BindAxis("LookUp", this, &ATantrumnPlayerController::OnLookUp);
        InputComponent->BindAxis("LookRight", this, &ATantrumnPlayerController::OnLookRight);

        InputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &ATantrumnPlayerController::OnJump);
        InputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &ATantrumnPlayerController::OnJump);

        InputComponent->BindAction("Crouch", EInputEvent::IE_Pressed, this, &ATantrumnPlayerController::OnCrouchDown);
        InputComponent->BindAction("Crouch", EInputEvent::IE_Released, this, &ATantrumnPlayerController::OnCrouchUp);

        InputComponent->BindAction("Sprint", EInputEvent::IE_Pressed, this, &ATantrumnPlayerController::OnSprint);
        InputComponent->BindAction("Sprint", EInputEvent::IE_Released, this, &ATantrumnPlayerController::OnStopSprint);
    }
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

void ATantrumnPlayerController::OnJump()
{
    auto character = GetCharacter();
    if (character)
        character->Jump();
}

void ATantrumnPlayerController::OnStopJump()
{
    auto character = GetCharacter();
    if (character)
        character->StopJumping();
}

void ATantrumnPlayerController::OnCrouchDown()
{
    auto character = GetCharacter();
    if (character && character->GetMovementComponent()->IsMovingOnGround())
        character->Crouch();
}

void ATantrumnPlayerController::OnCrouchUp()
{
    auto character = GetCharacter();
    if (character)
        character->UnCrouch();
}

void ATantrumnPlayerController::OnSprint()
{
    auto character = GetCharacter();
    if (character)
        character->GetCharacterMovement()->MaxWalkSpeed *= 2.0f;
}

void ATantrumnPlayerController::OnStopSprint()
{
    auto character = GetCharacter();
    if (character)
        character->GetCharacterMovement()->MaxWalkSpeed /= 2.0f;
}
