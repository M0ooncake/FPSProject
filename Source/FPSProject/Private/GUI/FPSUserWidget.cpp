// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/FPSUserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "HUD/FPSHUD.h"


void UFPSUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	SetHealthBar(1.0f);
	SetScoreText(0);
	// Initialize timer
	RemainingTime = 15; // 15 second countdown
	UpdateTimerText();
	// Start the countdown
	
	if (ButtonWidgetPrefab)
	{
		// Adding 4 buttons into the container. Currently None of them do anything
		for(int i = 0; i < 4; i++)
		{
			UUserWidget* widget = CreateWidget(this, ButtonWidgetPrefab);
			ButtonContainer->AddChildToVerticalBox(widget);
			UButtonUserWidget* button = Cast<UButtonUserWidget>(widget); // basically like getComponent in unity
			button->SetText(i);
			
		}
	}
	
}

void UFPSUserWidget::Timers()	
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

void UFPSUserWidget::UpdateTimerText()
{
	if (!TimerText) return;
	
	TimerText->SetText(FText::FromString(FString::Printf(TEXT("Time Left: %d"), RemainingTime)));
}
void UFPSUserWidget::StartTimer()
{
	//GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UFPSUserWidget::Timer, 1.0f, true);
}
void UFPSUserWidget::SetHealthBar(float percentage)
{
	if (!HealthBar) return;
	
	HealthBar->SetPercent(percentage);
}

void UFPSUserWidget::SetScoreText(int amount)
{
	if (!ScoreText) return;
	UIScore += amount;
	ScoreText->SetText(FText::FromString("Score: " + FString::FromInt(UIScore)));
}

int UFPSUserWidget::GetScoreText()
{

	return UIScore;
}

