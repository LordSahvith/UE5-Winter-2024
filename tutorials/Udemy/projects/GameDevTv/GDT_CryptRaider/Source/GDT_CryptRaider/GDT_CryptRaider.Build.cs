// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GDT_CryptRaider : ModuleRules
{
	public GDT_CryptRaider(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
