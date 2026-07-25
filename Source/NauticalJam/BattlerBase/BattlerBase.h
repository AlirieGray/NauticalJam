#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameFramework/Character.h"
#include "Managers/GameManagerBase.h"
#include "Managers/AbilityQueueManager/AbilityQueueManager.h"
#include "Managers/ManaManager/ManaManager.h"
#include "Managers/EnemyManager/EnemyManager.h"
#include "BattlerBase.generated.h"

UCLASS()
class NAUTICALJAM_API ABattlerBase: public ACharacter
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Health;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MaxHealth;
	
	UFUNCTION()
	void DealDamage(float damage_dealt, const TArray<ABattlerBase*>& targets);
	
	UFUNCTION()
	void Heal(float amount_healed, const TArray<ABattlerBase*>& targets);
	
	UFUNCTION(BlueprintCallable)
	void ReceiveDamage(float damage_taken);
	
};
