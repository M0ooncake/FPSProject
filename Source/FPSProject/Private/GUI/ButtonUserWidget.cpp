// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/ButtonUserWidget.h"

void UButtonUserWidget::SetText(int value)
{
	if (!Button || !ButtonText) return;

	num = value;
	ButtonText->SetText(FText::FromString("Button: " + FString::FromInt(num)));
	Button->OnClicked.AddDynamic(this, &UButtonUserWidget::OnButtonClick);
}


void UButtonUserWidget::OnButtonClick()
{
	UE_LOG(LogTemp, Warning, TEXT("Button Click: %d"), num);
}
