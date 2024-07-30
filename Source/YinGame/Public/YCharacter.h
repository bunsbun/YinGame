// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "YCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UAnimMontage;


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

	//UPROPERTY(EditAnywhere, Category = "Attack")
	//UAnimMontage* AttackAnim;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
    TArray<UAnimMontage*> AnimMontages;

	// Текущий индекс анимации
    int32 CurrentMontageIndex;
	
	virtual void BeginPlay() override;

	UFUNCTION()
	void MoveForward(float Value);
	
	UFUNCTION()
	void MoveRight(float Value);

    UFUNCTION()
    void StartJump();
         
    UFUNCTION()
    void StopJump();

	// Функция для начала проигрывания анимаций
    UFUNCTION(BlueprintCallable, Category = "Attack")
    void PrimaryAttack();

	// Функция для установки массива анимаций
    UFUNCTION(BlueprintCallable, Category = "Attack")
    void SetAnimMontages(TArray<UAnimMontage*> NewMontages);

public:	
	
	virtual void Tick(float DeltaTime) override;

	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
