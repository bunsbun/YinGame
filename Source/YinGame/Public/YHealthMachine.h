// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "YGameplayInterface.h"
#include "GameFramework/Actor.h"
#include "YHealthMachine.generated.h"


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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UStaticMeshComponent* BottleHealthComponent;


protected:
	
	virtual void BeginPlay() override;

private:

	


};
