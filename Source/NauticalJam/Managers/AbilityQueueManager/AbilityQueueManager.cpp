#include "AbilityQueueManager.h"
#include "Managers/ManaManager/ManaManager.h"
#include "Subsystems/GameManagerSubsystem.h"

UAbilityQueueManager::UAbilityQueueManager()
{
	MaxAbilitiesInQueue = 3;
	MagicalGirlQueues.Add("Joan", FQueue());
	MagicalGirlQueues.Add("Cassandra", FQueue());
	MagicalGirlQueues.Add("Verity", FQueue());
}

void UAbilityQueueManager::Initialize(UGameManagerSubsystem* InstanceOwner)
{
	Super::Initialize(InstanceOwner);
}

bool UAbilityQueueManager::EnqueueAbility(FName MagicalGirl, FAbility Ability)
{
	if (MagicalGirlQueues[MagicalGirl].Abilities.Num() >= MaxAbilitiesInQueue)
	{
		return false;
	}
	
	MagicalGirlQueues[MagicalGirl].Abilities.Add(Ability);
	return true;
}

FAbility UAbilityQueueManager::DequeueAbility(FName MagicalGirl, bool&bOutSuccess)
{
	
	if (MagicalGirlQueues[MagicalGirl].Abilities.Num() == 0)
	{
		bOutSuccess = false;
		return FAbility();
	}
	
	FAbility ability = MagicalGirlQueues[MagicalGirl].Abilities[0];
	
	// ask mana manager if we have enough mana to spend on this ability
	UManaManager* manaManager = GetWorld()->GetGameInstance()->GetSubsystem<UGameManagerSubsystem>()->GetManaManager();
	if (!manaManager)
	{
		bOutSuccess = false;
		return FAbility();
	}
	
	if (manaManager->HasMana(ability.ManaCost))
	{
		MagicalGirlQueues[MagicalGirl].Abilities.RemoveAt(0);
		bOutSuccess = true;
		return ability;
	}
	
	bOutSuccess = false;
	return FAbility();
}
