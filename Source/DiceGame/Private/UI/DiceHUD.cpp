// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/DiceHUD.h"

void ADiceHUD::BeginPlay()
{
	Super::BeginPlay();

	if (!IsValid(WidgetClass))
	{
		UE_LOG(LogTemp, Error, TEXT("HUD WidgetClass is Invalid"));
		return;
	}

	Widget = Cast<UHudWidget>(CreateWidget(GetWorld(), WidgetClass));
	Widget->AddToViewport();
}

void ADiceHUD::SetText(const FText& Text)
{
	Widget->SetText(Text);
}
