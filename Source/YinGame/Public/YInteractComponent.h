// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "YInteractComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
//UActorComponent - ��� �������������. ����� ���� ����� ������� � ����������. ����� ������� ��������� ������ 
class YINGAME_API UYInteractComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	void PrimaryInteract();

public:	

	UYInteractComponent();

protected:
	
	virtual void BeginPlay() override;

public:	

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
