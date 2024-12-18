// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Collectables/Collectable.h"
#include "Kismet/GameplayStatics.h"
#include "HUD/FPSHUD.h"
#include "GUI/FPSUserWidget.h"
#include "Components/StaticMeshComponent.h"
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
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void OnCollect() override;

	UPROPERTY(VisibleDefaultsOnly)
	UStaticMeshComponent* CoinMeshComponent;

	UPROPERTY(EditAnywhere)
	int Points = 1;
	
	UPROPERTY(EditAnywhere)
	bool IsHostage = false;

	// This allows me to set the reference in the details pane in the blueprint
	UPROPERTY(EditAnywhere)
	UMaterialInterface* HostageMaterial;

	UPROPERTY(EditAnywhere)
    UMaterialInterface* DefaultMaterial;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* ColouredRingRef;

	
	FTimerHandle DeathTimerHandle;

	UFUNCTION()
	void DeathTimerComplete();

	UFUNCTION()
	FVector GetRandomLocationInRange();

	UFUNCTION()
	void SwapTextures();
};
