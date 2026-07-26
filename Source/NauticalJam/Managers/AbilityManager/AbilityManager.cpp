#include "AbilityManager.h"

#include "BattlerBase/BattlerBase.h"
#include "Data/FAbility.h"
#include "Data/FDamageOverTime.h"

UAbilityManager::UAbilityManager()
{
	Timers = TMap<FGuid, FTimerHandle>();
}

void UAbilityManager::Initialize(UGameManagerSubsystem* InstanceOwner)
{
	Super::Initialize(InstanceOwner);
}

void UAbilityManager::DamageOverTimeTick(FGuid Id)
{
	FDamageOverTime* DamageOverTime = ActiveDamageOverTimes.Find(Id);
	
	if (DamageOverTime->Damage > 0)
	{
		DamageOverTime->Owner->TakeDamage(DamageOverTime->Damage, DamageOverTime->Causer);
	} else
	{
		DamageOverTime->Owner->Heal(-DamageOverTime->Damage, DamageOverTime->Causer);
	}
	
	DamageOverTime->Duration -= DamageOverTime->TickRate;
	if (DamageOverTime->Duration <= 0.0f)
	{
		GetWorld()->GetTimerManager().ClearTimer(Timers[Id]);
		Timers.Remove(Id);
		ActiveDamageOverTimes.Remove(Id);
	}
}

void UAbilityManager::ExecuteAbility(ABattlerBase* Caster, FAbility Ability, TArray<ABattlerBase*> Targets)
{
	FTimerManager& TimerManager = GetWorld()->GetTimerManager();
	
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
			FGuid Id = FGuid::NewGuid();
			
			FDamageOverTime DamageOverTime = FDamageOverTime(
				Caster,
				Target,
				Ability.DamageOverTimeAmount,
				Ability.DamageOverTimeDuration,
				1.0f
			);
			
			ActiveDamageOverTimes.Add(Id, DamageOverTime);
			FTimerDelegate Delegate;
			Delegate.BindUObject(this, &UAbilityManager::DamageOverTimeTick, Id);
			
			TimerManager.SetTimer(
				Timers.FindOrAdd(Id),
				Delegate,
				DamageOverTime.TickRate,
				true
			);
			
		}
		
		// Heal Burst
		if (Ability.HealBurst > 0)
		{
			Target->Heal(Ability.HealBurst, Caster);
		}
		
		// Heal Over Time
		if (Ability.HealOverTimeAmount > 0)
		{
			FGuid Id = FGuid::NewGuid();
			
			FDamageOverTime DamageOverTime = FDamageOverTime(
				Caster,
				Target,
				-Ability.HealOverTimeAmount,
				Ability.HealOverTimeDuration,
				1.0f
			);
			
			ActiveDamageOverTimes.Add(Id, DamageOverTime);
			FTimerDelegate Delegate;
			Delegate.BindUObject(this, &UAbilityManager::DamageOverTimeTick, Id);
			
			TimerManager.SetTimer(
				Timers.FindOrAdd(Id),
				Delegate,
				DamageOverTime.TickRate,
				true
			);
		}
		
		// Applied Effects
		for (auto [EffectName, Chance] : Ability.AppliedEffects)
		{
			// roll a random between 0-1, if <= Chance, apply EffectName
		}
		
	}
	
	
}
