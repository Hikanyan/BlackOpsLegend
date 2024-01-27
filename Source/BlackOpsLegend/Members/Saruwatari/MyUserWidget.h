// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Internationalization/Text.h"
#include "MyUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class BLACKOPSLEGEND_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()       

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
        FText DisplayText;

    UFUNCTION(BlueprintCallable, Category = "UI")
        void UpdateText();
	
};
