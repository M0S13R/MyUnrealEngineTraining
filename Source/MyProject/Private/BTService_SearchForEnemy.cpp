// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_SearchForEnemy.h"
#include "AiCharacter.h"
#include "MyAIController.h"
#include "Kismet/KismetSystemLibrary.h"
#include "MyProjectCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"


UBTService_SearchForEnemy::UBTService_SearchForEnemy(const FObjectInitializer& ObjectInitializer)
{
	EnemyKey.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UBTService_SearchForEnemy, EnemyKey), AActor::StaticClass());
}

void UBTService_SearchForEnemy::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	bool Seen = false;
	AMyAIController* Controller = Cast<AMyAIController>(OwnerComp.GetOwner());
	
	if (!Controller) return;
	
	AAiCharacter* Character = Cast<AAiCharacter>(Controller->GetPawn());
	
	if (!Character)
	{
		return;
	}
	
	float PatrolRadius = Controller->GetPatrolRadius();
	FVector Start = Character->GetActorLocation();
	FVector End = Start;
	TArray<FHitResult> OutHits;
	TArray<TEnumAsByte<EObjectTypeQuery>> TraceObjectTypes;
	TraceObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));
	UKismetSystemLibrary::SphereTraceMultiForObjects(GetWorld(), Start, End, PatrolRadius, TraceObjectTypes, false, TArray<AActor*>(), EDrawDebugTrace::None, OutHits, true);
	
	for (FHitResult& HitResult : OutHits)
	{
		if (AMyProjectCharacter* Enemy = Cast<AMyProjectCharacter>(HitResult.GetActor()))
		{
			Controller->GetBlackboardComponent()->SetValueAsObject(EnemyKey.SelectedKeyName, Enemy);
			Seen = true;
		}
	}
	
	if (!Seen)
	{
		Controller->GetBlackboardComponent()->SetValueAsObject(Controller->GetDetectedEnemyKey(), nullptr);
	}
}
