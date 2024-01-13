// Fill out your copyright notice in the Description page of Project Settings.


#include "Lobby.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
ALobby::ALobby()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALobby::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALobby::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ShowLoadingScreen()
{
	// ロード画面を表示する
	UGameplayStatics::OpenLevel(GetWorld(), "LoadingScreen");
}