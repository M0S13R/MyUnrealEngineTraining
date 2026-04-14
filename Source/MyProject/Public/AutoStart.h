// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyActor.h"
#include "AutoStart.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AAutoStart : public AMyActor
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
};
