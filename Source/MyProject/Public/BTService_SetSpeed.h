// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_SetSpeed.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UBTService_SetSpeed : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	
	void OnSearchStart(FBehaviorTreeSearchData& SearchData);
	
	UPROPERTY(EditAnywhere)
	float Speed;
};
