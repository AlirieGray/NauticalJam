#include "AbilityQueueManager.h"

UAbilityQueueManager::UAbilityQueueManager()
{
}

void UAbilityQueueManager::Initialize(UGameManagerSubsystem* InstanceOwner)
{
	Super::Initialize(InstanceOwner);
}

bool UAbilityQueueManager::EnqueueAbility(FName MagicalGirl, FAbility Ability)
{
	return true;
}

bool UAbilityQueueManager::DequeueAndExecuteAbility(FName MagicalGirl, FAbility Ability)
{
	// ask mana manager if we have enough mana to spend on this ability
	UManaManager* manaManager = GetWorld()->GetGameInstance()->GetSubsystem<UGameManagerSubsystem>()->GetManaManager();
	if (!manaManager)
	{
		return false;
	}
	
	if (manaManager->CurrentMana < Ability.ManaCost)
	{
		return false;
	}
	
	return true;
	
}
