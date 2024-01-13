#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameManager.generated.h"

UCLASS()
class BLACKOPSLEGEND_API AGameManager : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGameManager();

	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	// プレイヤー数を表示する関数
	void DisplayPlayerCount();
	// プレイヤーを全て取得する関数
	void GetAllPlayers();
	// 勝者を決定する関数
	void DetermineWinner(APlayerController* WinningPlayer);

private:
	// 勝者を表示するための変数
	APlayerController* Winner = nullptr;
};
