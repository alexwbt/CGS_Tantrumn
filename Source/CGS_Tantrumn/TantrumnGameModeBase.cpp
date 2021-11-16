// Fill out your copyright notice in the Description page of Project Settings.


#include "TantrumnGameModeBase.h"

ATantrumnGameModeBase::ATantrumnGameModeBase()
{

}

void ATantrumnGameModeBase::BeginPlay()
{
    Super::BeginPlay();

    current_game_state_ = EGameState::Waiting;

    GetWorld()->GetTimerManager().SetTimer(timer_handle_, this, &ATantrumnGameModeBase::StartGame, game_countdown_duration_);
    DisplayCountdown();
}

EGameState ATantrumnGameModeBase::GetCurrentGameState()
{
    return current_game_state_;
}

void ATantrumnGameModeBase::PlayerReachedEnd()
{
    current_game_state_ = EGameState::GameOver;
}

void ATantrumnGameModeBase::DisplayCountdown()
{

}

void ATantrumnGameModeBase::StartGame()
{
    current_game_state_ = EGameState::Playing;
}

