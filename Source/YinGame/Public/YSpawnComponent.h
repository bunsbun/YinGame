#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "YSpawnComponent.generated.h"



class AYBottleHealth;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class YINGAME_API UYSpawnComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UYSpawnComponent();

	UFUNCTION()
	void SpawnBottleHealth(FVector& BoxCenter, FVector& BoxExtent);

protected:
	
	virtual void BeginPlay() override;

	UPROPERTY()
    AYBottleHealth* CurrentBottleHealth;

public:	

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
