#pragma once
#include "FAbility.h"

#include "FMagicalGirlStats.generated.h"

USTRUCT(BlueprintType)
struct FMagicalGirlStats : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxHealth;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Sleuth;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Clairvoyance;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Strength;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Evasion;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Attack;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAbility> Abilities;
	
	FMagicalGirlStats()
	{
		MaxHealth = 100;
		Sleuth = 0;
		Clairvoyance = 0;
		Strength = 0;
		Evasion = 0;
		Attack = 0;
	}
	
	FMagicalGirlStats(float maxHealth, float sleuth, float clairvoyance, float strength, float evasion, float attack)
	{
		MaxHealth = maxHealth;
		Sleuth = sleuth;
		Clairvoyance = 0;
		Strength = strength;
		Evasion = evasion;
		Attack = attack;
	}
};
