// Fill out your copyright notice in the Description page of Project Settings.


#include "TantrumnPlayerController.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "TantrumnGameModeBase.h"
#include "TantrumnCharacter.h"


void ATantrumnPlayerController::BeginPlay()
{
    Super::BeginPlay();

    game_mode_ref_ = Cast<ATantrumnGameModeBase>(GetWorld()->GetAuthGameMode());
}

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

        InputComponent->BindAction("PullThrowable", EInputEvent::IE_Pressed, this, &ATantrumnPlayerController::OnPullThrowable);
        InputComponent->BindAction("PullThrowable", EInputEvent::IE_Released, this, &ATantrumnPlayerController::OnStopPullThrowable);

        //InputComponent->BindAction("Throw", EInputEvent::IE_Pressed, this, &ATantrumnPlayerController::OnThrow);
    }
}

void ATantrumnPlayerController::OnMoveForward(float value)
{
    if (pulling_throwable_)
        return;

    bool is_playing = IsGameStatePlaying();
    if (is_playing && value)
    {
        auto rotation = GetControlRotation();
        GetPawn()->AddMovementInput(FRotationMatrix(rotation).GetScaledAxis(EAxis::X), value);
    }
}

void ATantrumnPlayerController::OnMoveRight(float value)
{
    if (pulling_throwable_)
        return;

    bool is_playing = IsGameStatePlaying();
    if (is_playing && value)
    {
        auto rotation = GetControlRotation();
        GetPawn()->AddMovementInput(FRotationMatrix(rotation).GetScaledAxis(EAxis::Y), value);
    }
}

void ATantrumnPlayerController::OnLookUp(float value)
{
    AddPitchInput(value * pitch_scale_ * GetWorld()->GetDeltaSeconds());
}

void ATantrumnPlayerController::OnLookRight(float value)
{
    AddYawInput(value * yaw_scale_ * GetWorld()->GetDeltaSeconds());
}

void ATantrumnPlayerController::OnJump()
{
    if (pulling_throwable_)
        return;

    bool is_playing = IsGameStatePlaying();
    if (!is_playing)
        return;

    const auto character = GetCharacter();
    if (character)
        character->Jump();
}

void ATantrumnPlayerController::OnStopJump()
{
    const auto character = GetCharacter();
    if (character)
        character->StopJumping();
}

void ATantrumnPlayerController::OnCrouchDown()
{
    bool is_playing = IsGameStatePlaying();
    if (!is_playing)
        return;

    const auto character = GetCharacter();
    if (character && character->GetMovementComponent()->IsMovingOnGround())
        character->Crouch();
}

void ATantrumnPlayerController::OnCrouchUp()
{
    const auto character = GetCharacter();
    if (character)
        character->UnCrouch();
}

void ATantrumnPlayerController::OnSprint()
{
    bool is_playing = IsGameStatePlaying();
    if (!is_playing)
        return;

    const auto character = GetCharacter();
    if (character)
        character->GetCharacterMovement()->MaxWalkSpeed *= 2.0f;
}

void ATantrumnPlayerController::OnStopSprint()
{
    const auto character = GetCharacter();
    if (character)
        character->GetCharacterMovement()->MaxWalkSpeed /= 2.0f;
}

void ATantrumnPlayerController::OnPullThrowable()
{
    bool is_playing = IsGameStatePlaying();
    if (!is_playing)
        return;

    const auto character = GetCharacter();
    if (!character)
        return;

    const auto movement = character->GetMovementComponent();
    if (!movement)
        return;

    if (movement->Velocity.IsNearlyZero())
        pulling_throwable_ = true;
}

void ATantrumnPlayerController::OnStopPullThrowable()
{
    pulling_throwable_ = false;
}

void ATantrumnPlayerController::OnThrow()
{
    bool is_playing = IsGameStatePlaying();
    if (!is_playing)
        return;

    const auto character = Cast<ATantrumnCharacter>(GetCharacter());
    if (character)
        character->PlayThrowMontage();
}

bool ATantrumnPlayerController::IsGameStatePlaying()
{
    return game_mode_ref_ && game_mode_ref_->GetCurrentGameState() == EGameState::Playing;
}
