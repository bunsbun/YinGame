#include "AI/AIYCharacter.h"

// Sets default values
AAIYCharacter::AAIYCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

}


void AAIYCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAIYCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAIYCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

