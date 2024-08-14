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
	OnHealthChanged.Broadcast(Health);

	UE_LOG(LogHealthComponent, Display, TEXT("Health: %f") ,Health);
}

void UYPlayerComponents::BeginPlay()
{
	Super::BeginPlay();

	//AActor* MainCharacter = GetOwner();
	//if(MainCharacter){
	//	MainCharacter->OnTakeAnyDamage.AddDynamic(this, &UYPlayerComponents::OnTakeAnyDamageHandle);
	//}
	
}




void UYPlayerComponents::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

