#include "BadBotEditorCommands.h"
#include "BadBotEditor.h"
#define LOCTEXT_NAMESPACE "FBadBotEditorCommands"

FBadBotEditorCommands::FBadBotEditorCommands() :TCommands<FBadBotEditorCommands>("BadBotEditor", FText::FromString(TEXT("Bad Bot Editor Commands")), NAME_None, FBadBotEditorModule::GetStyleSetName())
{

}
void FBadBotEditorCommands::RegisterCommands()
{
	UI_COMMAND(MaterialTool, "Material tool", "Button to hold down while left/middle mouse clicking on copy/paste material from static mesh actors", EUserInterfaceActionType::None, FInputChord(EKeys::M));

}
#undef LOCTEXT_NAMESPACE