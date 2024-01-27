// Fill out your copyright notice in the Description page of Project Settings.
// 編集者：薄衣　毅
//　編集日：2023/11/11
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UsugiTestActor.generated.h"

UCLASS()
class BLACKOPSLEGEND_API AUsugiTestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUsugiTestActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
