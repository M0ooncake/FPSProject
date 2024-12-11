// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/Slate/SGameOverWidget.h"
#include "Kismet/GameplayStatics.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SGameOverWidget::Construct(const FArguments& InArgs)
{
	bCanSupportFocus = true;
	OwningHUD = InArgs._OwningHUD;

	const FMargin ContentPadding = FMargin(500.0f, 300.0f);
	const FMargin ButtonPadding = FMargin(10.0f);

	const FText  TitleText = FText::FromString("Times Up!");
	ScoreText = FText::FromString("Your score is: ");
	const FText  RestartText = FText::FromString("Restart Game");
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
			.ColorAndOpacity(FColor::Blue)
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
			// Score Text
			+ SVerticalBox::Slot()
			.Padding(ButtonPadding)
	        
			[
				SAssignNew(TextBlock,STextBlock)
				.Font(ButtonTextStyle)
				.Text(ScoreText)
				.Justification(ETextJustify::Center)
			
			]
			// Resume Button
			+ SVerticalBox::Slot()
			.Padding(ButtonPadding)
			[
				SNew(SButton)
				.OnClicked(this, &SGameOverWidget::OnRestartClicked)
				[
					SNew(STextBlock)
					.Font(ButtonTextStyle)
					.Text(RestartText)
					.Justification(ETextJustify::Center)
				]
			]
			
			// Quit Button
			+ SVerticalBox::Slot()
			.Padding(ButtonPadding)
			[
				SNew(SButton)
				.OnClicked(this, &SGameOverWidget::OnQuitClickeded)
				[
					SNew(STextBlock)
					.Font(ButtonTextStyle)
					.Text(QuitText)
					.Justification(ETextJustify::Center)
				]
			]
		]
	];
}

FReply SGameOverWidget::OnRestartClicked() const

{
	if (OwningHUD.IsValid())
	{
		OwningHUD->RemoveGameOver();
	}
	if (GEngine && GEngine->GameViewport)
	{
		UWorld* World = GEngine->GameViewport->GetWorld();
		if (World)
		{
			// Get the current level name
			FString LevelName = UGameplayStatics::GetCurrentLevelName(World, true);

			// Reload the level
			UGameplayStatics::OpenLevel(World, FName(*LevelName));
		}
	}
	return FReply::Handled();
}

FReply SGameOverWidget::OnQuitClickeded() const
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

void SGameOverWidget::SetScoreText(int amount)
{
	ScoreText = (FText::FromString("Score: " + FString::FromInt(amount)));
	TextBlock->SetText(ScoreText);
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
