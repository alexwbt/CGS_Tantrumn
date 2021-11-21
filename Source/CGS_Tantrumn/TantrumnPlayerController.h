// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TantrumnPlayerController.generated.h"

class ATantrumnGameModeBase;

/**
 *
 */
UCLASS()
class CGS_TANTRUMN_API ATantrumnPlayerController : public APlayerController
{
    GENERATED_BODY()

private:
    ATantrumnGameModeBase* game_mode_ref_;

    float pitch_scale_ = 90.0f;
    float yaw_scale_ = 90.0f;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Throwable", meta = (AllowPrivateAccess = "true"));
    bool pulling_throwable_ = false;


public:
    virtual void BeginPlay() override;

protected:
    void SetupInputComponent() override;

    void OnMoveForward(float value);
    void OnMoveRight(float value);
    void OnLookUp(float value);
    void OnLookRight(float value);

    void OnJump();
    void OnStopJump();

    void OnCrouchDown();
    void OnCrouchUp();

    void OnSprint();
    void OnStopSprint();

    void OnPullThrowable();
    void OnStopPullThrowable();

    void OnThrow();

private:
    bool IsGameStatePlaying();

};
