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

	UFUNCTION(BlueprintCallable)
	bool IsAlive() const;

	UFUNCTION()
	const float GetHealthPlayer() const { return Health;}

	//BlueprintAssignable - можно использовать в блюпринтах
	UPROPERTY(BlueprintAssignable)
	FOnHealthChanged OnHealthChanged;

protected:

	virtual void BeginPlay() override;

protected:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes")
	float Health;

	UPROPERTY()
	float NowHealth;

	// HealthMax, Stamina, Strength
	




public:	


	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
