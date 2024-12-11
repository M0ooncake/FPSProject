// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "HUD/FPSHUD.h"
#include "SlateOptMacros.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class FPSPROJECT_API SGameOverWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SGameOverWidget)
	{}
		SLATE_ARGUMENT(TWeakObjectPtr<class AFPSHUD>, OwningHUD)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	TWeakObjectPtr<class AFPSHUD> OwningHUD;
	FText  ScoreText = FText::FromString("Your score is: ");

	TSharedPtr<STextBlock> TextBlock;
	
	UFUNCTION()
	FReply OnRestartClicked() const;
	UFUNCTION()
	FReply OnQuitClickeded() const;
	UFUNCTION()
	void SetScoreText(int amount);
	
};
