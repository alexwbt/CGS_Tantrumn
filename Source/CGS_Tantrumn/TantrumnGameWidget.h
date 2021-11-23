#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TantrumnGameWidget.generated.h"

class ATantrumnGameModeBase;

UCLASS()
class CGS_TANTRUMN_API UTantrumnGameWidget : public UUserWidget
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintImplementableEvent)
    void StartCountdown(float seconds, ATantrumnGameModeBase* game_mode);

    UFUNCTION(BlueprintImplementableEvent)
    void LevelComplete();

};
