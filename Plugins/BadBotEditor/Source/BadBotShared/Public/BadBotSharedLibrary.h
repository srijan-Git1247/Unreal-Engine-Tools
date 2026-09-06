#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "BadBotSharedLibrary.generated.h"

UENUM(BlueprintType)
enum class EBadBotNotificationType :uint8
{
	Fail,
	Success,
};

UCLASS()
class BADBOTSHARED_API UBadBotSharedLibrary :public UBlueprintFunctionLibrary
{
	GENERATED_BODY()


public:
	UFUNCTION(BlueprintCallable, Category = "Util")
	static void AddNotification(FString _header, FString _description, EBadBotNotificationType _type, float _expireDuration = 2.0f, float _fadeOutDuration = 2.0f);

};