// Fill out your copyright notice in the Description page of Project Settings.


#include "BTDecorator_IsAlive.h"
#include "AiCharacter.h"
#include "MyAIController.h"

bool UBTDecorator_IsAlive::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	if (AMyAIController* Controller = Cast<AMyAIController>(OwnerComp.GetAIOwner()))
	{
		if (AAiCharacter* Character = Cast<AAiCharacter>(Controller->GetPawn()))
		{
			if (Character->CurrentHP == 0)
			{
				Character->IsStunned = true;
				return false;
			}
		}
	}
	return true;
}
