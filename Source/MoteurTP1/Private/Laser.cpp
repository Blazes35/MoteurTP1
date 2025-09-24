// Fill out your copyright notice in the Description page of Project Settings.


#include "Laser.h"

#include "Components/BoxComponent.h"
#include "GameFramework/FloatingPawnMovement.h"

ALaser::ALaser()
{
	PrimaryActorTick.bCanEverTick = true;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
	RootComponent = BoxCollision;

	MovementComponent = CreateDefaultSubobject<UPawnMovementComponent, UFloatingPawnMovement>(TEXT("MovementComponent"));
	MovementComponent->UpdatedComponent = BoxCollision;
}

void ALaser::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetActorLocation().Z > 1670.0f)
	{
		Destroy();
	}
	MovementComponent->AddInputVector(FVector(0.f,0.f, 150.f));
}

void ALaser::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

