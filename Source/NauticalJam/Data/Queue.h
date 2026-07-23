#pragma once
#include "FAbility.h"

#include "Queue.generated.h"

USTRUCT(BlueprintType)
struct FQueue
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAbility> Abilities;
	
	FQueue()
	{
		Abilities = TArray<FAbility>{ };
	}
};
