// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "YCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UAnimMontage;
class UYInteractComponent;
class UYPlayerComponents;


UCLASS()
class YINGAME_API AYCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	
	AYCharacter();

protected:

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
    TArray<UAnimMontage*> AnimMontages;

	// ������� ������ ��������
    int32 CurrentMontageIndex;

	// �������� ��� ����������� ������
    UPROPERTY(VisibleAnywhere, Category = "Combat")
    class UBoxComponent* PunchCollisionBox;

	// ���������� ��� �������� �����
    UPROPERTY(EditDefaultsOnly, Category = "Combat")
    float PunchDamage;

	UPROPERTY(VisibleAnywhere)
	UYInteractComponent* InteractionComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UYPlayerComponents* PlayerComponent;


protected:
	
	UFUNCTION()
	void MoveForward(float Value);
	
	UFUNCTION()
	void MoveRight(float Value);

    UFUNCTION()
    void StartJump();
         
    UFUNCTION()
    void StopJump();

	// ������� ��� ������ ������������ ��������
    UFUNCTION(BlueprintCallable, Category = "Attack")
    void PrimaryAttack();

	// ������� ��� ��������� ������� ��������
    UFUNCTION(BlueprintCallable, Category = "Attack")
    void SetAnimMontages(TArray<UAnimMontage*> NewMontages);

	void PrimaryInteract();

	UFUNCTION()
	void OnTakeAnyDamageHandle(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

	UFUNCTION(BlueprintCallable, Category = "Teleport")
    void TeleportToSelectedActor(AActor* SelectedActor);

	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
