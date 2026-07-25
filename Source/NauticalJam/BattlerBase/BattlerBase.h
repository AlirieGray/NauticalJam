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
	ABattlerBase();
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Health;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MaxHealth;
	
	UFUNCTION()
	void Heal(float Amount, ABattlerBase* Causer);
	
	UFUNCTION(BlueprintCallable)
	void TakeDamage(float Damage, ABattlerBase* Causer);
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnDeath();
};
