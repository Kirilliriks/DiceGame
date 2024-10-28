#include "UI/HudWidget.h"

void UHudWidget::SetText(const FText& Text)
{
	if (!IsValid(Label))
	{
		UE_LOG(LogTemp, Error, TEXT("Label is Invalid"));
		return;
	}
	
	Label->SetText(Text);
}

void UHudWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (!IsValid(Label))
	{
		UE_LOG(LogTemp, Error, TEXT("Label is Invalid"));
		return;
	}

	Label->SetText(FText::FromString("Easter Egg"));
}
