// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Attack.h"

#include "AiCharacter.h"
#include "MyAIController.h"

EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (auto Controller = Cast<AMyAIController>(OwnerComp.GetOwner()))
	{
		if (auto Character = Cast<AAiCharacter>(Controller->GetPawn()))
		{
			Character->Attack();
			return EBTNodeResult::Succeeded;
		}
	}
	return EBTNodeResult::Failed;
}
