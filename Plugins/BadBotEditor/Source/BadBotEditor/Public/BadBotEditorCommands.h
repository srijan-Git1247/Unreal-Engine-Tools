#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"

class FBadBotEditorCommands : public TCommands<FBadBotEditorCommands>
{
public:
	FBadBotEditorCommands();

	//TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr<FUICommandInfo> MaterialTool;
};
