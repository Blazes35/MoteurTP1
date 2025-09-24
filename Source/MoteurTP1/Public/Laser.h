// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Laser.generated.h"

UCLASS()
class MOTEURTP1_API ALaser : public APawn
{
	GENERATED_BODY()

public:
	ALaser();
	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* BoxCollision;
	
	UPROPERTY(Category=Pawn, VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess="true"))
	UPawnMovementComponent* MovementComponent;

};
