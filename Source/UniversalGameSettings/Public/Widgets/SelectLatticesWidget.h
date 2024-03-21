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
#include "Components/SizeBox.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/HorizontalBox.h"

#include "SelectLatticesWidget.generated.h"

/** *
 * 
 */
UCLASS()
class UNIVERSALGAMESETTINGS_API USelectLatticesWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	/** * 尺寸框控件 */
	UPROPERTY(BlueprintReadOnly, Meta = (BindWidget), Category = "SelectLatticesWidget|Variable")
	TObjectPtr<USizeBox> SizeBoxWidget;

	/** * 水平框控件 */
	UPROPERTY(BlueprintReadOnly, Meta = (BindWidget), Category = "SelectLatticesWidget|Variable")
	TObjectPtr<UHorizontalBox> HorizontalBoxWidget;

	/** * 图像资源组 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SelectLatticesWidget|Variable")
	TArray<TObjectPtr<UObject>> ImageResources;

	/** * 识别的UID */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SelectLatticesWidget|Variable")
	FString UID;

	/** * 选择索引 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SelectLatticesWidget|Variable")
	int SelectIndex;

	


	/** * * 委托宏2个输入 */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCommunication, FString, OnUID);

	UPROPERTY(BlueprintAssignable, Category = "SelectLatticesWidget|On") //蓝图公开并分类
		/** * * 触发的委托变量 */
		FCommunication OnSelect; //2 参数的委托定义变量

protected:

	virtual void NativeConstruct() override;

public:

	/* * 删除所有按钮,重新生成按钮,如果Text不为空生成文字 */
	UFUNCTION(BlueprintCallable, Category = "SelectLatticesWidget|Function")
	void InitWidget(FString InUID, TArray<UObject*> InResources, TArray<FText> InTexts,int ButtonNum = 4);

	UFUNCTION(BlueprintCallable, Category = "SelectLatticesWidget|Function")
		/* * 修改选项索引 */
	void SetSelect(int InIndex, UObject* InResource = nullptr);

	void SetButtonResource(UButton* InButton, UObject* InResource = nullptr);

	/* * 触发按下的委托_事件 */
	UFUNCTION(BlueprintCallable, Category = "SelectLatticesWidget|Function")
	void OnPressed_Event();
	

};
