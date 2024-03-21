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

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"


#include "SettingsLatticeWidget.generated.h"

/** *
 * 
 */
UCLASS()
class UNIVERSALGAMESETTINGS_API USettingsLatticeWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	/** * 按钮控件 */
	UPROPERTY(BlueprintReadOnly, Meta = (BindWidget), Category = "SettingsLatticeWidget|Variable")
	TObjectPtr<UButton> Button_Widget;

	/** * 文字控件 */
	UPROPERTY(BlueprintReadOnly, Meta = (BindWidget), Category = "SettingsLatticeWidget|Variable")
	TObjectPtr<UTextBlock> TextBlock_Widget;

	/** * 识别的UID */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SettingsLatticeWidget|Variable")
	FString UID;

	/** * * 委托宏2个输入 */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCommunication, int, OnType, FString, OnUID);

	/** * * 触发的委托变量 */
	UPROPERTY(BlueprintAssignable, Category = "SettingsLatticeWidget|On")
	FCommunication OnTrigger;

protected:

	virtual void NativeConstruct() override;

public:

	/** * * 触发的委托事件 */
	UFUNCTION(BlueprintNativeEvent, Category = "SettingsLatticeWidget|Function")
	void OnPressed_Event();
	/** * * 原生触发的委托事件 */
	virtual void NativeOnPressed_Event();

	/** * * 初始化数据 */
	UFUNCTION(BlueprintNativeEvent, Category = "SettingsLatticeWidget|Function")
	void InitData(const FString& OUID, const FText& OText);
	/** * * 原生初始化数据 */
	virtual void NativeInitData(const FString& OUID, const FText& OText);

	

};
