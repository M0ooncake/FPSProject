// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/Slate/SSettingsWIdget.h"


#include "AITestsCommon.h"
#include "SlateOptMacros.h"
#include "FPSProject/FPSProjectGameModeBase.h"
#include "Kismet/GameplayStatics.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SSettingsWIdget::Construct(const FArguments& InArgs)
{
	bCanSupportFocus = true;
	OwningHUD = InArgs._OwningHUD;
	FPSGameMode = InArgs._FPSGameMode;
	
	const FMargin ContentPadding = FMargin(500.0f, 300.0f);
    const FMargin ButtonPadding = FMargin(10.0f);
	
    const FText  TitleText = FText::FromString("Main Menu");
    const FText  ResumeText = FText::FromString("Begin Game");
    GameModeText = FText::FromString("Game Mode: ");
    const FText  QuitText = FText::FromString("Quit");
	
    FSlateFontInfo TitleTextStyle = FCoreStyle::Get().GetFontStyle("EmbassedText");
    TitleTextStyle.Size = 60.0f;
	
    FSlateFontInfo ButtonTextStyle = TitleTextStyle;
    TitleTextStyle.Size = 40.0f;
	ChildSlot
	[
		SNew(SOverlay)
        +SOverlay::Slot()
        .HAlign(HAlign_Fill)
        .VAlign(VAlign_Fill)
        [
        	SNew(SImage)
        	.ColorAndOpacity(FColor::Black)
        ]
        +SOverlay::Slot()
        .HAlign(HAlign_Fill)
        .VAlign(VAlign_Fill)
        .Padding(ContentPadding)
        [
        	// Title Text
        	SNew(SVerticalBox)
        	+ SVerticalBox::Slot()
        	[
        		SNew(STextBlock)
        		.Font(TitleTextStyle)
        		.Text(TitleText)
        		.Justification(ETextJustify::Center)
        	]
        
        	// Resume Button
        	+ SVerticalBox::Slot()
        	.Padding(ButtonPadding)
        	[
        		SNew(SButton)
        		.OnClicked(this, &SSettingsWIdget::OnResumeClicked)
        		[
        			SNew(STextBlock)
        			.Font(ButtonTextStyle)
        			.Text(ResumeText)
        			.Justification(ETextJustify::Center)
        		]
        	]
        	// GameMode Button
        	+ SVerticalBox::Slot()
        	.Padding(ButtonPadding)
	        
        	[
        		SNew(SButton)
        		.OnClicked(this, &SSettingsWIdget::OnSoundClicked)
        		[
        			SAssignNew(GameModeTextBlock,STextBlock)
        			.Font(ButtonTextStyle)
        			.Text(GameModeText)
        			.Justification(ETextJustify::Center)
        		]
        	]
        	// Quit Button
        	+ SVerticalBox::Slot()
        	.Padding(ButtonPadding)
        	[
        		SNew(SButton)
        		.OnClicked(this, &SSettingsWIdget::OnQuitClickeded)
        		[
        			SNew(STextBlock)
        			.Font(ButtonTextStyle)
        			.Text(QuitText)
        			.Justification(ETextJustify::Center)
        		]
        	]
        ]
	];
	OnSoundClicked();
}

FReply SSettingsWIdget::OnResumeClicked() const
{
	
	

	
	//if (!FPSGameMode.IsValid()) return FReply::Handled();
	FPSGameMode->StartTimer();
	//OwningHUD->gameWidgetContainer->StartTimer();
	if (OwningHUD.IsValid())
	{
		OwningHUD->RemoveSettingsMenu();
	}
	return FReply::Handled();
}

FReply SSettingsWIdget::OnSoundClicked()	// GameMode Really. Not sound anymore.
{
	ToggleGameState = !ToggleGameState; //	Flip flop between being true and false
	switch (ToggleGameState)
	{
	case true:
		GameModeText = FText::FromString("Game Mode: Countdown");
		GameModeTextBlock->SetText(GameModeText);
		break;
	case false:
		GameModeText = FText::FromString("Game Mode: CountUp");
		GameModeTextBlock->SetText(GameModeText);
	}
	
	return FReply::Handled();
}

FReply SSettingsWIdget::OnQuitClickeded() const
{
	if (OwningHUD.IsValid())
	{
		if (APlayerController* PlayerController = OwningHUD->PlayerOwner)
		{
			PlayerController->ConsoleCommand("quit");
		}
	}
	return FReply::Handled();
}


END_SLATE_FUNCTION_BUILD_OPTIMIZATION
