// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BlackOpsLegend : ModuleRules
{
	public BlackOpsLegend(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
