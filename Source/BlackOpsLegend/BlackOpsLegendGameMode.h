// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BlackOpsLegendGameMode.generated.h"

UCLASS(minimalapi)
class ABlackOpsLegendGameMode : public AGameModeBase
{
	GENERATED_BODY()
	virtual void StartPlay() override;
public:
	ABlackOpsLegendGameMode();
};



