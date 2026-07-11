// Fill out your copyright notice in the Description page of Project Settings.


#include "LightActorBase.h"


// Sets default values
ALightActorBase::ALightActorBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BasePointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("BasePointLight"));
	RootComponent = BasePointLight;
}

// Called when the game starts or when spawned
void ALightActorBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ALightActorBase::OnInteract_Implementation()
{
	
}

// Called every frame
void ALightActorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

