#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Managers/GameManagerBase.h"
#include "EnemyManager.generated.h"

UCLASS()
class NAUTICALJAM_API UEnemyManager: public UGameManagerBase
{
	GENERATED_BODY()
	
public:
	UEnemyManager();
	
	virtual void Initialize(UGameManagerSubsystem* InstanceOwner) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxHealth;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CurrentHealth;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BaseDamage;
	
	UFUNCTION(BlueprintCallable)
	void TakeDamage(float Damage);
	
	UFUNCTION(BlueprintCallable)
	void Defeated();
	
	
};
