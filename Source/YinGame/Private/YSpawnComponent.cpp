#include "YSpawnComponent.h"
#include "YBottleHealth.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"


UYSpawnComponent::UYSpawnComponent()
{

	PrimaryComponentTick.bCanEverTick = true;
	CurrentBottleHealth = CreateDefaultSubobject<AYBottleHealth>(TEXT("CurrentBottleHealth"));


}



void UYSpawnComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UYSpawnComponent::SpawnBottleHealth(FVector& BoxCenter, FVector& BoxExtent)
{
	FVector RandomLocation = UKismetMathLibrary::RandomPointInBoundingBox(BoxCenter, BoxExtent);

}


void UYSpawnComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

