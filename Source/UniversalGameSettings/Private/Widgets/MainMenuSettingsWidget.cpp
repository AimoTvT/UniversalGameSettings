/**
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
	if (VerticalBox_Lootices && !ButtonSoftClassPtr.IsNull())
	{
		TSubclassOf<class UUserWidget> ButtonClass;
		if (ButtonSoftClassPtr.IsValid())
		{
			ButtonClass = ButtonSoftClassPtr.Get();
		}
		else
		{
			ButtonClass = ButtonSoftClassPtr.LoadSynchronous();
		}
		UUserWidget* UserWidget;
		VerticalBox_Lootices->ClearChildren();
		for (size_t i = 0; i < ButtonNames.Num(); i++)
		{
			UserWidget = CreateWidget<UUserWidget>(GetOwningPlayer(), ButtonClass); /** * 生成按钮UI */
			if (UserWidget)
			{
				UserWidget->SetPadding({ 0.0f, 0.0f, 0.0f, 10.0f });
				VerticalBox_Lootices->AddChild(UserWidget);
				USettingsLatticeWidget* SettingsLatticeWidget = Cast<USettingsLatticeWidget>(UserWidget);
				if (SettingsLatticeWidget)
				{
					SettingsLatticeWidget->InitData(ButtonNames[i].ToString(), ButtonNames[i]);
					TScriptDelegate<FWeakObjectPtr> OnSetDragPrt; //建立对接变量
					OnSetDragPrt.BindUFunction(this, "OnTrigger_Event"); //对接变量绑定函数
					SettingsLatticeWidget->OnTrigger.Add(OnSetDragPrt);
				}
			}
		}
		if (ButtonNames.Num() > 0)
		{
			NativeOnTrigger_Event(0, ButtonNames[0].ToString());
		}
	}
}


void UMainMenuSettingsWidget::NativeOnTrigger_Event(int OnType, FString OnUID)
{
	int Index = 0;
	for (size_t i = 0; i < ButtonNames.Num(); i++)
	{
		if (ButtonNames[i].ToString() == OnUID)
		{
			Index = i;
			break;
		}
	}

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
				UWidget* Widget = nullptr;
				if (WidgetClass)
				{
					Widget = CreateWidget<UUserWidget>(GetOwningPlayer(), WidgetClass);
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

void UMainMenuSettingsWidget::OnTrigger_Event_Implementation(int& OnType, FString& OnUID)
{
	NativeOnTrigger_Event(OnType,OnUID); 
}

