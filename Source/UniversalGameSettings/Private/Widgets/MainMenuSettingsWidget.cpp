// Fill out your copyright notice in the Description page of Project Settings.


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

