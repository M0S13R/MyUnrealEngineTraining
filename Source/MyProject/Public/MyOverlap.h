// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyActor.h"
#include "Components/BoxComponent.h"
#include "MyOverlap.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AMyOverlap : public AMyActor
{
	GENERATED_BODY()
	
public:
	AMyOverlap();
	
	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* BoxComponent;
	
protected:
	virtual void BeginPlay() override;
	
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
		int OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
