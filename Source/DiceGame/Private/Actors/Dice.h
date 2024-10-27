#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Dice.generated.h"

UCLASS()
class ADice : public AActor
{
	GENERATED_BODY()

public:	
	ADice();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(const float DeltaTime) override;
};