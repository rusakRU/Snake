// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "bomb.generated.h"

UCLASS()
class SNAKEGAME_API Abomb : public AActor, public IInteractable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	Abomb();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Timer handle for the bomb explosion
	FTimerHandle ExplodeTimerHandle;

	// Function called when the bomb explodes

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void Explode(AActor* Interactor, bool bIsHead) override;
};


