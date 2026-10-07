// Fill out your copyright notice in the Description page of Project Settings.


#include "AiCharacter.h"

// Sets default values
AAiCharacter::AAiCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HPWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("HPWidget"));
}

// Called when the game starts or when spawned
void AAiCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAiCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAiCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AAiCharacter::Attack()
{
	IsAttacking = true;
	
	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AAiCharacter::EndAttack, 3.f, false);
}

void AAiCharacter::EndAttack()
{
	IsAttacking = false;
}

void AAiCharacter::Stun()
{
	IsStunned = true;
	
	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AAiCharacter::EndStun, 3.f, false);
}

void AAiCharacter::EndStun()
{
	IsStunned = false;
}