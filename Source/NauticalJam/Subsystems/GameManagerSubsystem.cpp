#include "GameManagerSubsystem.h"

#include "Managers/AbilityQueueManager/AbilityQueueManager.h"
#include "Managers/ManaManager/ManaManager.h"
#include "Managers/EnemyManager/EnemyManager.h"
#include "Managers/AbilityManager/AbilityManager.h"

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

template <typename T>
void UGameManagerSubsystem::RegisterManager()
{
	T* Manager = NewObject<T>(this);
	Managers.Add(T::StaticClass(), Manager);
}

void UGameManagerSubsystem::RegisterManagers()
{
	RegisterManager<UAbilityQueueManager>();
	RegisterManager<UManaManager>();
	RegisterManager<UEnemyManager>();
	RegisterManager<UAbilityManager>();
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

UEnemyManager* UGameManagerSubsystem::GetEnemyManager() const
{
	if (const TObjectPtr<UGameManagerBase>* Found = Managers.Find(UEnemyManager::StaticClass()))
	{
		return Cast<UEnemyManager>(Found->Get());
	}
	
	return nullptr;
}

UAbilityManager* UGameManagerSubsystem::GetAbilityManager() const
{
	if (const TObjectPtr<UGameManagerBase>* Found = Managers.Find(UEnemyManager::StaticClass()))
	{
		return Cast<UAbilityManager>(Found->Get());
	}
	
	return nullptr;
}
