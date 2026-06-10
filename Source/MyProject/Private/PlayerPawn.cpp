// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"


// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));
	
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(RootComponent);
	
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(RootComponent);
	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent);
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		ULocalPlayer* LocalPlayer = PlayerController->GetLocalPlayer();
		
		if (UEnhancedInputLocalPlayerSubsystem* InputLocalPlayerSubsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			InputLocalPlayerSubsystem->AddMappingContext(InputMappingContext, 1);
		}
	}
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	if (UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		Input->BindAction(InputActionMove, ETriggerEvent::Triggered, this, &ThisClass::InputMove);
		Input->BindAction(InputActionZoom, ETriggerEvent::Triggered, this, &ThisClass::InputZoom);
		Input->BindAction(InputActionLook, ETriggerEvent::Triggered, this, &ThisClass::InputLook);
		Input->BindAction(InputActionScale, ETriggerEvent::Triggered, this, &ThisClass::InputScale);
		Input->BindAction(InputActionSpawn, ETriggerEvent::Triggered, this, &ThisClass::InputSpawnProjectile);
		Input->BindAction(InputActionRotate, ETriggerEvent::Triggered, this, &ThisClass::InputRotateProjectile);
	}
}

void APlayerPawn::InputMove(const FInputActionValue& InputActionValue)
{
	const FVector2D& MovementVector = InputActionValue.Get<FVector2D>();
	
	SetActorLocation(GetActorLocation() + GetActorForwardVector() * MovementVector.Y);
	SetActorLocation(GetActorLocation() + GetActorRightVector() * MovementVector.X);
}


void APlayerPawn::InputZoom(const FInputActionValue& InputActionValue)
{
	float ZoomValue = InputActionValue.Get<float>();
	
	float NewTargetArmLength = SpringArmComponent->TargetArmLength + ZoomValue;
	SpringArmComponent->TargetArmLength = FMath::Clamp(NewTargetArmLength, 200, 500);
}

void APlayerPawn::InputLook(const FInputActionValue& InputActionValue)
{
	FVector2D LookAxisVector = InputActionValue.Get<FVector2D>();
	AddControllerYawInput(LookAxisVector.X);
	AddControllerPitchInput(LookAxisVector.Y);
}

void APlayerPawn::InputScale(const FInputActionValue& InputActionValue)
{
	float ScaleValue = InputActionValue.Get<float>();
	FVector CurrentScale = (ScaleValue > 0) ? GetActorScale3D() + 0.25 : StaticMeshComponent->GetRelativeScale3D() - 0.25;
	
	CurrentScale.X = FMath::Clamp(CurrentScale.X, 0.5, 2.0);
	CurrentScale.Y = FMath::Clamp(CurrentScale.Y, 0.5, 2.0);
	CurrentScale.Z = FMath::Clamp(CurrentScale.Z, 0.5, 2.0);
	
	if (ScaleValue > 0) SetActorScale3D(CurrentScale);
	else StaticMeshComponent->SetRelativeScale3D(CurrentScale);
}

void APlayerPawn::InputSpawnProjectile(const FInputActionValue& InputActionValue)
{
	FVector SpawnLocation = GetActorLocation() + GetActorForwardVector() * 100;
	
	GetWorld()->SpawnActor<AMyProjectileActor>(ProjectileClass, SpawnLocation, GetActorRotation());
}

void APlayerPawn::InputRotateProjectile(const FInputActionValue& InputActionValue)
{
	float RotateValue = InputActionValue.Get<float>();
	float PitchDeg = 5 * RotateValue * GetWorld()->GetDeltaSeconds();
	
	AddActorLocalRotation(FRotator(PitchDeg, 0, 0));
}
