#include "UGameManagerSubsystem.h"

void UGameManagerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	
	RegisterManagers();
	
	for (auto& Pair : Managers)
	{
		Pair.Value->Initialize(this);
	}
}

void UGameManagerSubsystem::Deinitialize()
{
	for (auto& Pair : Managers)
	{
		Pair.Value->Shutdown();
	}
	
	Managers.Empty();
	
	Super::Deinitialize();
}