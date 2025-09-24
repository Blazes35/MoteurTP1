// Fill out your copyright notice in the Description page of Project Settings.

#include "Asteroid.h"

#include "Laser.h"
#include "PlayerPawn.h"
#include "Components/BoxComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Kismet/GameplayStatics.h"

AAsteroid::AAsteroid()
{
	PrimaryActorTick.bCanEverTick = true;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	RootComponent = BoxCollision;

	MovementComponent = CreateDefaultSubobject<
		UPawnMovementComponent, UFloatingPawnMovement>(TEXT("MovementComponent"));
	MovementComponent->UpdatedComponent = BoxCollision;

	MinScale = 1.f;
	MaxScale = 4.f;
}

void AAsteroid::BeginPlay()
{
	Super::BeginPlay();

	const float RandomScale = FMath::FRandRange(MinScale, MaxScale);
	SetActorScale3D(FVector(RandomScale));
	Health = FMath::RoundToFloat(RandomScale);


	if (const APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0))
	{
		MovementDirection = PlayerPawn->GetActorLocation() - GetActorLocation();
		MovementDirection.Normalize();
	}

	this->OnActorBeginOverlap.AddDynamic(this, &AAsteroid::OnOverlap);
}

void AAsteroid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetActorLocation().Z < -1800.f)
	{
		Destroy();
	}
	else
	{
		MovementComponent->AddInputVector(MovementDirection);
	}
}

void AAsteroid::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}


void AAsteroid::OnOverlap(AActor* MyActor, AActor* OtherActor)
{
	// Vérifie si l'autre acteur est un laser et n'est pas l'astéroïde lui-même
	if (OtherActor->IsA(ALaser::StaticClass()))
	{
		Health -= 1.f;
		OtherActor->Destroy();

		if (Health <= 0.f)
		{
			Destroy();
		}
	}
}