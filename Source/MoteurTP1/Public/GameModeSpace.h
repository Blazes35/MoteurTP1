// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameModeSpace.generated.h"

/**
 * 
 */
UCLASS()
class MOTEURTP1_API AGameModeSpace : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGameModeSpace();
	virtual void Tick(float DeltaTime) override;

protected:
	UFUNCTION(BlueprintCallable)
	void SpawnObject();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Asteroid")
	TSubclassOf<AActor> ObjectToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Asteroid")
	FVector2D SpawnInterval;
	float CurrentSpawnInterval;
	float TimeSinceLastSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Asteroid")
	FVector2D SpawnLocationIntervalY;
};
