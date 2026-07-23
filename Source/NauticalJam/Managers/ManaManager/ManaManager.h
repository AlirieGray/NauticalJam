#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Managers/GameManagerBase.h"
#include "ManaManager.generated.h"

UCLASS()
class NAUTICALJAM_API UManaManager : public UGameManagerBase
{
	GENERATED_BODY()
	
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
	float RegenerationInterval;
	
	UFUNCTION(BlueprintNativeEvent)
	void SpendMana(int amount);
	
	UFUNCTION(BlueprintNativeEvent)
	void RegenerateMana();
	
	UFUNCTION(BlueprintNativeEvent)
	void UpdateMaxManaAmount(int amount);
};
