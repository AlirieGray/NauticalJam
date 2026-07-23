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
	
	UFUNCTION(BlueprintCallable)
	void EnqueueAbility(FName MagicalGirl, FAbility Ability);
	
	UFUNCTION(BlueprintCallable)
	void DequeueAbility(FName MagicalGirl, FAbility Ability);
};
