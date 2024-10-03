#include "AI/YAICharacter.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "YCharacter.h"
#include "YPlayerComponents.h"

// Sets default values
AYAICharacter::AYAICharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	PatrolLocation = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	PlayerComponent = CreateDefaultSubobject<UYPlayerComponents>(TEXT("PlayerComponent"));

	CurrentMontageIndex = 0;
	DamageInterval = 5.0f;
	OverlappingActor = nullptr;

	Health = 100.f;

}



void AYAICharacter::BeginPlay()
{
	Super::BeginPlay();

	//HammerCollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	//PlayerComponent->OnHealthChanged.AddDynamic(this, &ThisClass::ApplyHealthChanged);

}

void AYAICharacter::HitCharacter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this && OtherActor->IsA(AYCharacter::StaticClass()))
	{
		UE_LOG(LogTemp, Warning, TEXT("OverlappedComponent %s !"), *OverlappedComponent->GetName());
	}
	
}

void AYAICharacter::SetAnimMontages(TArray<UAnimMontage*> NewMontages)
{
	AnimMontages = NewMontages;
}


void AYAICharacter::HitPlayer(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("Actor %s was hit!"), *OtherActor->GetName());
	UE_LOG(LogTemp, Error, TEXT("Actor %s was suck!"), *this->GetName());
}

//void AYAICharacter::DoHit(AActor* OtherActor)
//{
//
//	if (AYCharacter* PlayerActor = Cast<AYCharacter>(OtherActor))
//	{
//		UYPlayerComponents* PlayerComp = PlayerActor->FindComponentByClass<UYPlayerComponents>();
//		GetWorldTimerManager().SetTimer(DamageTimerHandle, this, &ThisClass::ApplyDamage, DamageInterval, true);
//		//PlayerComp->ApplyHealthChange(HitPower);
//	}	
//}

//void AYAICharacter::ApplyDamage()
//{
//	if (OverlappingActor)
//	{
//		DoHit(OverlappingActor);
//	}
//	
//}

void AYAICharacter::ApplyHealthChanged(float NewHealth)
{

}



void AYAICharacter::PrimaryAttack()
{
	if (AnimMontages.IsValidIndex(CurrentMontageIndex))
    {
        UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
        if (AnimInstance && AnimMontages[CurrentMontageIndex])
        {
            AnimInstance->Montage_Play(AnimMontages[CurrentMontageIndex]);
			CurrentMontageIndex++;
        }
    }else{ 
		CurrentMontageIndex = 0;
		PrimaryAttack();
	}


}



void AYAICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



