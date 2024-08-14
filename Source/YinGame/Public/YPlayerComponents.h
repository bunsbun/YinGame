#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "YPlayerComponents.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChanged, float, NewHealth);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class YINGAME_API UYPlayerComponents : public UActorComponent
{
	GENERATED_BODY()

public:	

	UYPlayerComponents();

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	void ApplyHealthChange(float Damage);

protected:

	virtual void BeginPlay() override;

protected:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes")
	float Health;

	// HealthMax, Stamina, Strength
	
	//BlueprintAssignable - можно использовать в блюпринтах
	UPROPERTY(BlueprintAssignable)
	FOnHealthChanged OnHealthChanged;



public:	


	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
