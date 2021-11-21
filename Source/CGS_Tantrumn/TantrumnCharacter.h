// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TantrumnCharacter.generated.h"

UCLASS()
class CGS_TANTRUMN_API ATantrumnCharacter : public ACharacter
{
    GENERATED_BODY()

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Throwable");
    UAnimMontage* throw_montage_;

public:
    // Sets default values for this character's properties
    ATantrumnCharacter();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    UFUNCTION(BlueprintCallable, Category = "Throwable")
    virtual void PlayThrowMontage();

};
