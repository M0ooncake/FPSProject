// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSProjectGameModeBase.h"



void AFPSProjectGameModeBase::StartPlay()
{
	Super::StartPlay();

	check(GEngine != nullptr);
	

	// we want to display a debug message for 5 seconds
	// The -1 "Key" value argument prevents the message from being updated or refreshed.
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Silver, TEXT("Hello you son of a &**&#. Get to work"));
	AFPSHUD* HUD = UGameplayStatics::GetPlayerController(this, 0)->GetHUD<AFPSHUD>();
	
}

void AFPSProjectGameModeBase::Timer()
{
	// Decrease the remaining time
	RemainingTime--;

	// Update the timer text
	UpdateTimerText();

	// Check if time is up
	if (RemainingTime <= 0)
	{
		// Stop the timer
		GetWorld()->GetTimerManager().ClearTimer(TimerHandle);

		// End the game... But how? Something along the lines of popping a menu on to screen.
		AFPSHUD* HUD = UGameplayStatics::GetPlayerController(this, 0)->GetHUD<AFPSHUD>();
		if(!HUD) return; // If HUD has not been gotten, stop executing code to avoid crashing
		HUD->ShowGameOver();
	}
}

void AFPSProjectGameModeBase::UpdateTimerText()
{
	AFPSHUD* HUD = UGameplayStatics::GetPlayerController(this, 0)->GetHUD<AFPSHUD>();
	if(!HUD) return; // If HUD has not been gotten, stop executing code to avoid crashing
	HUD->gameWidgetContainer->TimerText->SetText(FText::FromString(FString::Printf(TEXT("Time Left: %d"), RemainingTime)));
	
}

void AFPSProjectGameModeBase::StartTimer()
{

	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AFPSProjectGameModeBase::Timer, 1.0f, true);
}
