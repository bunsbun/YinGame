// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "YGameplayInterface.h"
#include "GameFramework/Actor.h"
#include "YHealthMachine.generated.h"

class UYPlayerComponents;
class AYBottleHealth;
class UYSpawnComponent;

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
    AYBottleHealth* BottleHealth;

	UPROPERTY(EditAnywhere)
    UYSpawnComponent* SpawnComponent;


	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
 //   AYBottleHealth* BottleHealth;
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
 //   AYBottleHealth* BottleHealth;
private:

	//UPROPERTY(EditAnywhere)
	//TSubclassOf<AYBottleHealth> BottleHealth;

protected:
	
	virtual void BeginPlay() override;

private:

	/*UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);*/


};
