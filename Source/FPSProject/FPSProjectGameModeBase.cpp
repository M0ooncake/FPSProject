// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSProjectGameModeBase.h"

void AFPSProjectGameModeBase::StartPlay()
{
	Super::StartPlay();

	check(GEngine != nullptr);

	// we want to display a debug message for 5 seconds
	// The -1 "Key" value argument prevents the message from being updated or refreshed.
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Silver, TEXT("Hello you son of a &**&#. Get to work"));
	/*
	 *UE_LOG(LogTemp, Warning, TEXT("Hello World"));
      
      	UE_LOGFMT(LogTemp, Warning, "Hello World");
      	* int test = 10;
          	bool boolTest = true;
          	UE_LOG(LogTemp, Warning, TEXT("Test: %i, TestBool: %d"), test, boolTest);
	 */

	
}
