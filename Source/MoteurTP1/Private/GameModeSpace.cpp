// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModeSpace.h"


AGameModeSpace::AGameModeSpace()
{
	PrimaryActorTick.bCanEverTick = true;
	
	SpawnLocationIntervalY = FVector2D(-2000.f, 2000.f);
	SpawnInterval = FVector2D(1.f, 4.f);
	CurrentSpawnInterval = 0.f;
}

void AGameModeSpace::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TimeSinceLastSpawn += DeltaTime;
	if (TimeSinceLastSpawn >= CurrentSpawnInterval)
	{
		SpawnObject();
		CurrentSpawnInterval = FMath::FRandRange(SpawnInterval.X, SpawnInterval.Y);
		TimeSinceLastSpawn = 0.0f;
	}
}

void AGameModeSpace::SpawnObject()
{
	if (ObjectToSpawn)
	{
		FVector Location = FVector(-1.f, FMath::FRandRange(SpawnLocationIntervalY.X, SpawnLocationIntervalY.Y), 2200.f);
		GetWorld()->SpawnActor<AActor>(ObjectToSpawn, Location, FRotator(0, 0, 0));
	}
}
