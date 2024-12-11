// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Collectables/Collectable.h"
#include "Kismet/GameplayStatics.h"
#include "HUD/FPSHUD.h"
#include "GUI/FPSUserWidget.h"
#include "Coin.generated.h"

/**
 * 
 */
UCLASS()
class FPSPROJECT_API ACoin : public ACollectable
{
	GENERATED_BODY()
public:	
	// Sets default values for this actor's properties
	ACoin();

public:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void OnCollect() override;

	UPROPERTY(VisibleDefaultsOnly)
	UStaticMeshComponent* CoinMeshComponent;

	UPROPERTY(EditAnywhere)
	int Points = 1;
	//UPROPERTY(EditAnywhere)
	//float RotationRate = 100;
	//UPROPERTY(EditAnywhere)
	//float OnCollectRotationRate = 1500;

	FTimerHandle DeathTimerHandle;
	void DeathTimerComplete();

	FVector GetRandomLocationInRange();
};
