#include "GameModes/SingleDiceGameMode.h"
#include "Actors/Dice.h"

void ASingleDiceGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

	UWorld* World = GetWorld();
	World->OnWorldBeginPlay.AddWeakLambda
	(
		World, [this, World]
		{
			SpawnDices(World);
		}
	);
}

void ASingleDiceGameMode::SpawnDices(UWorld* World)
{
	const AActor* Player = World->GetFirstPlayerController();

	FVector PlayerLocation = Player->GetActorLocation();
	PlayerLocation += Player->GetActorForwardVector() * 2;

	for (int i = 0; i < DiceAmount; i++)
	{
		SpawnDice(World, PlayerLocation);
	}
}

void ASingleDiceGameMode::SpawnDice(UWorld* World, const FVector& Location)
{
	if (!IsValid(DiceBlueprint))
	{
		UE_LOG(LogTemp, Error, TEXT("Dice Blueprint in SingleDiceGameMode is Invalid"));
		return;
	}

	ADice* Dice = World->SpawnActor<ADice>(DiceBlueprint);
	Dice->SetActorLocation(Location);
}
