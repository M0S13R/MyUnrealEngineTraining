// Fill out your copyright notice in the Description page of Project Settings.


#include "OverlapCube.h"

// Sets default values
AOverlapCube::AOverlapCube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
	RootComponent = CubeMesh;
	
	CubeMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CubeMesh->SetCollisionProfileName(TEXT("CustomOverlap"));
	CubeMesh->SetCollisionObjectType(ECC_GameTraceChannel1);
	CubeMesh->SetCollisionResponseToAllChannels(ECR_Ignore);
}

// Called when the game starts or when spawned
void AOverlapCube::BeginPlay()
{
	Super::BeginPlay();
	CubeMesh->OnComponentBeginOverlap.AddDynamic(this, &AOverlapCube::OnBeginOverlap);
	CubeMesh->OnComponentEndOverlap.AddDynamic(this, &AOverlapCube::OnEndOverlap);
}

// Called every frame
void AOverlapCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOverlapCube::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(0, 1.0f, FColor::Red, FString::Printf(TEXT("Begin overlapping with %s"), *OverlappedComponent->GetName()));
	}
}

void AOverlapCube::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(0, 1.0f, FColor::Red, FString::Printf(TEXT("End overlapping with %s"), *OverlappedComponent->GetName()));
	}
}

