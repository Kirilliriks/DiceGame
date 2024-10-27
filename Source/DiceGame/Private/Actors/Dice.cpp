#include "Actors/Dice.h"

ADice::ADice()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ADice::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADice::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);
}

