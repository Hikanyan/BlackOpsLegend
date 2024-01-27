// Fill out your copyright notice in the Description page of Project Settings.


#include "Internationalization/Text.h"
#include "BlackOpsLegend/Members/Saruwatari/MyUserWidget.h"

void UMyUserWidget::UpdateText()
{
    // ‚±‚±‚ÅUI‚É‘Î‚·‚éƒƒWƒbƒN‚ğ’Ç‰Á
    DisplayText = FText::FromString(TEXT("Helloworld"));
}