// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/FAbility.h"
#include "GameFramework/Actor.h"
#include "Managers/UGameManagerBase.h"
#include "AbilityQueueManager.generated.h"

UCLASS()
class NAUTICALJAM_API UAbilityQueueManager : public UGameManagerBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	TMap<FName, TArray<FAbility>> MagicalGirlQueues;
	
	UPROPERTY(BlueprintReadWrite)
	int MaxAbilitiesInQueue;
	
	virtual void Initialize(UGameManagerSubsystem* InstanceOwner) override;
	
	// returns true if ability was successfully added to queue, false otherwise
	UFUNCTION(BlueprintCallable)
	bool EnqueueAbility(FName MagicalGirl, FAbility Ability);
	
	// returns true if the ability was successfully executed and removed from the queue false otherwise. 
	UFUNCTION(BlueprintCallable)
	bool DequeueAndExecuteAbility(FName MagicalGirl, FAbility Ability);
};
