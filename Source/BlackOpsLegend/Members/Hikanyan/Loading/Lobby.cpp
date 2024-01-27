#include "Lobby.h"
#include "Kismet/GameplayStatics.h"

ALobby::ALobby()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ALobby::BeginPlay()
{
	Super::BeginPlay();
}

void ALobby::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ALobby::ShowLoadingScreen()
{
	// 実装をここに記述
}

void ALobby::OpenLevel()
{
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("TitleMap"), true, TEXT("listen"));
}

void ALobby::ExecuteConsoleCommand(const FString& Command)
{
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	if (PlayerController)
	{
		PlayerController->ConsoleCommand(Command, true);
	}
}
