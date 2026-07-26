#include "BattlerBase.h"

ABattlerBase::ABattlerBase()
{
	MaxHealth = 100;
	Health = MaxHealth;
}

void ABattlerBase::Heal(float Amount, ABattlerBase* Causer)
{
	float PreviousHealth = Health;
	Health = FMath::Clamp(Health + Amount, 0, MaxHealth);
	
	this->OnHealed(Health - PreviousHealth);
	return;
}

void ABattlerBase::TakeDamage(float Damage, ABattlerBase* Causer)
{
	float PreviousHealth = Health;
	Health = FMath::Clamp(Health - Damage, 0, MaxHealth);
	
	this->OnDamageTaken(PreviousHealth - Health);
	return;
}

void ABattlerBase::OnDamageTaken_Implementation(float Delta)
{
	return;
}

void ABattlerBase::OnHealed_Implementation(float Delta)
{
	return;
}

void ABattlerBase::OnDeath_Implementation()
{
	return;
}
