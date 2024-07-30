// Fill out your copyright notice in the Description page of Project Settings.


#include "YCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Animation/AnimInstance.h"

AYCharacter::AYCharacter()
{
 	
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->bUsePawnControlRotation = true;

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);

	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationYaw = true;

	 CurrentMontageIndex = 0;

}

void AYCharacter::SetAnimMontages(TArray<UAnimMontage*> NewMontages)
{
	 AnimMontages = NewMontages;
}

void AYCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AYCharacter::MoveForward(float Value)
{
	// Find out which way is "forward" and record that the player wants to move that way.
	//Выясните, какой путь является "прямым", и запишите, что игрок хочет двигаться в этом направлении
    FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
    AddMovementInput(Direction, Value);

}

void AYCharacter::MoveRight(float Value)
{
	// Find out which way is "right" and record that the player wants to move that way.
    FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
    AddMovementInput(Direction, Value);

	// X = Forward (Red)
	// Y = Right (Green)
	// Z = Up (Blue)
}

void AYCharacter::StartJump()
{
	bPressedJump = true;
}

void AYCharacter::StopJump()
{
	 bPressedJump = false;
}

void AYCharacter::PrimaryAttack()
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


void AYCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AYCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AYCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AYCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AYCharacter::StartJump);
    PlayerInputComponent->BindAction("Jump", IE_Released, this, &AYCharacter::StopJump);

	PlayerInputComponent->BindAction("PrimaryAttack", IE_Released, this, &AYCharacter::PrimaryAttack);

}

