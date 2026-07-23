#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Managers/UGameManagerBase.h"
#include "ManaManager.generated.h"

UCLASS()
class NAUTICALJAM_API UManaManager : public UGameManagerBase
{
	GENERATED_BODY()
	
	virtual void Initialize(UGameManagerSubsystem* InstanceOwner) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxMana;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CurrentMana;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RegenerationAmount;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RegenerationInterval;
	
	UFUNCTION(BlueprintNativeEvent)
	void SpendMana(int amount);
	
	UFUNCTION(BlueprintNativeEvent)
	void RegenerateMana(int amount);
	
	UFUNCTION(BlueprintNativeEvent)
	void UpdateMaxManaAmount(int amount);
};
