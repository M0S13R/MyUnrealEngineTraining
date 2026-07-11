// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyInterface.h"
#include "StaticMeshInteractActor.generated.h"

UCLASS()
class MYPROJECT_API AStaticMeshInteractActor : public AActor, public IMyInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStaticMeshInteractActor();
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void OnInteract_Implementation() override;
	
private:
	bool bIsScaled;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION()
	void DestroyMesh();
};
