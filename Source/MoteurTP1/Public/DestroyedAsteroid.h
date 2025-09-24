// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DestroyedAsteroid.generated.h"

UCLASS()
class MOTEURTP1_API ADestroyedAsteroid : public AActor
{
	GENERATED_BODY()
	
public:	
	ADestroyedAsteroid();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Asteroid")
	float LifeSpan;

protected:
	virtual void BeginPlay() override;
};
