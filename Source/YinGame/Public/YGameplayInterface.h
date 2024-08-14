#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "YGameplayInterface.generated.h"


UINTERFACE(MinimalAPI)
class UYGameplayInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class YINGAME_API IYGameplayInterface
{
	GENERATED_BODY()

	
public:

	UFUNCTION(BlueprintNativeEvent)
	void Interact(APawn* InstigatorPawn);
};
