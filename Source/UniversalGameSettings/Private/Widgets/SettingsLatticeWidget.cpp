// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/SettingsLatticeWidget.h"

void USettingsLatticeWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (Button_Widget)
	{
		TScriptDelegate<FWeakObjectPtr> OnSetDragPrt; //建立对接变量
		OnSetDragPrt.BindUFunction(this, "OnPressed_Event"); //对接变量绑定函数
		Button_Widget->OnPressed.Add(OnSetDragPrt);
	}

}

void USettingsLatticeWidget::NativeOnPressed_Event()
{
	OnTrigger.Broadcast(0, UID);
}

void USettingsLatticeWidget::NativeInitData(const FString& OUID, const FText& OText)
{
	UID = OUID;
	if (TextBlock_Widget)
	{
		TextBlock_Widget->SetText(OText);
	}
}

void USettingsLatticeWidget::OnPressed_Event_Implementation()
{
	NativeOnPressed_Event();
}

void USettingsLatticeWidget::InitData_Implementation(const FString& OUID, const FText& OText)
{
	NativeInitData(OUID, OText);
}
