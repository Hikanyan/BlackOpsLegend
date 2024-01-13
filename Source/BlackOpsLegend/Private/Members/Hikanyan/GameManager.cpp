#include "Members/Hikanyan/GameManager.h"
#include "GameFramework/Character.h"
#include "EngineUtils.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/PlayerStart.h"

AGameManager::AGameManager()
{
	// コンストラクタでの初期設定
	PrimaryActorTick.bCanEverTick = true;
}

void AGameManager::BeginPlay()
{
	// ゲーム開始時の処理
	// TitleMapの場合はここでプレイヤー数を表示する
	// マッチング開始
	// 


	Super::BeginPlay();
	if (GetWorld()->GetNetMode() == NM_DedicatedServer)
	{
		// サーバー専用のロジック
		// ゲーム開始時にプレイヤー数を取得
		GetAllPlayers();
		// ゲーム開始時にプレイヤー数を表示
		DisplayPlayerCount();
	}
}

void AGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 勝者が決定したかどうかをチェック
	if (Winner)
	{
		FString WinnerMessage = FString::Printf(TEXT("Winner: %s"), *Winner->GetName());
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, WinnerMessage);

		// ゲーム終了処理など
	}
}

void AGameManager::DisplayPlayerCount()
{
	// プレイヤー数の取得
	int32 PlayerCount = 0;
	for (TActorIterator<APlayerController> It(GetWorld()); It; ++It)
	{
		PlayerCount++;
	}

	// プレイヤー数を文字列として表示
	FString PlayerCountString = FString::Printf(TEXT("Player Count: %d"), PlayerCount);
	UKismetSystemLibrary::PrintString(this, PlayerCountString, true, true, FLinearColor::Green, 0.f);
}

// プレイヤーを全て取得する
void AGameManager::GetAllPlayers()
{
	for (TActorIterator<ACharacter> It(GetWorld()); It; ++It)
	{
		ACharacter* PlayerCharacter = *It;
		if (PlayerCharacter)
		{
			// 必要な処理をここに追加
		}
	}
}

void AGameManager::DetermineWinner(APlayerController* WinningPlayer)
{
	Winner = WinningPlayer;

	// その他の勝利ロジック
}
