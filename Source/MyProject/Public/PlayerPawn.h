// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "InputMappingContext.h"
#include "MyProjectileActor.h"
#include "PlayerPawn.generated.h"

UCLASS()
class MYPROJECT_API APlayerPawn : public APawn
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputMappingContext> InputMappingContext;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> InputActionMove;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> InputActionLook;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> InputActionZoom;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> InputActionScale;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> InputActionSpawn;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> InputActionRotate;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AMyProjectileActor> ProjectileClass;

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<USpringArmComponent> SpringArmComponent;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UCameraComponent> CameraComponent;
	
	
	void InputMove(const FInputActionValue& InputActionValue);
	
	void InputZoom(const FInputActionValue& InputActionValue);
	
	void InputLook(const FInputActionValue& InputActionValue);
	
	void InputScale(const FInputActionValue& InputActionValue);
	
	void InputSpawnProjectile(const FInputActionValue& InputActionValue);
	
	void InputRotateProjectile(const FInputActionValue& InputActionValue);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
};
