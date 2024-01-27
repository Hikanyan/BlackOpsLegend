// Fill out your copyright notice in the Description page of Project Settings.


#include "BlackOpsLegend/Members/Saruwatari/SaruwatariTestActor.h"
#include "BlackOpsLegend/Members/Saruwatari/MyUserWidget.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

// Sets default values
ASaruwatariTestActor::ASaruwatariTestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


// Called when the game starts or when spawned
void ASaruwatariTestActor::BeginPlay()
{
	Super::BeginPlay();

    APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);

    FString Path = TEXT("Game/Members/Saruwatari/UMGWidget.UMGWidget");
    TSubclassOf<UUserWidget> WidgetClass = TSoftClassPtr<UUserWidget>(FSoftObjectPath(*Path)).LoadSynchronous();

    if (WidgetClass)
    {
        UKismetSystemLibrary::PrintString(this, "widgetclass", true, true, FColor::Cyan, 2.f, TEXT("None"));
    }
    if (PlayerController)
    {
        UKismetSystemLibrary::PrintString(this, "controller", true, true, FColor::Cyan, 2.f, TEXT("None"));
    }
    
    if (WidgetClass && PlayerController)
    {
        
        UUserWidget* UserWidget = UWidgetBlueprintLibrary::Create(GetWorld(), WidgetClass, PlayerController);


        // Viewport‚É’Ç‰Á‚·‚é
        UserWidget->AddToViewport(0);
    }

       

    //// Widget‚ğ¶¬‚µ‚Ä•\¦
    //UMyUserWidget* MyUserWidget = CreateWidget<UMyUserWidget>(GetWorld(), UMyUserWidget::StaticClass());
    //if (MyUserWidget)
    //{
    //    MyUserWidget->AddToViewport();
    //    MyUserWidget->UpdateText(); // UI‚É‘Î‚·‚é‰Šú‰»‚È‚Ç‚ª•K—v‚Èê‡
    //}
	
}

// Called every frame
void ASaruwatariTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

