#include "BadBotSharedLibrary.h"

#include "Framework/Notifications/NotificationManager.h"
#include "Widgets/Notifications/SNotificationList.h"


void UBadBotSharedLibrary::AddNotification(FString _header, FString _description, EBadBotNotificationType _type, float _expireDuration, float _fadeOutDuration)
{

	FNotificationInfo info(FText::FromString(_header));
	info.SubText = FText::FromString(_description);
	info.ExpireDuration = _expireDuration;
	info.FadeOutDuration = _fadeOutDuration;

	FSlateNotificationManager& notificationManager = FSlateNotificationManager::Get();

	TSharedPtr<SNotificationItem> notification = notificationManager.AddNotification(info);

	switch (_type)
	{
		case EBadBotNotificationType::Fail:
			notification->SetCompletionState(SNotificationItem::ECompletionState::CS_Fail);
			break;

		case EBadBotNotificationType::Success:
			notification->SetCompletionState(SNotificationItem::ECompletionState::CS_Success);
			break;

	}
}