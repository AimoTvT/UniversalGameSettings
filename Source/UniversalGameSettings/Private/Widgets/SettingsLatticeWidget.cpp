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


#include "Widgets/SettingsLatticeWidget.h"

void USettingsLatticeWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (Button_Widget)
	{
		FScriptDelegate ScriptDelegate; //建立对接变量
		ScriptDelegate.BindUFunction(this, "OnPressed_Event"); //对接变量绑定函数
		Button_Widget->OnPressed.Add(ScriptDelegate);
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
