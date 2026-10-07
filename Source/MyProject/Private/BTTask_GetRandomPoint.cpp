// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_GetRandomPoint.h"

#include "AiCharacter.h"
#include "MyAIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_GetRandomPoint::UBTTask_GetRandomPoint(const FObjectInitializer& ObjectInitializer)
{
	
}

EBTNodeResult::Type UBTTask_GetRandomPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AMyAIController* Controller = Cast<AMyAIController>(OwnerComp.GetAIOwner());
	if (!Controller)
	{
		return EBTNodeResult::Failed;
	}
	
	PatrolRadius = Controller->GetPatrolRadius();
	
	if (PatrolRadius > 0.f)
	{
		FNavLocation ResultLocation;
		
		if (UNavigationSystemV1::GetNavigationSystem(&OwnerComp)->GetRandomReachablePointInRadius(Controller->GetNavAgentLocation(), PatrolRadius, ResultLocation))
		{
			if (AAiCharacter* Character = Cast<AAiCharacter>(Controller->GetPawn()))
			{
				Controller->GetBlackboardComponent()->SetValueAsVector(Controller->GetLocationKey(), ResultLocation.Location);
				return EBTNodeResult::Succeeded;
			}
		}
	}
	return EBTNodeResult::Failed;
}
