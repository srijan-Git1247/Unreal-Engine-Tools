#include "EditorMode/BadBotEditorMode.h"

const FEditorModeID FBadBotEditorMode::EM_BadBotEditorMode = TEXT("EM_BadBotEditorMode");

void FBadBotEditorMode::Enter()
{
    FEdMode::Enter();
}

void FBadBotEditorMode::Exit()
{
    FEdMode::Exit();
}
bool FBadBotEditorMode::HandleClick(FEditorViewportClient* _viewportClient, HHitProxy* _hitProxy, const FViewportClick& _click)
{
    if (CopyMaterial.HandleClick(_viewportClient, _hitProxy, _click))
    {
        return true;
    }
    return FEdMode::HandleClick(_viewportClient, _hitProxy, _click);
}