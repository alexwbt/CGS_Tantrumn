// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TantrumnPlayerController.generated.h"

/**
 *
 */
UCLASS()
class CGS_TANTRUMN_API ATantrumnPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    UPROPERTY();
    float pitch_scale = 90.0f;

    UPROPERTY();
    float yaw_scale = 90.0f;

public:
    void SetupInputComponent() override;

    void OnJump();
    void OnMoveForward(float value);
    void OnMoveRight(float value);
    void OnLookUp(float value);
    void OnLookRight(float value);

};
