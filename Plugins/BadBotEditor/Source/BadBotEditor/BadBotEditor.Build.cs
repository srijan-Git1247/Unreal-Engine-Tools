// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BadBotEditor : ModuleRules
{
	public BadBotEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
            new string[] {
				// This tells the engine to expose everything inside your Public folder
				
            }
            );
				
		
		PrivateIncludePaths.AddRange(
            new string[] {
				// This tells the engine to look inside your Private folder
				
            }
            );
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                "UnrealEd",
                "EditorFramework",
                "LevelEditor",
                "Projects",
                "InputCore",
				"BadBotShared",
                "InteractiveToolsFramework",    // Often needed for new modes
    "EditorInteractiveToolsFramework",
            }
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
