// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "GUI/ButtonUserWidget.h"
#include "TimerManager.h"

#include "FPSUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class FPSPROJECT_API UFPSUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	FTimerHandle TimerHandle;
	int RemainingTime;
	
	UPROPERTY(meta = (BindWidget))
	UProgressBar* HealthBar;
	
	UPROPERTY(meta = (BindWidget))
    UTextBlock* ScoreText;
	
	UPROPERTY(meta = (BindWidget))
	UVerticalBox* ButtonContainer;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TimerText;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UButtonUserWidget> ButtonWidgetPrefab;

	UFUNCTION()
	void SetHealthBar(float percentage);

	UFUNCTION()
	void SetScoreText(int amount);
	UFUNCTION()
	int GetScoreText();

	UFUNCTION()
	virtual void NativeConstruct() override;

	UFUNCTION()
	void Timers();

	UFUNCTION()
	void UpdateTimerText();
	UFUNCTION()
	void StartTimer();

private:
	int UIScore;
};
