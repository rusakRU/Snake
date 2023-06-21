#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SnakeBase.generated.h"


UENUM()
enum class EMovementDirection
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

UCLASS()
class SNAKEGAME_API ASnakeBase : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    ASnakeBase();

    UPROPERTY(EditDefaultsOnly)
        TSubclassOf<ASnakeElementBase> SnakeElementClass;

    UPROPERTY(EditDefaultsOnly)
        float ElementSize;

    UPROPERTY(EditDefaultsOnly)
        float MovementSpeed;

    UPROPERTY()
        TArray<ASnakeElementBase*> SnakeElements;

    UPROPERTY()
        EMovementDirection LastMoveDirection;

    UPROPERTY(EditDefaultsOnly) // Add this line to expose the bomb class in the editor
        TSubclassOf<Abomb> BombClass;

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    UFUNCTION(BlueprintCallable)
        void AddSnakeElement(int ElementsNum = 1);
    UFUNCTION(BlueprintCallable)
        void Move();
    UFUNCTION()
        void SnakeElementOverlap(ASnakeElementBase* OverlappedElement, AActor* Other);

    UFUNCTION(BlueprintCallable) // Add this line to expose the bomb placement function in the editor
        void PlaceBomb();


    // PlaceBomb() function implementation
    void ASnakeBase::PlaceBomb()
    {
        if (BombClass)
        {
            FVector SpawnLocation = GetActorLocation(); // Set the spawn location of the bomb
            FRotator SpawnRotation = GetActorRotation(); // Set the spawn rotation of the bomb

            // Spawn the bomb actor
            FActorSpawnParameters SpawnParams;
            GetWorld()->SpawnActor<Abomb>(BombClass, SpawnLocation, SpawnRotation, SpawnParams);
        }
    }
};

