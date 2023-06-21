// Fill out your copyright notice in the Description page of Project Settings.


#include "bomb.h"
#include "SnakeBase.h"

// Sets default values
Abomb::Abomb()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Abomb::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Abomb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void Abomb::Explode(AActor* Interactor, bool bIsHead)
{
	if (bIsHead)
	{
		auto Snake = Cast<ASnakeBase>(Interactor);
		if (IsValid(Snake))
		{
			UFUNCTION(BlueprintCallable);
		}
	}
}
