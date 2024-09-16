// Fill out your copyright notice in the Description page of Project Settings.


#include "YCharacter.h"
#include "Components/BoxComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "YPlayerComponents.h"
#include "Camera/CameraComponent.h"
#include "Engine/DamageEvents.h"
#include "YInteractComponent.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Animation/AnimInstance.h"

DEFINE_LOG_CATEGORY_STATIC(AYCharacterLog, All, All);

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


	PunchCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("PunchCollisionBox"));
    PunchCollisionBox->SetupAttachment(GetMesh(), FName("whip_04"));// Привязываем к мечу

	PunchCollisionBox->SetCollisionProfileName(TEXT("Pawn"));
    PunchCollisionBox->SetGenerateOverlapEvents(false);
	 
    PunchDamage = 20.0f; // Устанавливаем значение урона

	InteractionComponent = CreateDefaultSubobject<UYInteractComponent>("InteractionComp");

	PlayerComponent = CreateDefaultSubobject<UYPlayerComponents>("PlayerComponent");
}

void AYCharacter::BeginPlay()
{
	Super::BeginPlay();


	check(PlayerComponent);

	OnTakeAnyDamage.AddDynamic(this, &AYCharacter::OnTakeAnyDamageHandle);
	
}

void AYCharacter::SetAnimMontages(TArray<UAnimMontage*> NewMontages)
{
	 AnimMontages = NewMontages;
}

void AYCharacter::PrimaryInteract()
{
	if (InteractionComponent)
	{
		InteractionComponent->PrimaryInteract();
	}
}
#pragma optimize ("", off)
void AYCharacter::OnTakeAnyDamageHandle(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	PlayerComponent->ApplyHealthChange(Damage);
	
	if(PlayerComponent->GetHealthPlayer() == 0.0f)
	{
		APlayerController* PC = Cast<APlayerController>(GetController());
		DisableInput(PC);
	}
}
void AYCharacter::TeleportToSelectedActor(AActor* SelectedActor)
{
	if (SelectedActor)
    {
        FVector TargetLocation = SelectedActor->GetActorLocation();

        // Перемещаемся на позицию объекта с небольшой высотой для корректного расположения над землей
        SetActorLocation(TargetLocation + FVector(0.f, 0.f, 50.f));
    }
}
#pragma optimize ("", on)

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

	//TakeDamage(0.1f, FDamageEvent{}, Controller, this);

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
	
	PlayerInputComponent->BindAction("Interact", IE_Released, this, &AYCharacter::PrimaryInteract);



}

