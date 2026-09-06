// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class FSlateStyleSet;
class FBadBotEditorModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	void RegisterStyleSet();
	void UnregisterStyleSet();

	static FName GetStyleSetName()
	{
		return FName("BadBotModuleStyleSet");
	}
private:
	TSharedPtr<FSlateStyleSet> StyleSet;

};
