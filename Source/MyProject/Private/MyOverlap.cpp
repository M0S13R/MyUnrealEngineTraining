// Fill out your copyright notice in the Description page of Project Settings.


#include "MyOverlap.h"

#include "DiffUtils.h"

AMyOverlap::AMyOverlap()
{
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapComponent"));
	BoxComponent->SetupAttachment(RootComponent);
}

void AMyOverlap::BeginPlay()
{
	Super::BeginPlay();
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AMyOverlap::OnBeginOverlap);
}

void AMyOverlap::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
		int OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (AudioComponent && !AudioComponent->IsPlaying())
	{
		AudioComponent->Play();
	}
}