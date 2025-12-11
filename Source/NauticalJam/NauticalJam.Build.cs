// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NauticalJam : ModuleRules
{
	public NauticalJam(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"NauticalJam",
			"NauticalJam/Variant_Platforming",
			"NauticalJam/Variant_Platforming/Animation",
			"NauticalJam/Variant_Combat",
			"NauticalJam/Variant_Combat/AI",
			"NauticalJam/Variant_Combat/Animation",
			"NauticalJam/Variant_Combat/Gameplay",
			"NauticalJam/Variant_Combat/Interfaces",
			"NauticalJam/Variant_Combat/UI",
			"NauticalJam/Variant_SideScrolling",
			"NauticalJam/Variant_SideScrolling/AI",
			"NauticalJam/Variant_SideScrolling/Gameplay",
			"NauticalJam/Variant_SideScrolling/Interfaces",
			"NauticalJam/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
