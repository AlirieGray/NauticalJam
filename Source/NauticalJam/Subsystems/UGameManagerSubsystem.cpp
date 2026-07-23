#include "UGameManagerSubsystem.h"

#include "Managers/AbilityQueueManager/AbilityQueueManager.h"
#include "Managers/ManaManager/ManaManager.h"

void UGameManagerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	
	RegisterManagers();
	
	for (auto& Pair : Managers)
	{
		Pair.Value->Initialize(this);
	}
}

void UGameManagerSubsystem::Deinitialize()
{
	for (auto& Pair : Managers)
	{
		Pair.Value->Shutdown();
	}
	
	Managers.Empty();
	
	Super::Deinitialize();
}

template <typename T>
T* UGameManagerSubsystem::GetManager()
{
	if (T* Manager = Cast<T>(UGameManagerBase::StaticClass()))
	{
		return Manager;
	}
	return nullptr;
}

UGameManagerBase* UGameManagerSubsystem::GetManagerByClass(TSubclassOf<UGameManagerBase> ManagerClass)
{
	UGameManagerBase* Manager = Managers.FindRef(ManagerClass);
	
	return Manager;
}

void UGameManagerSubsystem::RegisterManagers()
{
	RegisterManager<UAbilityQueueManager>();
	RegisterManager<UManaManager>();
}

UManaManager* UGameManagerSubsystem::GetManaManager() const
{
	if (const TObjectPtr<UGameManagerBase>* Found = Managers.Find(UManaManager::StaticClass()))
	{
		return Cast<UManaManager>(Found->Get());
	}
	
	return nullptr;
}

UAbilityQueueManager* UGameManagerSubsystem::GetAbilityQueueManager() const
{
	if (const TObjectPtr<UGameManagerBase>* Found = Managers.Find(UAbilityQueueManager::StaticClass()))
	{
		return Cast<UAbilityQueueManager>(Found->Get());
	}
	
	return nullptr;
}