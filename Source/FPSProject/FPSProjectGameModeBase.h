// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Logging/StructuredLog.h"
#include "Kismet/GameplayStatics.h"
#include "GUI/FPSUserWidget.h"
#include "HUD/FPSHUD.h"
#include "FPSProjectGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class FPSPROJECT_API AFPSProjectGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:                      
	virtual void StartPlay() override;
	
	
	//AFPSHUD* HUD; // Why the ever loving fk does this not work????? i dont understand. 
	
	FTimerHandle TimerHandle;
	int RemainingTime = 15;
	
	UFUNCTION()
	void Timer();
	
	UFUNCTION()
	void UpdateTimerText();
	
	void StartTimer();
};
