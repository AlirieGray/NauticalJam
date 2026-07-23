#pragma once

#include "CoreMinimal.h"
#include "Managers/UGameManagerBase.h"
#include "UObject/Object.h"
#include "UGameManagerSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class NAUTICALJAM_API UGameManagerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	
	template<typename T>
	T* GetManager();
	
	// For blueprints and when the type needs to be inferred at runtime
	UFUNCTION(BlueprintCallable, Category = "Managers", meta = (DeterminesOutputType = "ManagerClass"))
	UGameManagerBase* GetManagerByClass(TSubclassOf<UGameManagerBase> ManagerClass);
	
	// Stricter type safety for C++ for getting a manager from the list of managers
	UGameManagerBase* GetManager(TSubclassOf<UGameManagerBase> ManagerClass) const;
	
protected:
	virtual void RegisterManagers();
	
	template<typename T>
	void RegisterManager();
	
private:
	// Map for access to managers
	UPROPERTY(EditDefaultsOnly, Category = "GameManager")
	TMap<TSubclassOf<UGameManagerBase>, TObjectPtr<UGameManagerBase>> Managers;
	
};
