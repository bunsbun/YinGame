// Fill out your copyright notice in the Description page of Project Settings.
#include "YPlayerComponents.h"
#include "YCharacter.h"
#include "YBottleHealth.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "YSpawnComponent.h"
#include "YHealthMachine.h"


// Sets default values
AYHealthMachine::AYHealthMachine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MachineComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MachineComponent"));
	RootComponent = MachineComponent;

	SpawnComponent = CreateDefaultSubobject<UYSpawnComponent>(TEXT("SpawnComponent"));



}


void AYHealthMachine::BeginPlay()
{
	Super::BeginPlay();

	
}

void AYHealthMachine::Interact_Implementation(APawn* InstigatorPawn)
{
	
	SpawnComponent->SpawnBottleHealth();
	
}

void AYHealthMachine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

