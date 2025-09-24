// Fill out your copyright notice in the Description page of Project Settings.


#include "SpacePlayerState.h"

ASpacePlayerState::ASpacePlayerState()
{
	PrimaryActorTick.bCanEverTick = true;

	PlayerHealth = 3;
	bIsGamePaused = false;
	TimeScore = 0;
}

void ASpacePlayerState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerHealth > 0)
	{
		TimeScore+= DeltaTime * 10;	}
}

void ASpacePlayerState::GetDamage()
{
	PlayerHealth--;
}
