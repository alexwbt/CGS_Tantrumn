// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ThrowableActor.generated.h"

class UProjectileMovementComponent;

UCLASS()
class CGS_TANTRUMN_API AThrowableActor : public AActor
{
    GENERATED_BODY()

private:
    UStaticMeshComponent* mesh_;
    UProjectileMovementComponent* projectile_movement_;

public:
    AThrowableActor();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

};
