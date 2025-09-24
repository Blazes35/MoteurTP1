// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"

#include "Asteroid.h"
#include "SpacePlayerState.h"
#include "GameFramework/PlayerState.h"
#include "GameFramework/PlayerController.h"
#include "Components/BoxComponent.h"
#include "GameFramework/FloatingPawnMovement.h"

APlayerPawn::APlayerPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
	RootComponent = BoxCollision;

	MovementComponent = CreateDefaultSubobject<
		UPawnMovementComponent, UFloatingPawnMovement>(TEXT("MovementComponent"));
	MovementComponent->UpdatedComponent = BoxCollision;

	// Initialisez les limites avec des valeurs par défaut si nécessaire
	MinBounds = FVector2D(-1000.f, -1600.0f);
	MaxBounds = FVector2D(50.f, 1600.0f);
}

void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();

	this->OnActorBeginOverlap.AddDynamic(this, &APlayerPawn::OnOverlap);
	SpacePlayerState = GetPlayerState<ASpacePlayerState>();
}

void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();

	// Limite la position de l'acteur aux bornes définies
	CurrentLocation.Y = FMath::Clamp(CurrentLocation.Y, MinBounds.Y, MaxBounds.Y);
	CurrentLocation.Z = FMath::Clamp(CurrentLocation.Z, MinBounds.X, MaxBounds.X);

	// Applique la nouvelle position si elle a été modifiée
	SetActorLocation(CurrentLocation);
}

void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void APlayerPawn::Move(FVector2D Direction)
{
	if (MovementComponent)
	{
		MovementComponent->AddInputVector(FVector(0.f, Direction.Y, Direction.X));
	}
}

void APlayerPawn::SpawnObject()
{
	FVector Location = GetActorLocation();

	Location.X += 0.5f;
	Location.Z += 100.f;

	if (ObjectToSpawn)
	{
		GetWorld()->SpawnActor<AActor>(ObjectToSpawn, Location, FRotator(0, 0, 0));
	}
}

void APlayerPawn::OnOverlap(AActor* MyActor, AActor* OtherActor)
{
	if (OtherActor->IsA(AAsteroid::StaticClass()))
	{
		UE_LOG(LogTemp, Warning, TEXT("OnOverlap"));
		if (SpacePlayerState)
		{
			UE_LOG(LogTemp, Warning, TEXT("onPlayerState"));
			// Appelle une fonction sur SpacePlayerState pour réduire la vie.
			// Cet exemple suppose une fonction UpdateHealth et une valeur de dégât de -10.
			SpacePlayerState->GetDamage();
		}
		OtherActor->Destroy();
	}
}
