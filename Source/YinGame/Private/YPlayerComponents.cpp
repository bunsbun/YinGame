#include "YPlayerComponents.h"

DEFINE_LOG_CATEGORY_STATIC(LogHealthComponent, All, All);

UYPlayerComponents::UYPlayerComponents()
{

	PrimaryComponentTick.bCanEverTick = true;

	Health = 100.0f;

}

void UYPlayerComponents::ApplyHealthChange(float Damage)
{
	Health = FMath::Max(0, Health - Damage);
	if(Health > 100.0f)
	{
		Health = 100.0f;
		return;
	}
	OnHealthChanged.Broadcast(Health);

	UE_LOG(LogHealthComponent, Display, TEXT("Health: %f") ,Health);
}

bool UYPlayerComponents::IsAlive() const
{
	return Health > 0.0f;
}

void UYPlayerComponents::BeginPlay()
{
	Super::BeginPlay();
	
}




void UYPlayerComponents::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

