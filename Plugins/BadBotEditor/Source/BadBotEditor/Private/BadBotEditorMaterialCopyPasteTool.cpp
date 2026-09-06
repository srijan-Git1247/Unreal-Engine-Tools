#include "EditorMode/BadBotEditorMaterialCopyPasteTool.h"

#include "EngineUtils.h"
#include "BadBotEditorCommands.h"
#include "ScopedTransaction.h"//Helps us for undo and redo support
#include "BadBotSharedLibrary.h"

bool FBadBotEditorMaterialCopyPasteTool::HandleClick(FEditorViewportClient* _viewportClient, HHitProxy* _hitProxy, const FViewportClick& _click)
{
	if (_click.GetEvent() == IE_Released)
	{
		FInputEventState inputState(GEditor->GetActiveViewport(), _click.GetKey(), _click.GetEvent());

		const FInputChord& primaryChord = *FBadBotEditorCommands::Get().MaterialTool->GetActiveChord(EMultipleKeyBindingIndex::Primary);
		const FInputChord& secondaryChord = *FBadBotEditorCommands::Get().MaterialTool->GetActiveChord(EMultipleKeyBindingIndex::Secondary);

		bool materialMode = primaryChord.IsValidChord() && inputState.IsButtonPressed(primaryChord.Key) ||
			secondaryChord.IsValidChord() && inputState.IsButtonPressed(secondaryChord.Key);

		if (materialMode)
		{
			//TODO add copy.paste code here
			if (HActor* actorProxy = HitProxyCast<HActor>(_hitProxy))
			{
				AVolume* volume = Cast<AVolume>(actorProxy->Actor);
				if(volume==nullptr)
				{
					if (_click.GetKey() == EKeys::RightMouseButton)
					{
						const UStaticMeshComponent* meshComponent = Cast<UStaticMeshComponent>(actorProxy->PrimComponent);
						if (meshComponent != nullptr)
						{
							CopyMaterial(actorProxy->MaterialIndex, meshComponent);
							return true;
						}
						else
						{
							UBadBotSharedLibrary::AddNotification("Copy Failed", "Selected target has no static mesh!", EBadBotNotificationType::Fail);
						}

					}
					else if (_click.GetKey() == EKeys::LeftMouseButton)
					{
						const UStaticMeshComponent* meshComponent = Cast<UStaticMeshComponent>(actorProxy->PrimComponent);
						if (meshComponent != nullptr)
						{
							PasteMaterial(actorProxy->MaterialIndex, const_cast<UStaticMeshComponent*>(meshComponent));
							return true;
						}
						else
						{
							UBadBotSharedLibrary::AddNotification("Paste Failed", "Selected target has no static mesh!", EBadBotNotificationType::Fail);
						}
					}
				}
				else
				{
					// Triggered when clicking on a Volume (e.g., Blocking Volume, Post Process Volume)
					UBadBotSharedLibrary::AddNotification("Invalid Target", "Cannot copy/paste materials on Volumes!", EBadBotNotificationType::Fail);
				}
				
			}
			else
			{
				// Triggered when clicking empty viewport space
				UBadBotSharedLibrary::AddNotification("Invalid Target", "Clicked on empty space!", EBadBotNotificationType::Fail);
			}
		}

	}
	return false;
}
void FBadBotEditorMaterialCopyPasteTool::CopyMaterial(int _materialIndex, const UStaticMeshComponent* _meshComponent)
{
	Material = _meshComponent->GetMaterial(_materialIndex);

	//Creating notifications
	if (Material != nullptr)
	{
		UBadBotSharedLibrary::AddNotification("Copied Material", FString::Printf(TEXT("Copied material %s!"), *Material->GetName()), EBadBotNotificationType::Success);
	}
	else
	{
		UBadBotSharedLibrary::AddNotification("Copied Material", FString::Printf(TEXT("Failed getting material")), EBadBotNotificationType::Fail);
	}
}
void FBadBotEditorMaterialCopyPasteTool::PasteMaterial(int _materialIndex, UStaticMeshComponent* _meshComponent)
{
	if (UMaterialInterface* material = Material.Get())
	{
		//For undo and redo support
		FScopedTransaction transaction(FText::FromString("Paste a material onto clicked actor"));
		_meshComponent->GetOwner()->Modify();

		//Applying the materrial


		_meshComponent->SetMaterial(_materialIndex, material);

		UBadBotSharedLibrary::AddNotification("Pasted Material", FString::Printf(TEXT("Pasted Material %s!"), *Material->GetName()), EBadBotNotificationType::Success);
	}
	else
	{
		UBadBotSharedLibrary::AddNotification("Pasted Material", FString::Printf(TEXT("We do not have a copied material!")), EBadBotNotificationType::Fail);
	}
}
