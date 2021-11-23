// Fill out your copyright notice in the Description page of Project Settings.


#include "TantrumnGameModeBase.h"

#include "TantrumnGameWidget.h"

#include "Kismet/GameplayStatics.h"

ATantrumnGameModeBase::ATantrumnGameModeBase()
{

}

void ATantrumnGameModeBase::BeginPlay()
{
    Super::BeginPlay();

    current_game_state_ = EGameState::Waiting;

    GetWorld()->GetTimerManager().SetTimer(timer_handle_, this, &ATantrumnGameModeBase::StartGame, game_countdown_seconds_);
    DisplayCountdown();

    FInputModeGameOnly input_mode;
    PC->SetInputMode(input_mode);
    PC->SetShowMouseCursor(false);
}

EGameState ATantrumnGameModeBase::GetCurrentGameState()
{
    return current_game_state_;
}

void ATantrumnGameModeBase::PlayerReachedEnd()
{
    current_game_state_ = EGameState::GameOver;

    game_widget_->LevelComplete();
    FInputModeUIOnly input_mode;
    PC->SetInputMode(input_mode);
    PC->SetShowMouseCursor(true);
}

void ATantrumnGameModeBase::DisplayCountdown()
{
    if (!game_widget_class_)
        return;

    PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);

    game_widget_ = CreateWidget<UTantrumnGameWidget>(PC, game_widget_class_);
    game_widget_->AddToViewport();
    game_widget_->StartCountdown(game_countdown_seconds_, this);
}

void ATantrumnGameModeBase::StartGame()
{
    current_game_state_ = EGameState::Playing;
}

