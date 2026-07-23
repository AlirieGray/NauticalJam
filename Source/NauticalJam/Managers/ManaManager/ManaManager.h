#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Managers/GameManagerBase.h"
#include "ManaManager.generated.h"

UCLASS()
class NAUTICALJAM_API UManaManager : public UGameManagerBase
{
	GENERATED_BODY()
	
	UFUNCTION()
	void RegenerateMana();
	
public:
	UManaManager();
	
	virtual void Initialize(UGameManagerSubsystem* InstanceOwner) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxMana;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CurrentMana;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RegenerationAmount;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTimerHandle RegenerationTimer;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RegenerationInterval;
	
	UFUNCTION(BlueprintCallable)
	void AddMana(int amount);
	
	UFUNCTION(BlueprintCallable)
	void RemoveMana(int amount);
	
	UFUNCTION(BlueprintCallable)
	void SetMana(int amount);
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool HasMana(int amount);
	
	UFUNCTION(BlueprintCallable)
	void StartManaRegeneration();
	
	UFUNCTION(BlueprintCallable)
	void StopManaRegeneration();
	
	UFUNCTION(BlueprintCallable)
	void UpdateMaxManaAmount(int amount);
	
	UFUNCTION(BlueprintCallable)
	void UpdateRegenerationAmount(int amount);
	
	UFUNCTION(BlueprintCallable)
	void UpdateRegenerationInterval(float interval);
};
