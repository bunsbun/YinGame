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

	PunchCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("PunchCollisionBox"));
    PunchCollisionBox->SetupAttachment(GetMesh(), FName("HammerCenter"));// Привязываем к мечу

	//PunchCollisionBox->SetCollisionProfileName(TEXT("Pawn"));
 //   PunchCollisionBox->SetGenerateOverlapEvents(false);

	PunchCollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	PunchCollisionBox->SetCollisionObjectType(ECollisionChannel::ECC_PhysicsBody);
	PunchCollisionBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);

	CurrentMontageIndex = 0;
	DamageInterval = 5.0f;
	OverlappingActor = nullptr;

}


void AYAICharacter::BeginPlay()
{
	Super::BeginPlay();
	PunchCollisionBox->OnComponentHit.AddDynamic(this, &ThisClass::HitPlayer);

}


void AYAICharacter::SetAnimMontages(TArray<UAnimMontage*> NewMontages)
{
	AnimMontages = NewMontages;
}


void AYAICharacter::HitPlayer(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{

 	 if (OtherActor != this)
    {
        OverlappingActor = OtherActor;
		//DoHit(OtherActor);
        UE_LOG(LogTemp, Warning, TEXT("Actor %s was hit!"), *OtherActor->GetName());
    }
}

void AYAICharacter::DoHit(AActor* OtherActor)
{

	if (AYCharacter* PlayerActor = Cast<AYCharacter>(OtherActor))
	{
		UYPlayerComponents* PlayerComp = PlayerActor->FindComponentByClass<UYPlayerComponents>();
		GetWorldTimerManager().SetTimer(DamageTimerHandle, this, &ThisClass::ApplyDamage, DamageInterval, true);
		//PlayerComp->ApplyHealthChange(HitPower);

	}

	
}

void AYAICharacter::ApplyDamage()
{
	if (OverlappingActor)
	{
		DoHit(OverlappingActor);
	}
	
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



