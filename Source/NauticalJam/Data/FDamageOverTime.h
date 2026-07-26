#pragma once


#include "BattlerBase/BattlerBase.h"
#include "FDamageOverTime.generated.h"

USTRUCT(BlueprintType)
struct FDamageOverTime : public FTableRowBase
{
	GENERATED_BODY()
	
	ABattlerBase* Causer;
	ABattlerBase* Owner;
	
	float Damage;
	float Duration;
	float TickRate;
	
	FDamageOverTime()
	{
		Causer = nullptr;
		Owner = nullptr;
		Damage = 0.0f;
		Duration = 0.0f;
		TickRate = 0.0f;
	}
	
	FDamageOverTime(ABattlerBase* Causer, ABattlerBase* Owner, float Damage, float Duration, float TickRate)
	{
		this->Causer = Causer;
		this->Owner = Owner;
		this->Damage = Damage;
		this->Duration = Duration;
		this->TickRate = TickRate;
	}
};
