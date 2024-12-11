// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyAIController.h"

#include "BehaviorTree/BlackboardComponent.h"


AEnemyAIController::AEnemyAIController()
{
	PrimaryActorTick.bCanEverTick = true;

	if(!PawnSensingComponent)
	{
		PawnSensingComponent = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComponent"));
	}
}

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();

	RunBehaviorTree(StartingBehaviorTree);

	if(PawnSensingComponent)
	{
		PawnSensingComponent->OnSeePawn.AddDynamic(this, &AEnemyAIController::OnSeePawn);
	}
}

void AEnemyAIController::OnSeePawn(APawn* PlayerPawn)
{
	AFPSCharacter* Player = Cast<AFPSCharacter>(PlayerPawn);
	if (!Player) return;
	SetCanSeePlayer(true, Player);
}

void AEnemyAIController::SetCanSeePlayer(bool SeePlayer, UObject* Player)
{
	UBlackboardComponent* BlackboardComponent = GetBlackboardComponent();
	BlackboardComponent->SetValueAsBool(FName("Can See Player"), SeePlayer);

	if(SeePlayer)
	{
		BlackboardComponent->SetValueAsObject(FName("Player Target"), Player);
	}
}

void AEnemyAIController::RunTriggerableTimer()
{
	
	GetWorld()->GetTimerManager().ClearTimer(*ReTriggerableTimerHandle);
	FunctionDelegate.BindUFunction(this, FName("SetCanSeePlayer"), false , GetPawn());
	GetWorld()->GetTimerManager().SetTimer(*ReTriggerableTimerHandle, FunctionDelegate,
		PawnSensingComponent->SensingInterval * 2.0f, false);
}
