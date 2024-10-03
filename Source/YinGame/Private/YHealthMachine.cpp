// Fill out your copyright notice in the Description page of Project Settings.
#include "YHealthMachine.h"
#include "YSpawnComponent.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AYHealthMachine::AYHealthMachine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MachineComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MachineComponent"));
	RootComponent = MachineComponent;

	SpawnComponent = CreateDefaultSubobject<UYSpawnComponent>(TEXT("SpawnComponent"));
	AreaForBottles = CreateDefaultSubobject<UBoxComponent>(TEXT("AreaForBottles"));

}

void AYHealthMachine::BeginPlay()
{
	Super::BeginPlay();	
}

void AYHealthMachine::Interact_Implementation(APawn* InstigatorPawn)
{

	OnSpawnComponent.Broadcast(YSpawnModel::BOTTLE_HEALTH);

}

void AYHealthMachine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

