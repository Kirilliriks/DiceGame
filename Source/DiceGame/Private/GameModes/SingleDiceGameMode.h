#pragma once

#include "CoreMinimal.h"
#include "Actors/Dice.h"
#include "GameFramework/GameModeBase.h"
#include "SingleDiceGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ASingleDiceGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<ADice> DiceBlueprint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(UIMin = 1))
	int DiceAmount = 1;

private:
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
	void SpawnDices(UWorld* World);
	void SpawnDice(UWorld* World, const FVector& Location);
};
