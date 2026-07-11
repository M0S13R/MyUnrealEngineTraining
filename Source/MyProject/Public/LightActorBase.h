// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/PointLightComponent.h"
#include "MyInterface.h"
#include "LightActorBase.generated.h"

UCLASS()
class MYPROJECT_API ALightActorBase : public AActor, public IMyInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALightActorBase();
	
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UPointLightComponent> BasePointLight;
	
	virtual void OnInteract_Implementation() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
