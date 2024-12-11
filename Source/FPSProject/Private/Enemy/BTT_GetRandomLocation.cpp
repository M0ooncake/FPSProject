// Fill out your copyright notice in the Description page of Project Settings.



#include "Enemy/BTT_GetRandomLocation.h"




EBTNodeResult::Type UBTT_GetRandomLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// 1. Get a random point on the nav mesh
	// 2. Set the blackbaord random patrol location
	// 3. return if we succeeded or not

	// Create a nav mesh
	NavArea = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
	//	If the Nav mesh exists, proceed
	if(NavArea)
	{
		AEnemyAIController* AIOwner = Cast<AEnemyAIController>(OwnerComp.GetAIOwner());
		NavArea->K2_GetRandomReachablePointInRadius(GetWorld(), AIOwner->GetPawn()->GetActorLocation(),
			RandomLocation, 2000.0f);
		
	}
	else
	{
		return EBTNodeResult::Failed;
	}
	AEnemyAIController* AIOwner = Cast<AEnemyAIController>(OwnerComp.GetAIOwner());
	OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName("Random Patrol Location"), RandomLocation);
	AIOwner->GetPawn()->SetActorLocation(RandomLocation);
	
	return EBTNodeResult::Succeeded;
	
}
