// Fill out your copyright notice in the Description page of Project Settings.


#include "TantrumnCharacter.h"

// Sets default values
ATantrumnCharacter::ATantrumnCharacter()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATantrumnCharacter::BeginPlay()
{
    Super::BeginPlay();

}

// Called every frame
void ATantrumnCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    //auto* anim_instance = GetMesh()->GetAnimInstance();
    //if (!anim_instance)
    //    return;

    //const auto* current_montage = anim_instance->GetCurrentActiveMontage();
    //if (!current_montage)
    //    return;

    //float play_rate = anim_instance->GetCurveValue("ThrowCurve");
    //anim_instance->Montage_SetPlayRate(current_montage, play_rate);


    //UE_LOG(LogTemp, Warning, TEXT("play rate %f"), play_rate);
}

// Called to bind functionality to input
void ATantrumnCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void ATantrumnCharacter::PlayThrowMontage()
{
    if (!throw_montage_)
        return;

    PlayAnimMontage(throw_montage_);
}
