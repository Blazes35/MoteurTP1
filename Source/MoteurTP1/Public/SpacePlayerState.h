// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "SpacePlayerState.generated.h"

/**
 * 
 */
UCLASS()
class MOTEURTP1_API ASpacePlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	ASpacePlayerState();
	virtual void Tick(float DeltaTime) override;
	void GetDamage();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsGamePaused;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Score")
	double TimeScore; 
};
