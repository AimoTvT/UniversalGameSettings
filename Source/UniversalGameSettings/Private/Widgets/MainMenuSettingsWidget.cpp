/** *
 * Copyright: Aimo_皑墨
 * Open Source Date: December 27, 2022
 * BiLiBiLi (哔哩哔哩) address: https://space.bilibili.com/146962867
 * making address: https://github.com/AimoTvT/UniversalGameSettings
 * We welcome the contributions of powerful movers and movers to join this plugin
 * Build powerful plugins together!!
 *
 * 版权所有权: Aimo_皑墨
 * 开源时间: 2022年12月27号
 * BiLiBiLi(哔哩哔哩)地址: https://space.bilibili.com/146962867
 * GitHub地址: https://github.com/AimoTvT/UniversalGameSettings
 * 欢迎有实力的大佬/萌新加入本插件的贡献
 * 一起打造强大的插件!!!
 */


#include "Widgets/MainMenuSettingsWidget.h"
#include "Kismet/GameplayStatics.h"

#include "Widgets/ChildSettingWidget.h"

void UMainMenuSettingsWidget::NativePreConstruct()
{
	Super::NativePreConstruct();


}





void UMainMenuSettingsWidget::NativeConstruct()
{
	Super::NativeConstruct();

	InitWdiget();
}

void UMainMenuSettingsWidget::InitWdiget_Implementation()
{
	WidgetSwitcherWidgets.SetNum(ButtonNames.Num());
	if (SelectScrollBox)
	{
		SelectScrollBox->InitData(IDs, ButtonNames);
		SelectScrollBox->OnClickedSelect.AddDynamic(this, &UMainMenuSettingsWidget::OnTrigger_Event);
		ExtensionSelectScrollBox->OnClickedSelect.AddDynamic(this, &UMainMenuSettingsWidget::OnExtensionTrigger_Event);
		if (ButtonNames.Num() > 0)
		{
			NativeOnTrigger_Event("", IDs[0]);
		}
	}
}



void UMainMenuSettingsWidget::OnTrigger_Event_Implementation(const FString& OnID, const FString& SelectID)
{
	NativeOnTrigger_Event(OnID, SelectID);
}


void UMainMenuSettingsWidget::NativeOnTrigger_Event(const FString& OnID, const FString& SelectID)
{
	int Index = IDs.Find(SelectID);
	if (Index != -1)
	{
		if (ButtonNames.IsValidIndex(Index))
		{
			PromptText(ButtonNames[Index]);
		}
		if (WidgetSwitcherWidgets.Num() > Index && WidgetSwitcherWidgets[Index])
		{
			if (Index != WidgetSwitcher->GetActiveWidgetIndex())
			{
				WidgetSwitcher->SetActiveWidget(WidgetSwitcherWidgets[Index]);
				UChildSettingWidget* ChildSettingWidget = Cast<UChildSettingWidget>(WidgetSwitcherWidgets[Index]);
				if (ChildSettingWidget)
				{
					ExtensionNames(ChildSettingWidget->ExtensionButtonNames);
				}
				else
				{
					ExtensionNames(TArray<FText>());
				}
			}
			return;
		}
		else
		{
			if (WidgetSwitcherSoftClassPtr.Num() > Index && !WidgetSwitcherSoftClassPtr[Index].IsNull())
			{
				
				TSubclassOf<class UUserWidget> WidgetClass = WidgetSwitcherSoftClassPtr[Index].LoadSynchronous();
				if (WidgetClass)
				{
					UWidget* Widget = CreateWidget<UUserWidget>(GetOwningPlayer(), WidgetClass);
					if (Widget)
					{
						WidgetSwitcherWidgets[Index] = Widget;
						UChildSettingWidget* ChildSettingWidget = Cast<UChildSettingWidget>(Widget);
						if (ChildSettingWidget)
						{
							ChildSettingWidget->SetMyMainMenuSettingsWidget(this); 
							ExtensionNames(ChildSettingWidget->ExtensionButtonNames);
						}
						else
						{
							ExtensionNames(TArray<FText>());
						}
						WidgetSwitcher->AddChild(Widget);
						WidgetSwitcher->SetActiveWidget(Widget);
					}
				}
			}
		}
	}
	return;
}

USettingSave* UMainMenuSettingsWidget::GetSettingSave(int32 UserIndex)
{
	if (MySettingSave)
	{
		return MySettingSave;
	}
	if (UGameplayStatics::DoesSaveGameExist(SettingSaveName, UserIndex))
	{
		USaveGame* LoadSaveGame = UGameplayStatics::LoadGameFromSlot(SettingSaveName, UserIndex);
		if (LoadSaveGame)
		{
			MySettingSave = Cast<USettingSave>(LoadSaveGame);
			if (MySettingSave)
			{
				return MySettingSave;
			}
			UGameplayStatics::DeleteGameInSlot(SettingSaveName, UserIndex);
		}
	}
	USaveGame* SaveGame = UGameplayStatics::CreateSaveGameObject(USettingSave::StaticClass());
	if (SaveGame)
	{
		UGameplayStatics::SaveGameToSlot(SaveGame, SettingSaveName, UserIndex);
		MySettingSave = Cast<USettingSave>(SaveGame);
	}
	return MySettingSave;
}

bool UMainMenuSettingsWidget::SaveSettingSave(USettingSave* InSettingSave, int32 UserIndex)
{
	if (InSettingSave)
	{
		return UGameplayStatics::SaveGameToSlot(InSettingSave, SettingSaveName, UserIndex);
	}
	return false;
}

void UMainMenuSettingsWidget::ExtensionNames_Implementation(const TArray<FText>& ExtensionButtonNames)
{
	if (ExtensionButtonNames.Num())
	{
		TArray<FString> Indexs;
		for (size_t i = 0; i < ExtensionButtonNames.Num(); i++)
		{
			Indexs.Add(FString::FromInt(i));
		}
		ExtensionSelectScrollBox->InitData(Indexs, ExtensionButtonNames);
	}
	else
	{
		ExtensionSelectScrollBox->InitData({}, {});
	}

}



void UMainMenuSettingsWidget::OnExtensionTrigger_Event(const FString& OnID, const FString& SelectID)
{
	if (WidgetSwitcher->GetActiveWidget())
	{
		UChildSettingWidget* ChildSettingWidget = Cast<UChildSettingWidget>(WidgetSwitcher->GetActiveWidget());
		if (ChildSettingWidget)
		{
			ChildSettingWidget->ExtensionTrigger(FCString::Atoi(*SelectID));
		}
	}
}

void UMainMenuSettingsWidget::PromptText_Implementation(const FText& InText)
{
	NativePromptText(InText);
}

void UMainMenuSettingsWidget::NativePromptText(const FText& InText)
{
	if (PromptTextWidget)
	{
		PromptTextWidget->SetText(InText);
	}
}
