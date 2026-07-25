#include "BattlerBase.h"

ABattlerBase::ABattlerBase()
{
	MaxHealth = 100;
	Health = MaxHealth;
}

void ABattlerBase::Heal(float Amount, ABattlerBase* Causer)
{
	Health = FMath::Clamp(Health + Amount, 0, MaxHealth);
	return;
}

void ABattlerBase::TakeDamage(float Damage, ABattlerBase* Causer)
{
	Health = FMath::Clamp(Health - Damage, 0, MaxHealth);
	return;
}

void ABattlerBase::OnDeath_Implementation()
{
	return;
}
