// Fill out your copyright notice in the Description page of Project Settings.


#include "Internationalization/Text.h"
#include "BlackOpsLegend/Members/Saruwatari/MyUserWidget.h"

void UMyUserWidget::UpdateText()
{
    // ここでUIに対するロジックを追加
    DisplayText = FText::FromString(TEXT("Helloworld"));
}