#include "Actors/Dice.h"

#include "MathUtil.h"
#include "Utils/RandomVectorUtil.h"

ADice::ADice()
{
	PrimaryActorTick.bCanEverTick = true;
}

int ADice::GetDownSideNumber()
{
	if (!Mesh->GetComponentVelocity().IsZero())
	{
		return 0;
	}

	// Faster than Dot Product I Guess
	// const int UpSide = FMath::RoundToInt(Mesh->GetUpVector().Z);
	// const int ForwardSide = FMath::RoundToInt(Mesh->GetForwardVector().Z);
	// const int RightSide = FMath::RoundToInt(Mesh->GetRightVector().Z);

	const FVector UpVector = FVector::UpVector;
	const float UpSide = Mesh->GetUpVector().Dot(UpVector);
	const float ForwardSide = Mesh->GetForwardVector().Dot(UpVector);
	const float RightSide = Mesh->GetRightVector().Dot(UpVector);

	if (UpSide == 1)
	{
		return 4;
	}

	if (UpSide == -1)
	{
		return 3;
	}

	if (ForwardSide == 1)
	{
		return 2;
	}

	if (ForwardSide == -1)
	{
		return 5;
	}
	
	if (RightSide == 1)
	{
		return 6;
	}

	if (RightSide == -1)
	{
		return 1;
	}

	return -1;
}

void ADice::BeginPlay()
{
	Super::BeginPlay();
	Mesh = FindComponentByClass<UStaticMeshComponent>();
}

void ADice::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADice::RandomThrow()
{
	if (!IsValid(Mesh))
	{
		UE_LOG(LogTemp, Error, TEXT("Mesh is Invalid"));
		return;
	}

	Mesh->SetPhysicsLinearVelocity(FVector(0, 0, 1));

	const FVector Impulse = FRandomVectorUtil::GetRandomVector(-1, 1);
	Mesh->AddImpulse(Impulse * FMath::FRandRange(50.0, 500.0), NAME_None, true);

	const FVector Angular = FRandomVectorUtil::GetRandomVector(-1, 1);
	Mesh->AddAngularImpulseInDegrees(Angular * FMath::FRandRange(50.0, 500.0), NAME_None, true);
}
