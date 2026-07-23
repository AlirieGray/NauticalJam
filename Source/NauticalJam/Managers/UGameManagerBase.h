#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Subsystems/UGameManagerSubsystem.h"
#include "UGameManagerBase.generated.h"

/**
 * 
 */
UCLASS(Abstract, BlueprintType, Blueprintable)
class NAUTICALJAM_API UGameManagerBase : public UObject
{
	GENERATED_BODY()

	
public:
	UPROPERTY()
	TObjectPtr<UGameManagerSubsystem> Owner;
	
	virtual void Initialize(UGameManagerSubsystem* InstanceOwner);
	
	virtual void Shutdown();
	
	virtual void PostInitialize();
};
