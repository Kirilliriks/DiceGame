#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "HudWidget.generated.h"

/**
 * 
 */
UCLASS()
class UHudWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	void SetText(const FText& Text);

private:

	virtual void NativeConstruct() override;

	UPROPERTY(meta=(BindWidget))
	UTextBlock* Label;
};
