// Fill out your copyright notice in the Description page of Project Settings.


#include "Internationalization/Text.h"
#include "BlackOpsLegend/Members/Saruwatari/MyUserWidget.h"

void UMyUserWidget::UpdateText()
{
    // ������UI�ɑ΂��郍�W�b�N��ǉ�
    DisplayText = FText::FromString(TEXT("Helloworld"));
}