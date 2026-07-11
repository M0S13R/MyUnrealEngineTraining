// Fill out your copyright notice in the Description page of Project Settings.


#include "StaticMeshInteractActor.h"
#include "MyProjectCharacter.h"

// Sets default values
AStaticMeshInteractActor::AStaticMeshInteractActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = StaticMeshComponent;
	
	bIsScaled = false;
}

// Called when the game starts or when spawned
void AStaticMeshInteractActor::BeginPlay()
{
	Super::BeginPlay();
	
	Cast<AMyProjectCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn())->MyCustomDelegate.AddDynamic(this, &AStaticMeshInteractActor::DestroyMesh);
}

// Called every frame
void AStaticMeshInteractActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AStaticMeshInteractActor::OnInteract_Implementation()
{
	if (StaticMeshComponent)
	{
		FVector NewScale = bIsScaled ? FVector(1, 1, 1) : FVector(2, 2, 2);
		
		StaticMeshComponent->SetRelativeScale3D(NewScale);
		
		bIsScaled = !bIsScaled;
	}
}

void AStaticMeshInteractActor::DestroyMesh()
{
	StaticMeshComponent->DestroyComponent();
}
