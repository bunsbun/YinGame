#include "YBottleHealth.h"
#include "YPlayerComponents.h"
#include "YCharacter.h"

FTransform AYBottleHealth::SpawnTransform = FTransform(FRotator(0.f, 0.f, 0.f), FVector(0.f, 0.f, 0.f), FVector(1.f, 1.f, 1.f));

AYBottleHealth::AYBottleHealth()
{

	PrimaryActorTick.bCanEverTick = true;

	MeshBottleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshBottleComponent"));
	MeshBottleComponent->GetRelativeTransform().SetLocation(SpawnTransform.GetLocation());
	RootComponent = MeshBottleComponent;
	 
	//MeshBottleComponent->SetSimulatePhysics(true);
	//MeshBottleComponent->SetVisibility(true);
}


void AYBottleHealth::BeginPlay()
{
	Super::BeginPlay();

	if(MeshBottleComponent)
	{
		SpawnTransform = MeshBottleComponent->GetComponentTransform();
		MeshBottleComponent->OnComponentHit.AddDynamic(this, &AYBottleHealth::OnHit);
	}

}

void AYBottleHealth::Interact_Implementation(APawn* InstigatorPawn)
{
	 UE_LOG(LogTemp, Log, TEXT("Interact_Implementation"));
}

void AYBottleHealth::SetState()
{
	if(MeshBottleComponent)
	{
		MeshBottleComponent->SetRelativeTransform(SpawnTransform);
	}
	
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

void AYBottleHealth::SpawnBottleHealth()
{
	if(MeshBottleComponent == nullptr)
	{
		//MeshBottleComponent = GetWorld()->SpawnActor<UStaticMeshComponent>(UStaticMeshComponent::StaticClass(), SpawnTransform);
	}
}

void AYBottleHealth::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AYBottleHealth::SetVisibilityBottle()
{
	MeshBottleComponent->SetVisibility(true, true);
}

