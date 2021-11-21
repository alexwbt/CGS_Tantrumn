// Fill out your copyright notice in the Description page of Project Settings.


#include "ThrowableActor.h"

#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AThrowableActor::AThrowableActor()
{
    //PrimaryActorTick.bCanEverTick = true;

    mesh_ = CreateDefaultSubobject<UStaticMeshComponent>("mesh");
    projectile_movement_ = CreateDefaultSubobject<UProjectileMovementComponent>("projectileMomvement");


}

// Called when the game starts or when spawned
void AThrowableActor::BeginPlay()
{
    Super::BeginPlay();

}

// Called every frame
void AThrowableActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

