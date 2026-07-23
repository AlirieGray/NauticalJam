#pragma once

#include "CoreMinimal.h"
#include "Managers/UGameManagerBase.h"
#include "Managers/AbilityQueueManager/AbilityQueueManager.h"
#include "Managers/ManaManager/ManaManager.h"
#include "UObject/Object.h"
#include "UGameManagerSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class NAUTICALJAM_API UGameManagerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	
	template<typename T>
	T* GetManager();
	
	// For blueprints and when the type needs to be inferred at runtime
	UFUNCTION(BlueprintCallable, Category = "Managers", meta = (DeterminesOutputType = "ManagerClass"))
	UGameManagerBase* GetManagerByClass(TSubclassOf<UGameManagerBase> ManagerClass);
	
	// Stricter type safety for C++ for getting a manager from the list of managers
	UGameManagerBase* GetManager(TSubclassOf<UGameManagerBase> ManagerClass) const;
	
	UFUNCTION(BlueprintCallable, Category = "Managers")
	UManaManager* GetManaManager() const;
	
	UFUNCTION(BlueprintCallable, Category = "Managers")
	UAbilityQueueManager* GetAbilityQueueManager() const;
	
protected:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	
	virtual void RegisterManagers();
	
	template<typename T>
	void RegisterManager();
	
	
private:
	// Map for access to managers
	UPROPERTY(EditDefaultsOnly, Category = "GameManager")
	TMap<TSubclassOf<UGameManagerBase>, TObjectPtr<UGameManagerBase>> Managers;
	
};
