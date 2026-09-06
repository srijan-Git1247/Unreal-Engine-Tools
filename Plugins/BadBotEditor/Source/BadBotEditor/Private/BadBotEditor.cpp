#include "BadBotEditor.h"
#include "EditorModeRegistry.h"
#include "EditorMode/BadBotEditorMode.h"
#include "Styling/SlateStyleRegistry.h"
#include "BadBotEditorCommands.h"
#define LOCTEXT_NAMESPACE "FBadBotEditorModule"


//Implementing the RegisterStyleSet
void FBadBotEditorModule :: RegisterStyleSet()
{
	StyleSet = MakeShareable(new FSlateStyleSet(GetStyleSetName()));
	StyleSet->SetContentRoot(FPaths::ProjectPluginsDir() / TEXT("BadBotEditor/Resources"));
	const FVector2D Icon40x40(40.0f, 40.0f);
	const FVector2D Icon20x20(20.f, 20.0f);

#define IMAGE_BRUSH(RelativePath, ...) FSlateImageBrush(StyleSet->RootToContentDir(RelativePath, TEXT(".png")),__VA_ARGS__)
	StyleSet->Set("BadBotEditor.EditorMode", new IMAGE_BRUSH("BadBotEditorMode", Icon40x40));
	StyleSet->Set("BadBotEditor.EditorMode.Small", new IMAGE_BRUSH("BadBotEditorMode", Icon20x20));

	FSlateStyleRegistry::RegisterSlateStyle(*StyleSet.Get());
}
//Implementing the UnregisterStyleSet
void FBadBotEditorModule::UnregisterStyleSet()
{
	if (StyleSet.IsValid())
	{
		FSlateStyleRegistry::UnRegisterSlateStyle(*StyleSet.Get());
		ensure(StyleSet.IsUnique());
		StyleSet.Reset();
	}
}
void FBadBotEditorModule::StartupModule()
{
	RegisterStyleSet();
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FEditorModeRegistry::Get().RegisterMode<FBadBotEditorMode>(FBadBotEditorMode::EM_BadBotEditorMode, LOCTEXT("BadBotEditorModeName", "Bad Bot Editor"), FSlateIcon(GetStyleSetName(),"BadBotEditor.EditorMode","BadBotEditor.EditorMode.Small"), true, 200);
	FBadBotEditorCommands::Register();
}

void FBadBotEditorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	UnregisterStyleSet();
	FBadBotEditorCommands::Unregister();
}


#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FBadBotEditorModule, BadBotEditor)