#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Lobby.generated.h"

UCLASS()
class BLACKOPSLEGEND_API ALobby : public AActor
{
	GENERATED_BODY()

public:
	ALobby();

	UFUNCTION(BlueprintCallable, Category = "Custom Events")
	void ShowLoadingScreen();

	UFUNCTION(BlueprintCallable, Category = "Custom Events")
	void OpenLevel();

	UFUNCTION(BlueprintCallable, Category = "Custom Events")
	void ExecuteConsoleCommand(const FString& Command);

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
