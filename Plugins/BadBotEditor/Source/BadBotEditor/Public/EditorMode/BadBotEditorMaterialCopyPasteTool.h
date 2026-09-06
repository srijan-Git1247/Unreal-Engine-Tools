#pragma	once

#include "CoreMinimal.h"

class	FEditorViewportClient;
class	HHitProxy;
class	UStaticMeshComponent;
class	UMaterialInterface;
struct	FViewportClick;

class FBadBotEditorMaterialCopyPasteTool
{
public:
	bool HandleClick(FEditorViewportClient* _viewportClient, HHitProxy* _hitProxy, const	FViewportClick& _click);
private:

	void CopyMaterial(int	_materialIndex, const	UStaticMeshComponent* _meshComponent);
	void PasteMaterial(int	_materialIndex, UStaticMeshComponent* _meshComponent);
	TWeakObjectPtr<UMaterialInterface>	Material = nullptr;
};