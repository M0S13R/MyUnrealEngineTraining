// Fill out your copyright notice in the Description page of Project Settings.


#include "BTDecorator_CheckStun.h"

#include "AiCharacter.h"
#include "MyAIController.h"

bool UBTDecorator_CheckStun::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	if (auto Controller = Cast<AMyAIController>(OwnerComp.GetOwner()))
	{
		if (auto Character = Cast<AAiCharacter>(Controller->GetPawn()))
		{
			return Character->IsStunned;
		}
	}
	return false;
}
