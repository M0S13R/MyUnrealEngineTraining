// Fill out your copyright notice in the Description page of Project Settings.


#include "MyProjectileActor.h"

// Sets default values
AMyProjectileActor::AMyProjectileActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));
	RootComponent = ProjectileMesh;
	
	ProjectileComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComponent"));
	ProjectileComponent->InitialSpeed = 250;
}

// Called when the game starts or when spawned
void AMyProjectileActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyProjectileActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

