#include "AI/YBTTask_ChooseLocationForPatrol.h"
#include "AIController.h"
#include "GameFramework/Character.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AI/YAICharacter.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"

#pragma optimize ("", off)
EBTNodeResult::Type UYBTTask_ChooseLocationForPatrol::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	
	UBlackboardComponent* BlackBoardComp = OwnerComp.GetBlackboardComponent();
	
	if(ensure(BlackBoardComp))
	{
		AAIController* MyController = OwnerComp.GetAIOwner();
		if(ensure(MyController))
		{
			AYAICharacter* MyPawn = Cast<AYAICharacter>(MyController->GetPawn());
			if (MyPawn == nullptr)
			{
				return EBTNodeResult::Failed;
			}

			UBoxComponent* PatrolLocation =  MyPawn->GetPatrolLocation();

			FVector BoxCenter = PatrolLocation->GetComponentLocation();
			FVector BoxExtent = PatrolLocation->GetScaledBoxExtent();

			FVector RandomLocation = UKismetMathLibrary::RandomPointInBoundingBox(BoxCenter, BoxExtent);

			BlackBoardComp->SetValueAsVector("MoveToLocation", RandomLocation);

			return EBTNodeResult::Succeeded;
		}

		return EBTNodeResult::Failed;

	}
	return EBTNodeResult::Failed;

}
#pragma optimize ("", on)