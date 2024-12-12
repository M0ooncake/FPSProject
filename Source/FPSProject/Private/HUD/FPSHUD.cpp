// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/FPSHUD.h"

#include "Kismet/GameplayStatics.h"


void AFPSHUD::BeginPlay()
{
	Super::BeginPlay();
	ShowGameMenu(startingGameWidget);
	ShowSettingsMenu();  // Uncomment to show menu on luanch
}

void AFPSHUD::DrawHUD()
{
	Super::DrawHUD();

	if (!CrosshairTexture) return;
    
    	// 1. Calculate the center point on the screen
    	FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);
    
    	// 2. Set the crosshair pivot to the center
    	float CrosshairHalfWidth = (CrosshairTexture->GetSurfaceWidth() * 0.5f);
    	float CrosshairHalfHeight = (CrosshairTexture->GetSurfaceHeight() * 0.5f);
    	FVector2D CrosshairDrawPos(Center.X - CrosshairHalfWidth, Center.Y - CrosshairHalfHeight);
		
    	// 3. Draw the crosshair
    	FCanvasTileItem TileItem(CrosshairDrawPos, CrosshairTexture->GetResource(), FLinearColor::White);
    	TileItem.BlendMode = SE_BLEND_Translucent;
    	Canvas->DrawItem(TileItem);
    	
}


void AFPSHUD::ShowSettingsMenu()
{	
	if(GEngine && GEngine->GameViewport)
	{
		
		SettingsWIdget = SNew(SSettingsWIdget).OwningHUD(this).FPSGameMode(Cast<AFPSProjectGameModeBase>(UGameplayStatics::GetGameMode(this)));

		
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(
			settingsWidgetContainer, SWeakWidget).PossiblyNullContent(SettingsWIdget.ToSharedRef()) );
	}

	if (PlayerOwner)
	{
		PlayerOwner->bShowMouseCursor = true;
		PlayerOwner->SetInputMode(FInputModeUIOnly());
	}
}

void AFPSHUD::RemoveSettingsMenu()
{
	if(GEngine && GEngine->GameViewport && settingsWidgetContainer.IsValid())
	{
		GEngine->GameViewport->RemoveViewportWidgetContent(settingsWidgetContainer.ToSharedRef());
	}

	if (PlayerOwner)
	{
		PlayerOwner->bShowMouseCursor = false;
		PlayerOwner->SetInputMode(FInputModeGameOnly());
	}
}

void AFPSHUD::ShowGameOver()
{
	if(GEngine && GEngine->GameViewport)
	{
		GameOverWidget = SNew(SGameOverWidget).OwningHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(
			GameOverWidgetContainer, SWeakWidget).PossiblyNullContent(GameOverWidget.ToSharedRef()));
	}
	GameOverWidget->SetScoreText(gameWidgetContainer->GetScoreText()); // This was being called before the reference was initialized

	if (PlayerOwner)
	{
		PlayerOwner->bShowMouseCursor = true;
		PlayerOwner->SetInputMode(FInputModeUIOnly());
	}
}

void AFPSHUD::RemoveGameOver()
{
	if(GEngine && GEngine->GameViewport && GameOverWidgetContainer.IsValid())
	{
		GEngine->GameViewport->RemoveViewportWidgetContent(GameOverWidgetContainer.ToSharedRef());
	}

	if (PlayerOwner)
	{
		PlayerOwner->bShowMouseCursor = false;
		PlayerOwner->SetInputMode(FInputModeGameOnly());
	}
}

void AFPSHUD::ShowGameMenu(TSubclassOf<UFPSUserWidget> newGameWidget)
{
	if (gameWidgetContainer)
	{
		gameWidgetContainer->RemoveFromParent();
		gameWidgetContainer = nullptr;
	}
	if (newGameWidget)
	{
		gameWidgetContainer = CreateWidget<UFPSUserWidget>(GetWorld(), newGameWidget);
		gameWidgetContainer->AddToViewport();
	}
}
