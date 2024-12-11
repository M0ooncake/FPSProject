// Fill out your copyright notice in the Description page of Project Settings.


#include "Collectables/Coin.h"

ACoin::ACoin()
{
	PrimaryActorTick.bCanEverTick = true;
	
	if(!CoinMeshComponent)
	{
		CoinMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CoinMesh"));
		CoinMeshComponent->SetupAttachment(CollisionComponent);
	}


}

void ACoin::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACoin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//AddActorLocalRotation(FRotator(0,RotationRate * DeltaTime, 0));
	
}

void ACoin::OnCollect()
{
	
	
	Super::OnCollect();
	UE_LOG(LogTemp, Warning, TEXT("COIN: OnCollect triggered"));
	
	AFPSHUD* HUD = UGameplayStatics::GetPlayerController(this, 0)->GetHUD<AFPSHUD>();
	if(!HUD) return; // If HUD has not been gotten, stop executing code to avoid crashing	
	
	HUD->gameWidgetContainer->SetScoreText(Points); // pass that percentage to the UI bar to be displayed
	
	// Generate a new random location within the specified range, This will need polishing
	FVector NewLocation = GetRandomLocationInRange();

	// Set the actor's location to the new location
	SetActorLocation(NewLocation);
	
	//RotationRate = OnCollectRotationRate;
	// C++ Version of a delay node
	//GetWorldTimerManager().SetTimer(DeathTimerHandle, this, &ACoin::DeathTimerComplete, 0.1, false);
	
}

void ACoin::DeathTimerComplete()
{
	AFPSHUD* HUD = UGameplayStatics::GetPlayerController(this, 0)->GetHUD<AFPSHUD>();
	if(!HUD) return; // If HUD has not be gotten, stop executing code to avoid crashing	
	
	HUD->gameWidgetContainer->SetScoreText(Points); // pass that percentage to the UI bar to be displayed
	
	Destroy();
}

FVector ACoin::GetRandomLocationInRange()
{
	// Define the ranges for X, Y, and Z
	float RandomX = FMath::RandRange(-800.0f, 400.0f); // Random X value between -800 and 450
	float RandomY = FMath::RandRange(-240.0f, -770.0f); // Y range remains as defined earlier
	float RandomZ = FMath::RandRange(70.0f, 600.0f); // Random Z value between 70 and 600

	// Create and return the new location vector
	return FVector(RandomX, RandomY, RandomZ);
}

