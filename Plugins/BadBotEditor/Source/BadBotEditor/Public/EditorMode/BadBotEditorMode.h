#pragma once

#include "CoreMinimal.h"
#include "EdMode.h"
#include "EditorMode/BadBotEditorMaterialCopyPasteTool.h"
class FBadBotEditorMode : public FEdMode
{

public:

    // Unique ID for this mode
    const static FEditorModeID EM_BadBotEditorMode;

    // Called when mode starts
    virtual void Enter() override;

    // Called when mode ends
    virtual void Exit() override;

    // Enable UI widgets
    virtual bool UsesPropertyWidgets() const override
    {
        return true;
    }
    virtual bool HandleClick(FEditorViewportClient* _viewportClient, HHitProxy* _hitProxy, const FViewportClick& _click) override;
private:
    FBadBotEditorMaterialCopyPasteTool CopyMaterial;
  


};