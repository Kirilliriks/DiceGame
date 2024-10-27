#include "GameModes/SingleDiceGameMode.h"
#include "Actors/Dice.h"

ASingleDiceGameMode::ASingleDiceGameMode()
{
	PrimaryActorTick.bStartWithTickEnabled = true;
	PrimaryActorTick.bCanEverTick = true;
}

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

void ASingleDiceGameMode::Tick(const float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	for (auto It = Dices.CreateIterator(); It; ++It)
	{
		ADice* Dice = It->Get();
		if (!IsValid(Dice))
		{
			It.RemoveCurrent();
			continue;
		}

		const int DownSideNumber = Dice->GetDownSideNumber();
		UE_LOG(LogTemp, Warning, TEXT("Side %d"), DownSideNumber);
		
		if (DownSideNumber <= 0)
		{
			continue;
		}

		It.RemoveCurrent();
	}
}

void ASingleDiceGameMode::SpawnDices(UWorld* World)
{
	if (!IsValid(DiceBlueprint))
	{
		UE_LOG(LogTemp, Error, TEXT("Dice Blueprint in SingleDiceGameMode is Invalid"));
		return;
	}
	
	const AActor* Player = World->GetFirstPlayerController();
	FVector PlayerLocation = Player->GetActorLocation();
	PlayerLocation += Player->GetActorForwardVector() * 200;

	for (int i = 0; i < DiceAmount; i++)
	{
		SpawnDice(World, PlayerLocation);
	}
}

void ASingleDiceGameMode::SpawnDice(UWorld* World, const FVector& Location)
{
	ADice* Dice = World->SpawnActor<ADice>(DiceBlueprint, Location, FRotator(0, 0, 0));
	Dice->RandomThrow();

	Dices.Add(Dice);
}
