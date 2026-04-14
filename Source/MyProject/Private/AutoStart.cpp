// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/AutoStart.h"

void AAutoStart::BeginPlay()
{
	Super::BeginPlay();
	if (AudioComponent)
	{
		AudioComponent->Play();
	}
}