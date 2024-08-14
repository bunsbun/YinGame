#include "YDamageArea.h"
#include "YPlayerComponents.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

AYDamageArea::AYDamageArea()
{
 	
	PrimaryActorTick.bCanEverTick = true;

	DamageAreaComponent = CreateDefaultSubobject<UBoxComponent>("DamageAreaComponent");
	RootComponent = DamageAreaComponent;

	Damage = 10.0f;
	DamageInterval = 1.0f;
	OverlappingActor = nullptr;

}


void AYDamageArea::BeginPlay()
{
	Super::BeginPlay();

	DamageAreaComponent->OnComponentBeginOverlap.AddDynamic(this, &AYDamageArea::OnOverlapBegin);
	DamageAreaComponent->OnComponentEndOverlap.AddDynamic(this, &AYDamageArea::OnOverlapEnd);
	
}

void AYDamageArea::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	
	if (OtherActor && (OtherActor != this) && OtherComp)
    {
        OverlappingActor = OtherActor;

        // Запуск таймера для нанесения урона
        GetWorldTimerManager().SetTimer(DamageTimerHandle, this, &AYDamageArea::ApplyContinuousDamage, DamageInterval, true);
        
        UE_LOG(LogTemp, Warning, TEXT("Actor %s entered the damage box!"), *OtherActor->GetName());
    }
	
}
		

void AYDamageArea::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	 if (OtherActor && (OtherActor != this) && OtherComp)
    {
        // Остановка таймера при выходе из зоны
        GetWorldTimerManager().ClearTimer(DamageTimerHandle);
        OverlappingActor = nullptr;
        
        UE_LOG(LogTemp, Warning, TEXT("Actor %s left the damage box!"), *OtherActor->GetName());
    }
}

void AYDamageArea::ApplyContinuousDamage()
{
	UGameplayStatics::ApplyDamage(OverlappingActor, Damage, GetInstigatorController(), this, nullptr);
}

void AYDamageArea::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

