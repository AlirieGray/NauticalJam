#pragma once

#include "FAbility.generated.h"

UENUM(Blueprintable)
enum class EAbility : uint8
{
	BasicAttack UMETA(DisplayName = "Basic Attack"),
	BasicHeal UMETA(DisplayName = "Basic Heal"),
	BlessingOfLight UMETA(DisplayName = "Blessing of Light"),
	SpiritZap UMETA(DisplayName = "Spirit Zap"),
};

USTRUCT(BlueprintType)
struct FAbility : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EAbility Name;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ManaCost;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UTexture2D> Icon;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DamageBurst;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DamageOverTimeAmount;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DamageOverTimeDuration;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HealBurst;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HealOverTimeAmount;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HealOverTimeDuration;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FName, float> AppliedEffects;
	
	FAbility()
	{
		Name = EAbility::BasicAttack;
		Icon = nullptr;
		ManaCost = 0;
		DamageBurst = 0;
		DamageOverTimeAmount = 0;
		DamageOverTimeDuration = 0;
		HealBurst = 0;
		HealOverTimeAmount = 0;
		HealOverTimeDuration = 0;
		AppliedEffects = TMap<FName, float> ();
	}
	
	FAbility(EAbility name, int manaCost, TSoftObjectPtr<UTexture2D> iconRef, float damageBurst, float dotAmount, float dotDuration, float healBurst, float hotAmount, float hotDuration, TMap<FName, float> appliedEffects)
	{
		Name = name;
		ManaCost = manaCost;
		Icon = iconRef;
		DamageBurst = damageBurst;
		DamageOverTimeAmount = dotAmount;
		DamageOverTimeDuration = dotDuration;
		HealBurst = healBurst;
		HealOverTimeAmount = hotAmount;
		HealOverTimeDuration = hotDuration;
		AppliedEffects = appliedEffects;
	}
};
