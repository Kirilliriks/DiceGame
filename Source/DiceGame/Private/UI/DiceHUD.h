#pragma once

#include "CoreMinimal.h"
#include "HudWidget.h"
#include "GameFramework/HUD.h"
#include "DiceHUD.generated.h"

/**
 * 
 */
UCLASS()
class ADiceHUD : public AHUD
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;
	void SetText(const FText& Text);

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UHudWidget> WidgetClass;

	UHudWidget* Widget;
};
