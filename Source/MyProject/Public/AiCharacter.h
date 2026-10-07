// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/WidgetComponent.h"
#include "AiCharacter.generated.h"

class UWidgetComponent;

UCLASS()
class MYPROJECT_API AAiCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAiCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	void EndStun();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UFUNCTION(BlueprintCallable, Category = Character)
	void Attack();

	UFUNCTION(BlueprintCallable, Category = Character)
	void EndAttack();
	
	UFUNCTION(BlueprintCallable, Category = Character)
	void Stun();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool IsAttacking = false;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool IsStunned = false;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float ForwardInputValue;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float RightInputValue;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UWidgetComponent> HPWidgetComponent;
	
	int CurrentHP = 100;
};
