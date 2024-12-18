// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FPSProject/FPSProjectGameModeBase.h"
#include "FPSGameModeCountDown.h"
#include "HUD/FPSHUD.h"
#include "Widgets/SCompoundWidget.h"


/**
 * 
 */
class FPSPROJECT_API SSettingsWIdget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSettingsWIdget)
	{}
		SLATE_ARGUMENT(TWeakObjectPtr<class AFPSHUD>, OwningHUD)
		SLATE_ARGUMENT(TWeakObjectPtr<class AFPSProjectGameModeBase>, FPSGameMode)
		SLATE_ARGUMENT(TWeakObjectPtr<class AFPSGameModeCountDown>, FPSGameModeCountDown)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	TWeakObjectPtr<class AFPSHUD> OwningHUD;
	TWeakObjectPtr<class AFPSProjectGameModeBase> FPSGameMode;
	TWeakObjectPtr<class AFPSGameModeCountDown> FPSGameModeCountDown;
	
	FText  GameModeText = FText::FromString("Game Mode: ");	// Why does the system think its a const: Got finally
	TSharedPtr<STextBlock> GameModeTextBlock;	// Allows for setting text dynamically for the button
	
	bool ToggleGameState = false;
	FReply OnSoundClicked();
	FReply OnResumeClicked() const;
	FReply OnQuitClickeded() const;
	
};
