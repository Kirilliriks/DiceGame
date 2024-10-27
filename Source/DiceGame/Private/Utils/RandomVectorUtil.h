// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class FRandomVectorUtil
{
public:
	static FVector GetRandomVector(const double Min, const double Max)
	{
		return {
			FMath::FRandRange(Min, Max),
			FMath::FRandRange(Min, Max),
			FMath::FRandRange(Min, Max)
		};
	}
};
