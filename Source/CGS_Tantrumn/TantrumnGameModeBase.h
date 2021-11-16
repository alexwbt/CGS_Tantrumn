// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TantrumnGameModeBase.generated.h"

UENUM(BlueprintType)
enum class EGameState : uint8
{
    None UMETA(DisplayName = "None"),
    Waiting UMETA(DisplayName = "Waiting"),
    Playing UMETA(DisplayName = "Playing"),
    Paused UMETA(DisplayName = "Paused"),
    GameOver UMETA(DisplayName = "GameOver")
};

UCLASS()
class CGS_TANTRUMN_API ATantrumnGameModeBase : public AGameModeBase
{
    GENERATED_BODY()

private:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "States", meta = (AllowPrivateAccess = "true"));
    EGameState current_game_state_ = EGameState::None;

    UPROPERTY(EditAnywhere, Category = "Game Details");
    float game_countdown_duration_ = 4.0f;

    FTimerHandle timer_handle_;

public:
    ATantrumnGameModeBase();

    virtual void BeginPlay() override;

    EGameState GetCurrentGameState();
    void PlayerReachedEnd();


private:
    void DisplayCountdown();
    void StartGame();

};
