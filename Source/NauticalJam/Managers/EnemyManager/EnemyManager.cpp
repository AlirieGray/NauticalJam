#include "EnemyManager.h"

UEnemyManager::UEnemyManager()
{
	MaxHealth = 1000;
	CurrentHealth = MaxHealth;
	BaseDamage = 10;
}

void UEnemyManager::Initialize(UGameManagerSubsystem* InstanceOwner)
{
	Super::Initialize(InstanceOwner);
}

void UEnemyManager::TakeDamage(float Damage)
{
	CurrentHealth -= Damage;
	if (CurrentHealth <= 0)
	{
		Defeated();	
	}
}

void UEnemyManager::Defeated()
{
	
}
