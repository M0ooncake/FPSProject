// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GUI/Slate/SSettingsWIdget.h"
#include "Engine/Canvas.h"
#include "EntitySystem/MovieSceneEntitySystemRunner.h"
#include "GUI/Slate/SGameOverWidget.h"
#include"Widgets/SWeakWidget.h"
#include "GUI/FPSUserWidget.h"
#include "FPSHUD.generated.h"

/**
 * 
 */
UCLASS()
class FPSPROJECT_API AFPSHUD : public AHUD
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	// 1. HUD method of making UI
	virtual void DrawHUD() override;

	// 2. Slates method of making UI
	TSharedPtr<class SSettingsWIdget> SettingsWIdget;
	TSharedPtr<class SWidget> settingsWidgetContainer;
	TSharedPtr<class SGameOverWidget> GameOverWidget;
	TSharedPtr<class SWidget> GameOverWidgetContainer;
	
	void ShowSettingsMenu();
	void RemoveSettingsMenu();

	void ShowGameOver();
	void RemoveGameOver();
	// 3. UMG method of making UI
	UPROPERTY(EditAnywhere)
	TSubclassOf<UFPSUserWidget> startingGameWidget;

	
	UPROPERTY()
	UFPSUserWidget* gameWidgetContainer;
	
	void ShowGameMenu(TSubclassOf<UFPSUserWidget> newGameWidget);
	
protected:
	UPROPERTY(EditDefaultsOnly)
	UTexture2D* CrosshairTexture;
};

/*
 * Different forms of pointers
 * unique_ptr - cannot be copied, shared and used by something else. it is dedicated to the class and nothing else
 *		Upon deletion of the class it will be destroyed with it.
 *
 *	shared_ptr - Two classes can have access to the pointer at the same time. Both classes would need to be deleted
 *		in order for the pointer to self destruct.
 *
 *	weak_ptr - Strong pointers are any that use an *. Like normal ones, it will never die on its own, you must delete
 *		it. However, this is a weak pointer. It lets the system know it might still be there, or it might not.
 *		Don't rely on it being initialized.
 * 
 */
