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

	ASingleDiceGameMode();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<ADice> DiceBlueprint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(UIMin = 1))
	int DiceAmount = 1;

private:

	TArray<TObjectPtr<ADice>> Dices;

	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
	virtual void Tick(float DeltaSeconds) override;
	
	void SpawnDices(UWorld* World);
	void SpawnDice(UWorld* World, const FVector& Location);
};
