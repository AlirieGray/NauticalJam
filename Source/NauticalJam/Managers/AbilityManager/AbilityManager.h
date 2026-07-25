#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Managers/GameManagerBase.h"
#include "AbilityManager.generated.h"

UCLASS()
class NAUTICALJAM_API UAbilityManager : public UGameManagerBase
{
	GENERATED_BODY()
	
public:
	UAbilityManager();
	
	virtual void Initialize(UGameManagerSubsystem* InstanceOwner) override;
	
	UFUNCTION(BlueprintCallable)
	void ExecuteAbility(ABattlerBase* Caster, FAbility Ability, TArray<ABattlerBase*> Targets);
};
