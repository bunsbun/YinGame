// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "YGameplayInterface.h"
#include "YBottleHealth.generated.h"

UCLASS()
class YINGAME_API AYBottleHealth : public AActor,  public IYGameplayInterface
{
	GENERATED_BODY()
	
public:	

	AYBottleHealth();

	UFUNCTION()
	void SetState();

protected:

	virtual void BeginPlay() override;

	UFUNCTION()
	void Interact_Implementation(APawn* InstigatorPawn);

	UFUNCTION(BlueprintCallable, Category = "Teleport")
	UStaticMeshComponent* GetMeshBottleComponent(AActor* SelectedActor){ return MeshBottleComponent;}

protected:


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UStaticMeshComponent* MeshBottleComponent;


public:	


	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void SetVisibilityBottle();

private:

	static FTransform SpawnTransform;

private:
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
	void SpawnBottleHealth();


};
