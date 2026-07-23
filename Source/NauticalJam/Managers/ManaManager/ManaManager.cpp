#include "ManaManager.h"


UManaManager::UManaManager()
{
	MaxMana = 100;
	CurrentMana = MaxMana;
	RegenerationAmount = 1;
	RegenerationInterval = 0.5;
}

void UManaManager::Initialize(UGameManagerSubsystem* InstanceOwner)
{
	Super::Initialize(InstanceOwner);
}

/**
 * Adds n Mana to CurrentMana.
 * @param amount n
 */
void UManaManager::AddMana(int amount)
{
	CurrentMana = FMath::Clamp(CurrentMana + amount, 0, MaxMana);
}

/**
 * Subtracts n Mana from CurrentMana.
 * @param amount n
 */
void UManaManager::RemoveMana(int amount)
{
	CurrentMana = FMath::Clamp(CurrentMana - amount, 0, MaxMana);
}

/**
 * Sets CurrentMana to n.
 * @param amount n
 */
void UManaManager::SetMana(int amount)
{
	CurrentMana = FMath::Clamp(amount,  0,  MaxMana);
}

/**
 * Determines if CurrentMana >= n.
 * @param amount n
 * @return true if CurrentMana >= n, false otherwise 
 */
bool UManaManager::HasMana(int amount)
{
	return CurrentMana >= amount;
}

/**
 * Regenerates one tick of Mana
 */
void UManaManager::RegenerateMana()
{
	if (CurrentMana <  MaxMana)
	{
		AddMana(RegenerationAmount);
	}
}

/**
 * Starts Mana Regeneration.
 */
void UManaManager::StartManaRegeneration()
{
	FTimerManager& TimerManager = GetWorld()->GetTimerManager();
	
	TimerManager.SetTimer(
			RegenerationTimer,
			this,
			&UManaManager::RegenerateMana,
			RegenerationInterval,
			true
	);
}

/**
 * Stops Mana Regeneration.
 */
void UManaManager::StopManaRegeneration()
{
	FTimerManager& TimerManager = GetWorld()->GetTimerManager();
	TimerManager.ClearTimer(RegenerationTimer);
}

/**
 * Sets MaxMana to n.
 * @param amount n
 */
void UManaManager::UpdateMaxManaAmount(int amount)
{
	MaxMana = amount;
}

/**
 * Sets RegenerationAmount to n.
 * @param amount n
 */
void UManaManager::UpdateRegenerationAmount(int amount)
{
	RegenerationAmount = amount;
}

/**
 * Sets RegenerationInterval to n and restarts RegenerationTimer with the new interval.
 * @param interval n
 */
void UManaManager::UpdateRegenerationInterval(float interval)
{
	RegenerationInterval = interval;
	
	FTimerManager& TimerManager = GetWorld()->GetTimerManager();
	TimerManager.SetTimer(
			RegenerationTimer,
			this,
			&UManaManager::RegenerateMana,
			RegenerationInterval,
			true
	);
}
