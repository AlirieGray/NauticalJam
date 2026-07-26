#pragma once

#include "CoreMinimal.h"
#include "Data/FDamageOverTime.h"
#include "GameFramework/Actor.h"
#include "Managers/GameManagerBase.h"
#include "AbilityManager.generated.h"

UCLASS()
class NAUTICALJAM_API UAbilityManager : public UGameManagerBase
{
	GENERATED_BODY()
	
	TMap<FGuid, FDamageOverTime> ActiveDamageOverTimes;
	TMap<FGuid, FTimerHandle> Timers;
	
	void DamageOverTimeTick(FGuid Id);
	
public:
	UAbilityManager();
	
	virtual void Initialize(UGameManagerSubsystem* InstanceOwner) override;
	
	UFUNCTION(BlueprintCallable)
	void ExecuteAbility(ABattlerBase* Caster, FAbility Ability, TArray<ABattlerBase*> Targets);
};
