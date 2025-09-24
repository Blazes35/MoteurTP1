// Fill out your copyright notice in the Description page of Project Settings.


#include "DestroyedAsteroid.h"

// Sets default values
ADestroyedAsteroid::ADestroyedAsteroid()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ADestroyedAsteroid::BeginPlay()
{
	Super::BeginPlay();

	LifeSpan= 2.0f;
}

void ADestroyedAsteroid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	LifeSpan -= DeltaTime;
	if (LifeSpan <= 0.f)
	{
		Destroy();
	}
}

