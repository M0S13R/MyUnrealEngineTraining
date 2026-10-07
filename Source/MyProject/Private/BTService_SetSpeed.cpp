// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_SetSpeed.h"

#include "AiCharacter.h"
#include "MyAIController.h"
#include "GameFramework/CharacterMovementComponent.h"

void UBTService_SetSpeed::OnSearchStart(FBehaviorTreeSearchData& SearchData)
{
	AMyAIController* Controller = Cast<AMyAIController>(SearchData.OwnerComp.GetOwner());
	AAiCharacter* Character = Cast<AAiCharacter>(Controller->GetPawn());
	
	if (Character)
	{
		Character->GetCharacterMovement()->MaxWalkSpeed = Speed;
	}
}
