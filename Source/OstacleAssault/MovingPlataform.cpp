// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlataform.h"

// Sets default values
AMovingPlataform::AMovingPlataform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlataform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation(); 

	
}

// Called every frame
void AMovingPlataform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlataform(DeltaTime);

	RotatePlataform(DeltaTime);

}


void AMovingPlataform::MovePlataform(float DeltaTime)
{
	if ( ShouldPlataformReturn())
	{
		FVector MoveDirection = PlataformVelociy.GetSafeNormal();
		StartLocation = StartLocation + (MoveDirection * MoveDistance);
		SetActorLocation(StartLocation);
		PlataformVelociy = -PlataformVelociy;
	}
	else
	{
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation = CurrentLocation + (PlataformVelociy * DeltaTime);
		SetActorLocation(CurrentLocation);
	}	
}

void AMovingPlataform::RotatePlataform(float DeltaTime)
{
	UE_LOG(LogTemp, Display, TEXT("The Rotating Plataform fx"));
}

bool AMovingPlataform::ShouldPlataformReturn()
{
	return GetDistanceMoved() > MoveDistance;
}

float AMovingPlataform::GetDistanceMoved()
{
	return FVector::Dist(StartLocation, GetActorLocation());
}
