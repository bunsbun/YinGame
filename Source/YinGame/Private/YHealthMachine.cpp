// Fill out your copyright notice in the Description page of Project Settings.


#include "YHealthMachine.h"


// Sets default values
AYHealthMachine::AYHealthMachine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MachineComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MachineComponent"));
	RootComponent = MachineComponent;

	BottleHealthComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BottleHealthComponent"));
	BottleHealthComponent->SetupAttachment(MachineComponent);
	
	BottleHealthComponent->SetVisibility(false);


}


// Called when the game starts or when spawned
void AYHealthMachine::BeginPlay()
{
	Super::BeginPlay();

	check(BottleHealthComponent);
	
}


void AYHealthMachine::Interact_Implementation(APawn* InstigatorPawn)
{
	BottleHealthComponent->SetVisibility(true);


	UE_LOG(LogTemp, Warning, TEXT("ExecuteAction called in MyActor!"));
}


// Called every frame
void AYHealthMachine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

