// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/ChildSettingWidget.h"
#include "Widgets/MainMenuSettingsWidget.h"

UMainMenuSettingsWidget* UChildSettingWidget::GetMyMainMenuSettingsWidget()
{
	return MyMainMenuSettingsWidget;
}

void UChildSettingWidget::SetMyMainMenuSettingsWidget(UMainMenuSettingsWidget* InMainMenuSettingsWidget)
{
	MyMainMenuSettingsWidget = InMainMenuSettingsWidget;
}

USettingSave* UChildSettingWidget::GetSettingSave(int32 UserIndex)
{
	if (MyMainMenuSettingsWidget)
	{
		return MyMainMenuSettingsWidget->GetSettingSave(UserIndex);
	}
	return nullptr;
}

bool UChildSettingWidget::SaveSettingSave(int32 UserIndex)
{
	if (MyMainMenuSettingsWidget)
	{
		return MyMainMenuSettingsWidget->SaveSettingSave(MyMainMenuSettingsWidget->MySettingSave, UserIndex);
	}
	return false;
}


void UChildSettingWidget::ExtensionTrigger_Implementation(int InIndex)
{
}

void UChildSettingWidget::PromptText(FText InText)
{
	if (MyMainMenuSettingsWidget)
	{
		MyMainMenuSettingsWidget->PromptText(InText);
	}
}