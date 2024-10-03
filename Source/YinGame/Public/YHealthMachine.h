// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "YGameplayInterface.h"
#include "GameFramework/Actor.h"
#include "YHealthMachine.generated.h"

class UYPlayerComponents;
class AYBottleHealth;
class UYSpawnComponent;
class UBoxComponent;

UENUM(BlueprintType) 
enum class YSpawnModel : uint8
{
	BOTTLE_HEALTH  UMETA(DisplayName = "BOTTLE_HEALTH"),
	BOTTLE_STAMINA UMETA(DisplayName = "BOTTLE_STAMINA"),
	BOTTLE_SPEED   UMETA(DisplayName = "BOTTLE_SPEED")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSpawnComponent, YSpawnModel, SpawnModel);

UCLASS()
class YINGAME_API AYHealthMachine : public AActor, public IYGameplayInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AYHealthMachine();

public:

	void Interact_Implementation(APawn* InstigatorPawn);

	virtual void Tick(float DeltaTime) override;

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UStaticMeshComponent* MachineComponent;

	UPROPERTY(EditAnywhere)
    UYSpawnComponent* SpawnComponent;

	UPROPERTY(EditAnywhere)
	UBoxComponent* AreaForBottles;

	UPROPERTY(EditAnywhere)
	FVector RandomLocation;

	UPROPERTY(BlueprintAssignable)
	FOnSpawnComponent OnSpawnComponent;

private:


protected:
	
	virtual void BeginPlay() override;


};
