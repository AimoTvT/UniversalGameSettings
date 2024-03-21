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
#include "Widgets/SettingsLatticeWidget.h"

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
		FScriptDelegate ScriptDelegate; //建立对接变量
		ScriptDelegate.BindUFunction(this, "OnTrigger_Event"); //对接变量绑定函数
		SelectScrollBox->OnClickedSelect.Add(ScriptDelegate);
		if (ButtonNames.Num() > 0)
		{
			NativeOnTrigger_Event("", IDs[0]);
		}
	}
}


void UMainMenuSettingsWidget::NativeOnTrigger_Event(const FString& OnID, const FString& SelectID)
{
	int Index = IDs.Find(SelectID);
	if (Index != -1)
	{
		if (WidgetSwitcherWidgets.Num() > Index && WidgetSwitcherWidgets[Index])
		{
			WidgetSwitcher->SetActiveWidget(WidgetSwitcherWidgets[Index]);
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
						WidgetSwitcher->AddChild(Widget);
						WidgetSwitcher->SetActiveWidget(Widget);
						WidgetSwitcherWidgets[Index] = Widget;
					}
				}
			}
		}
	}
} 

void UMainMenuSettingsWidget::OnTrigger_Event_Implementation(const FString& OnID, const FString& SelectID)
{
	NativeOnTrigger_Event(OnID, SelectID);
}

