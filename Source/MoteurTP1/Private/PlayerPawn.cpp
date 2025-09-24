// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"

#include "Asteroid.h"
#include "GameFramework/PlayerController.h"
#include "Components/BoxComponent.h"
#include "GameFramework/FloatingPawnMovement.h"

APlayerPawn::APlayerPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
	RootComponent = BoxCollision;

	MovementComponent = CreateDefaultSubobject<UPawnMovementComponent, UFloatingPawnMovement>(TEXT("MovementComponent"));
	MovementComponent->UpdatedComponent = BoxCollision;

	// Initialisez les limites avec des valeurs par défaut si nécessaire
	MinBounds = FVector2D(-1000.f,-1600.0f);
	MaxBounds = FVector2D(50.f,1600.0f );

}

void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
	this->OnActorBeginOverlap.AddDynamic(this, &APlayerPawn::OnOverlap);

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
		MovementComponent->AddInputVector(FVector(0.f,Direction.Y, Direction.X));
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
	// Vérifie si l'autre acteur est un laser et n'est pas l'astéroïde lui-même
	if (OtherActor->IsA(AAsteroid::StaticClass()))
	{
		// Health -= 1.f;
		OtherActor->Destroy();
	}
}