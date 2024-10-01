#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "YAIController.generated.h"

class UBehaviorTree;

UCLASS()
class YINGAME_API AYAIController : public AAIController
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	UBehaviorTree* BehaviorTree;


	virtual void BeginPlay() override;
	
};
