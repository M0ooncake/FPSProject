// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUD/FPSHUD.h"
#include "GameFramework/GameModeBase.h"
#include "FPSGameModeCountDown.generated.h"

/**
 * 
 */
UCLASS()
class FPSPROJECT_API AFPSGameModeCountDown : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void StartPlay() override;
	FTimerHandle TimerHandle;
	int CurrentTime = 0;
	
	UFUNCTION()
	void StopWatch();
	
	UFUNCTION()
	void UpdateTimerText();
	
	void StartStopWatch();

	
};
