#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/WidgetComponent.h"
#include "YPlayerComponents.h"
#include "YAICharacter.generated.h"


class UBoxComponent;
class UAnimMontage;
class UYPlayerComponents;

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

	// ������� ������ ��������
    int32 CurrentMontageIndex;

	UPROPERTY()
    AActor* OverlappingActor;

	UPROPERTY()
    FTimerHandle DamageTimerHandle;

	// ������� ��������� ����� (� ��������)
	UPROPERTY()
    float DamageInterval;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Health")
    UWidgetComponent* HealthWidgetComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UYPlayerComponents* PlayerComponent;

	UPROPERTY(VisibleAnywhere)
	int32 Health;

	// ������� ��� ��������� ������� ��������
    UFUNCTION(BlueprintCallable, Category = "Attack")
    void SetAnimMontages(TArray<UAnimMontage*> NewMontages);

	UFUNCTION()
	void HitPlayer (UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
		FVector NormalImpulse, const FHitResult& Hit);

	//UFUNCTION()
	//void DoHit(AActor* OtherActor);

	//UFUNCTION()
	//void ApplyDamage();

	UFUNCTION()
	void HitCharacter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


	UFUNCTION()
	void ApplyHealthChanged(float NewHealth);



public:
	// ������� ��� ������ ������������ ��������
    UFUNCTION(BlueprintCallable, Category = "Attack")
    void PrimaryAttack();

public:	
	
	virtual void Tick(float DeltaTime) override;


};
