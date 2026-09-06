#pragma once

#include "CoreMinimal.h"

class FEditorViewPortClient;
class HHitProxy;
class UStaticMeshComponent;
class UMaterialInterface;
struct FViewPortClick;

class FBadBotEditorMaterialCopyPasteTool
{
public:
	bool HandleClick(FEditorViewPortClient* _viewportClient, HHitProxy* _hitProxy, const FViewPortClick& _click);

private:
	void CopyMaterial(int _materialIndex, const UStaticMeshComponent* _meshComponent);
	void PasteMaterial(int _materialIndex, UStaticMeshComponent* _meshComponent);

	TWeakObjectPtr<UMaterialInterface> Material = nullptr;
};