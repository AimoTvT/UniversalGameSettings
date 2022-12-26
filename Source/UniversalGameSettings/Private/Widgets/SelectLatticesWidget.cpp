// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/SelectLatticesWidget.h"
#include "Components/HorizontalBoxSlot.h"



void USelectLatticesWidget::NativeConstruct()
{
	Super::NativeConstruct();
	

}



void USelectLatticesWidget::InitWidget(FString InUID, TArray<UObject*> InResources, TArray<FText> InTexts, int ButtonNum)
{
	UID = InUID;
	ImageResources = InResources;
	HorizontalBoxWidget->ClearChildren();
	for (size_t i = 0; i < ButtonNum && i < 8; i++)
	{
		UButton* Button = NewObject<UButton>(this);
		if (Button)
		{
			TScriptDelegate<FWeakObjectPtr> OnSetDragPrt; //建立对接变量
			FString FunctionName = "OnPressed" + FString::FromInt(i) + "_Event";
			OnSetDragPrt.BindUFunction(this, *FunctionName); //对接变量绑定函数
			Button->OnPressed.Add(OnSetDragPrt);
			SetButtonResource(Button, ImageResources.Num() > 0 ? ImageResources[0] : nullptr);
			UPanelSlot* PanelSlot = HorizontalBoxWidget->AddChild(Button);
			if (PanelSlot)
			{
				UHorizontalBoxSlot* HorizontalBoxSlot= Cast<UHorizontalBoxSlot>(PanelSlot);
				if (HorizontalBoxSlot)
				{
					FSlateChildSize InSize;
					InSize.SizeRule = ESlateSizeRule::Fill;
					HorizontalBoxSlot->SetSize(InSize);
				}
			}
			if (InTexts.Num() > i && InTexts[i].ToString().Len() > 0)
			{
				UTextBlock* WidgetText = NewObject<UTextBlock>(this);
				if (WidgetText)
				{
					WidgetText->SetText(InTexts[i]);
					Button->AddChild(WidgetText);
				}
			}
		}
	}
	SetSelect(SelectInde);
}


void USelectLatticesWidget::SetSelect(int InIndex, UObject* InResource)
{
	if (HorizontalBoxWidget)
	{
		TArray<UWidget*> Widgets = HorizontalBoxWidget->GetAllChildren();
		UButton* Button = nullptr;
		if (InIndex >= 0 && Widgets.Num() > InIndex)
		{
			if (Widgets[SelectInde])
			{
				Button = Cast<UButton>(Widgets[SelectInde]);
				SetButtonResource(Button, InResource ? InResource : (ImageResources.Num() > 0 ? ImageResources[0] : nullptr));
			}
			if (Widgets[InIndex])
			{
				Button = Cast<UButton>(Widgets[InIndex]);
				SetButtonResource(Button, InResource);
			}
			SelectInde = InIndex;
		}
	}
}

void USelectLatticesWidget::SetButtonResource(UButton* InButton, UObject* InResource)
{
	if (InButton)
	{
		FButtonStyle ButtonStyle = InButton->WidgetStyle;
		FSlateBrush InNormal;
		InResource = InResource ? InResource : (ImageResources.Num() > 1 ? ImageResources[1] : nullptr);
		ButtonStyle.Normal.SetResourceObject(InResource);
		ButtonStyle.Hovered.SetResourceObject(InResource);
		ButtonStyle.Pressed.SetResourceObject(InResource);
		ButtonStyle.Disabled.SetResourceObject(InResource);
		InButton->SetStyle(ButtonStyle);
	}
}

void USelectLatticesWidget::OnPressed0_Event()
{
	OnSelect.Broadcast(UID,0);
	SetSelect(0);
}

void USelectLatticesWidget::OnPressed1_Event()
{
	OnSelect.Broadcast(UID, 1);
	SetSelect(1);
}

void USelectLatticesWidget::OnPressed2_Event()
{
	OnSelect.Broadcast(UID, 2);
	SetSelect(2);
}

void USelectLatticesWidget::OnPressed3_Event()
{
	OnSelect.Broadcast(UID, 3);
	SetSelect(3);
}

void USelectLatticesWidget::OnPressed4_Event()
{
	OnSelect.Broadcast(UID, 4);
	SetSelect(4);
}

void USelectLatticesWidget::OnPressed5_Event()
{
	OnSelect.Broadcast(UID, 5);
	SetSelect(5);
}

void USelectLatticesWidget::OnPressed6_Event()
{
	OnSelect.Broadcast(UID, 6);
	SetSelect(6);
}

void USelectLatticesWidget::OnPressed7_Event()
{
	OnSelect.Broadcast(UID, 7);
	SetSelect(7);
}
