// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

UCLASS()
class MOTEURTP1_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	APlayerPawn();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* BoxCollision;

	UPROPERTY(Category=Pawn, VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess="true"))
	UPawnMovementComponent* MovementComponent;

	UFUNCTION(BlueprintCallable)
	void Move(FVector2D Direction);

	UFUNCTION(BlueprintCallable)
	void SpawnObject();
	UFUNCTION()
	void OnOverlap(AActor* MyActor, AActor* OtherActor);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spaceship")
	TSubclassOf<AActor> ObjectToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	FVector2D MinBounds;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	FVector2D MaxBounds;

};
