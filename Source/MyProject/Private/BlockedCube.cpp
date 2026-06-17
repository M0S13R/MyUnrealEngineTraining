// Fill out your copyright notice in the Description page of Project Settings.


#include "BlockedCube.h"

// Sets default values
ABlockedCube::ABlockedCube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
	RootComponent = CubeMesh;
	
	CubeMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CubeMesh->SetCollisionProfileName(TEXT("CustomCollision"));
	CubeMesh->SetCollisionResponseToAllChannels(ECR_Block);
	CubeMesh->SetNotifyRigidBodyCollision(true);
	
}

// Called when the game starts or when spawned
void ABlockedCube::BeginPlay()
{
	Super::BeginPlay();
	CubeMesh->OnComponentHit.AddDynamic(this, &ABlockedCube::OnHit);
}

// Called every frame
void ABlockedCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABlockedCube::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 1.0f, FColor::Red, FString::Printf(TEXT("Hit with %s"), *HitComponent->GetName()));
	}
}

