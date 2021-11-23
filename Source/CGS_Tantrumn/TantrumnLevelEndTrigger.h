// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "TantrumnLevelEndTrigger.generated.h"

UCLASS()
class CGS_TANTRUMN_API ATantrumnLevelEndTrigger : public ATriggerVolume
{
    GENERATED_BODY()

private:
    UFUNCTION()
    void OnOverlapBegin(class AActor* overlapped_actor, class AActor* other_actor);

    class ATantrumnGameModeBase* game_mode_ref_;

public:
    ATantrumnLevelEndTrigger();

protected:
    virtual void BeginPlay() override;

};
