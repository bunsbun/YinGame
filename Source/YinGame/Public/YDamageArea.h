#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "YDamageArea.generated.h"

class UBoxComponent;

UCLASS()
class YINGAME_API AYDamageArea : public AActor
{
	GENERATED_BODY()
	
public:	

	AYDamageArea();

	
protected:
	
	virtual void BeginPlay() override;

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBoxComponent* DamageAreaComponent;

	UPROPERTY()
	float Damage;

	// Таймер для нанесения урона
	UPROPERTY()
    FTimerHandle DamageTimerHandle;

    // Частота нанесения урона (в секундах)
	UPROPERTY()
    float DamageInterval;

	UPROPERTY()
    AActor* OverlappingActor;

public:	

	virtual void Tick(float DeltaTime) override;

private:

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
    void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
    void ApplyContinuousDamage();
};
