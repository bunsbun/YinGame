#include "YBottleHealth.h"
#include "YPlayerComponents.h"
#include "YCharacter.h"



AYBottleHealth::AYBottleHealth()
{

	PrimaryActorTick.bCanEverTick = true;

	MeshBottleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshBottleComponent"));
	RootComponent = MeshBottleComponent;

}


void AYBottleHealth::BeginPlay()
{
	Super::BeginPlay();

	if(MeshBottleComponent)
	{
		MeshBottleComponent->OnComponentHit.AddDynamic(this, &AYBottleHealth::OnHit);
	}

}

void AYBottleHealth::Interact_Implementation(APawn* InstigatorPawn)
{
	 UE_LOG(LogTemp, Log, TEXT("Interact_Implementation"));
}


void AYBottleHealth::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//¬место создани€ нового экземпл€ра UYPlayerComponents в AYHealthMachine, 
	//вы должны найти и использовать существующий компонент, который принадлежит AYCharacter
	AYCharacter* Character = GetWorld()->GetFirstPlayerController()->GetPawn<AYCharacter>();
	if (Character)
	{
		UYPlayerComponents* PlayerComp = Character->FindComponentByClass<UYPlayerComponents>();

		if (PlayerComp)
		{
			PlayerComp->ApplyHealthChange(-10.0f);
			MeshBottleComponent->SetVisibility(false,true);
			MeshBottleComponent->SetWorldLocation(Character->GetActorLocation() + (0.0f, 0.0f, -100.0f));
			//Destroy();
		}
	}
}


void AYBottleHealth::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


