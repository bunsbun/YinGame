// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/YBTTask_HitPlayer.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "AI/YAICharacter.h"

EBTNodeResult::Type UYBTTask_HitPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackBoardComp = OwnerComp.GetBlackboardComponent();
	
	if(ensure(BlackBoardComp))
	{
		AAIController* MyController = OwnerComp.GetAIOwner();
		if(ensure(MyController))
		{
			AYAICharacter* MyPawn = Cast<AYAICharacter>(MyController->GetPawn());
			MyPawn->PrimaryAttack();
			return EBTNodeResult::Succeeded;

		}
		return EBTNodeResult::Failed;
	}

	return EBTNodeResult::Failed;
}
