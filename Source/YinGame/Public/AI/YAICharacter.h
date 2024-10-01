#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "YAICharacter.generated.h"


class UBoxComponent;
class UAnimMontage;

UCLASS()
class YINGAME_API AYAICharacter : public ACharacter
{
	GENERATED_BODY()

public:
	
	AYAICharacter();

	UBoxComponent* GetPatrolLocation() { return PatrolLocation;}

	const uint32 HitPower = 10.0f;

protected:
	
	virtual void BeginPlay() override;


	UPROPERTY(VisibleAnywhere)
    UBoxComponent* PatrolLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
    TArray<UAnimMontage*> AnimMontages;

	// Текущий индекс анимации
    int32 CurrentMontageIndex;

	// Коллизия для обнаружения ударов
    UPROPERTY(VisibleAnywhere, Category = "Combat")
    class UBoxComponent* PunchCollisionBox;

	UPROPERTY()
    AActor* OverlappingActor;

	UPROPERTY()
    FTimerHandle DamageTimerHandle;

	// Частота нанесения урона (в секундах)
	UPROPERTY()
    float DamageInterval;

	// Функция для установки массива анимаций
    UFUNCTION(BlueprintCallable, Category = "Attack")
    void SetAnimMontages(TArray<UAnimMontage*> NewMontages);

	UFUNCTION()
	void HitPlayer (UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
		FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
	void DoHit(AActor* OtherActor);

	UFUNCTION()
	void ApplyDamage();

public:
	// Функция для начала проигрывания анимаций
    UFUNCTION(BlueprintCallable, Category = "Attack")
    void PrimaryAttack();

public:	
	
	virtual void Tick(float DeltaTime) override;


};
