// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Asteroid.generated.h"

class UFloatingPawnMovement;

UCLASS()
class MOTEURTP1_API AAsteroid : public APawn
{
	GENERATED_BODY()

public:
	AAsteroid();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Destroyed() override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* BoxCollision;

	UPROPERTY(Category=Pawn, VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess="true"))
	UPawnMovementComponent* MovementComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
	FVector MovementDirection;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning")
	int Health;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float MinScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float MaxScale;

	UFUNCTION()
	void OnOverlap(AActor* MyActor, AActor* OtherActor);
	
	UFUNCTION(BlueprintCallable)
	void SpawnObject();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spaceship")
	TSubclassOf<AActor> ObjectToSpawn;
};
