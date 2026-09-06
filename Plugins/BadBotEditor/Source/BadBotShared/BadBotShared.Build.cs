using UnrealBuildTool;
public class BadBotShared: ModuleRules
{

    public BadBotShared(ReadOnlyTargetRules Target):base(Target)
    {
        PCHUsage=ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "NetCore",
            }
        );
        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "ApplicationCore",
                "CoreUObject",
                "Engine",
                "Slate",


                "SlateCore",
                "UnrealEd",
                "EditorFramework",
                "LevelEditor",
                "Projects",
                "InputCore",
                "InteractiveToolsFramework",    // Often needed for new modes
    "EditorInteractiveToolsFramework",

            }
        );
    }

}