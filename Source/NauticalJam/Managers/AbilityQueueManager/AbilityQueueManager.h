// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/FAbility.h"
#include "Data/Queue.h"
#include "GameFramework/Actor.h"
#include "Managers/GameManagerBase.h"
#include "AbilityQueueManager.generated.h"

UCLASS()
class NAUTICALJAM_API UAbilityQueueManager : public UGameManagerBase
{
	GENERATED_BODY()

public:
	UAbilityQueueManager();
	
	virtual void Initialize(UGameManagerSubsystem* InstanceOwner) override;
	
	// returns true if ability was successfully added to queue, false otherwise
	UFUNCTION(BlueprintNativeEvent)
	bool EnqueueAbility(FName MagicalGirl, FAbility Ability);
	
	// returns true if the ability was successfully executed and removed from the queue false otherwise. 
	UFUNCTION(BlueprintNativeEvent)
	bool DequeueAndExecuteAbility(FName MagicalGirl, FAbility Ability);

protected:
	UPROPERTY(BlueprintReadWrite)
	TMap<FName, FQueue> MagicalGirlQueues;
	
	// maximum number abilities that can be in a given Magical Girl's queue at one time
	int MaxAbilitiesInQueue;
};
