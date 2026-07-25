#include "AbilityManager.h"

#include "BattlerBase/BattlerBase.h"
#include "Data/FAbility.h"


UAbilityManager::UAbilityManager()
{
	
}

void UAbilityManager::Initialize(UGameManagerSubsystem* InstanceOwner)
{
	Super::Initialize(InstanceOwner);
}

void UAbilityManager::ExecuteAbility(ABattlerBase* Caster, FAbility Ability, TArray<ABattlerBase*> Targets)
{
	// Apply Ability Effects to all Targets
	for (ABattlerBase* Target : Targets)
	{
		// Damage Burst
		if (Ability.DamageBurst > 0)
		{
			Target->TakeDamage(Ability.DamageBurst, Caster);
		}
		
		//Damage Over Time
		if (Ability.DamageOverTimeAmount > 0)
		{
			
		}
		
		// Heal Burst
		if (Ability.HealBurst > 0)
		{
			Target->Heal(Ability.HealBurst, Caster);
		}
		
		// Heal Over Time
		if (Ability.HealOverTimeAmount > 0)
		{
			
		}
		
		// Applied Effects
		for (auto [EffectName, Chance] : Ability.AppliedEffects)
		{
			// roll a random between 0-1, if <= Chance, apply EffectName
		}
		
	}
	
	
}
