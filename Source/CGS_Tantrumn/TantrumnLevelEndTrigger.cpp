// Fill out your copyright notice in the Description page of Project Settings.


#include "TantrumnLevelEndTrigger.h"

#include "TantrumnCharacter.h"
#include "TantrumnGameModeBase.h"

ATantrumnLevelEndTrigger::ATantrumnLevelEndTrigger()
{
    OnActorBeginOverlap.AddDynamic(this, &ATantrumnLevelEndTrigger::OnOverlapBegin);
}

void ATantrumnLevelEndTrigger::BeginPlay()
{
    Super::BeginPlay();
    game_mode_ref_ = GetWorld()->GetAuthGameMode<ATantrumnGameModeBase>();
}

void ATantrumnLevelEndTrigger::OnOverlapBegin(AActor* overlapped_actor, AActor* other_actor)
{
    if (other_actor == Cast<ATantrumnCharacter>(other_actor))
    {
        game_mode_ref_->PlayerReachedEnd();
    }
}
