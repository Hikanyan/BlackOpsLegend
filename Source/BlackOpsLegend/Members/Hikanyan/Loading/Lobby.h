// Fill out your copyright notice in the Description page of Project Settings.

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
	// BlueprintCallableを使用してBlueprintから呼び出し可能にする
	UFUNCTION(BlueprintCallable, Category = "Custom Events")
	void ShowLoadingScreen();
	

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;
};
