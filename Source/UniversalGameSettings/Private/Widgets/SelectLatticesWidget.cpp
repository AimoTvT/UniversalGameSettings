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
			FScriptDelegate ScriptDelegate; //建立对接变量
			FString FunctionName = "OnPressed" + FString::FromInt(i) + "_Event";
			ScriptDelegate.BindUFunction(this, *FunctionName); //对接变量绑定函数
			Button->OnPressed.Add(ScriptDelegate);
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
		FButtonStyle ButtonStyle = InButton->GetStyle();
		FSlateBrush InNormal;
		InResource = InResource ? InResource : (ImageResources.Num() > 1 ? ImageResources[1] : nullptr);
		ButtonStyle.Normal.SetResourceObject(InResource);
		ButtonStyle.Hovered.SetResourceObject(InResource);
		ButtonStyle.Pressed.SetResourceObject(InResource);
		ButtonStyle.Disabled.SetResourceObject(InResource);
		InButton->SetStyle(ButtonStyle);
	}
}

void USelectLatticesWidget::OnPressed_Event()
{
	OnSelect.Broadcast(UID);
}
