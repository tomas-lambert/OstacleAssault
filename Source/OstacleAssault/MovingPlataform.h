// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlataform.generated.h"

UCLASS()
class OSTACLEASSAULT_API AMovingPlataform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlataform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

UPROPERTY(EditAnywhere, Category = "Moving Plataform")
	FVector PlataformVelociy = FVector(100, 0, 0);

	UPROPERTY(EditAnywhere, Category = "Moving Plataform")
	float MoveDistance = 100;

	UPROPERTY(EditAnywhere, Category = "Rotation")
	FRotator RotationVelocity;

	FVector StartLocation;

	void MovePlataform(float DeltaTime);

	void RotatePlataform(float DeltaTime);

	bool ShouldPlataformReturn() const;
	float GetDistanceMoved() const;

};
