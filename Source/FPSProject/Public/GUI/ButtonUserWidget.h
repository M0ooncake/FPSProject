// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "ButtonUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class FPSPROJECT_API UButtonUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	int num;
	UPROPERTY(meta = (BindWidget))
	UButton* Button;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ButtonText;

	

	UFUNCTION()
	void SetText(int value);

	UFUNCTION()
	virtual void OnButtonClick();
};
