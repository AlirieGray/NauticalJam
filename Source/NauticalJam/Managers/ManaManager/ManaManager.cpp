#include "ManaManager.h"


UManaManager::UManaManager() { }

void UManaManager::Initialize(UGameManagerSubsystem* InstanceOwner)
{
	Super::Initialize(InstanceOwner);
}

void UManaManager::SpendMana_Implementation(int amount) { }

void UManaManager::RegenerateMana_Implementation() { }

void UManaManager::UpdateMaxManaAmount_Implementation(int amount) { }
