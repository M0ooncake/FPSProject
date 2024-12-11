// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/BTT_Attack.h"




EBTNodeResult::Type UBTT_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// Method 1:
	//AFPSCharacter* Player = Cast<AFPSCharacter>(
	//	OwnerComp.GetBlackboardComponent()->GetValueAsObject(FName("Player Target")));

	// Method 2: Only for player
    // APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    //AFPSCharacter* Player = Cast<AFPSCharacter>(PlayerPawn);

	// Method 3: Faster Get character
	AFPSCharacter* Player = Cast<AFPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(),0));

	
	if(!Player) return EBTNodeResult::Failed;

	float DamageAmount = 1.0f;
	
	AEnemyAIController* AIOwner = Cast<AEnemyAIController>(OwnerComp.GetAIOwner());
	if (!AIOwner) return EBTNodeResult::Failed;

	// Method 1 of applying damage
	Player->TakeDamage(DamageAmount, FDamageEvent(), AIOwner, AIOwner->GetPawn());
	// Method 2 of damage
	// UGameplayStatics::ApplyDamage(Player, DamageAmount, AIOwner,
	// 	AIOwner->GetPawn(), UDamageType::StaticClass());
	
	return  EBTNodeResult::Succeeded;
}
