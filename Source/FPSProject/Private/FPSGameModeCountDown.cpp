// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSGameModeCountDown.h"



void AFPSGameModeCountDown::StartPlay()
{
	Super::StartPlay();
}

void AFPSGameModeCountDown::StopWatch()
{
	// Decrease the remaining time
	CurrentTime++;

	// Update the timer text
	UpdateTimerText();

	// Check if time is up
	if (CurrentTime <= 15)
	{
		// Stop the timer
		GetWorld()->GetTimerManager().ClearTimer(TimerHandle);

		// End the game... But how? Something along the lines of popping a menu on to screen.
		AFPSHUD* HUD = UGameplayStatics::GetPlayerController(this, 0)->GetHUD<AFPSHUD>();
		if(!HUD) return; // If HUD has not been gotten, stop executing code to avoid crashing
		HUD->ShowGameOver();
	}
}

void AFPSGameModeCountDown::UpdateTimerText()
{
	AFPSHUD* HUD = UGameplayStatics::GetPlayerController(this, 0)->GetHUD<AFPSHUD>();
	if(!HUD) return; // If HUD has not been gotten, stop executing code to avoid crashing
	HUD->gameWidgetContainer->TimerText->SetText(FText::FromString(FString::Printf(TEXT("Current Time: %d"), CurrentTime)));
}

void AFPSGameModeCountDown::StartStopWatch()
{
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AFPSGameModeCountDown::StopWatch, 1.0f, true);
}
