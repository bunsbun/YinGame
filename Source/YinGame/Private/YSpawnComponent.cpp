#include "YSpawnComponent.h"
#include "YBottleHealth.h"
#include <Kismet/GameplayStatics.h>


UYSpawnComponent::UYSpawnComponent()
{

	PrimaryComponentTick.bCanEverTick = true;


}



void UYSpawnComponent::BeginPlay()
{
	Super::BeginPlay();


	
}

void UYSpawnComponent::SpawnBottleHealth()
{
    AActor* Owner = GetOwner();
    //CurrentBottleHealth = Owner->GetWorld()->SpawnActor<AYBottleHealth>(AYBottleHealth::StaticClass());
    AActor* Actor = UGameplayStatics::GetActorOfClass(Owner->GetWorld(),AYBottleHealth::StaticClass());
	if(Actor)
	{
		AYBottleHealth* CurrentBottleHealth = Cast<AYBottleHealth>(Actor);
		if(CurrentBottleHealth)
		{
			CurrentBottleHealth->SetVisibilityBottle();
		}
		
	}
}


void UYSpawnComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

