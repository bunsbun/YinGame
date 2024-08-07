// Fill out your copyright notice in the Description page of Project Settings.


#include "YHitMesh.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
AYHitMesh::AYHitMesh()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    MeshComponent->SetSimulatePhysics(true);
    RootComponent = MeshComponent;

    ForceComponent = CreateDefaultSubobject<URadialForceComponent>("ForceComponent");
	ForceComponent->SetupAttachment(MeshComponent);

	// Leaving this on applies small constant force via component 'tick' (Optional)
	ForceComponent->SetAutoActivate(false);

	ForceComponent->Radius = 750.0f;
	ForceComponent->ImpulseStrength = 2500.0f; // Alternative: 200000.0 if bImpulseVelChange = false
	// Optional, ignores 'Mass' of other objects (if false, the impulse strength will be much higher to push most objects depending on Mass)
	ForceComponent->bImpulseVelChange = true;

	// Optional, default constructor of component already adds 4 object types to affect, excluding WorldDynamic
	ForceComponent->AddCollisionChannelToAffect(ECC_WorldDynamic);



}

void AYHitMesh::OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	ForceComponent->FireImpulse();
    UE_LOG(LogTemp, Log, TEXT("OnActorHit reached (AYHitMesh)"));

}

void AYHitMesh::BeginPlay()
{
	Super::BeginPlay();

    //Подписка на событие OnActorBeginOverlap
   MeshComponent->OnComponentHit.AddDynamic(this, &AYHitMesh::OnActorHit);
    
}


// Called every frame
void AYHitMesh::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

