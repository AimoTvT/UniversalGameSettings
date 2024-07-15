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

#include "Components/TextBlock.h"
#include "Components/ScrollBox.h"
#include "Components/WidgetSwitcher.h"
#include "Saves/SettingSave.h"
#include "WidgetExpansions/Public/SelectScrollBox/SelectScrollBox.h"
#include "Components/GridPanel.h"

#include "MainMenuSettingsWidget.generated.h"

/** *
 * 
 */
UCLASS()
class UNIVERSALGAMESETTINGS_API UMainMenuSettingsWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	/** * 设置类型选项框控件 */
	UPROPERTY(BlueprintReadOnly, Meta = (BindWidget), Category = "MainMenuSettingsWidget|Variable")
	TObjectPtr<UGridPanel>  GridPanel;

	/** * 设置类型选项框控件 */
	UPROPERTY(BlueprintReadOnly, Meta = (BindWidget), Category = "MainMenuSettingsWidget|Variable")
	TObjectPtr<USelectScrollBox>  SelectScrollBox;

	/** * 切换控件 */
	UPROPERTY(BlueprintReadOnly, Meta = (BindWidget), Category = "MainMenuSettingsWidget|Variable")
	TObjectPtr<UWidgetSwitcher> WidgetSwitcher;

	/** *  */
	UPROPERTY(BlueprintReadOnly, Meta = (BindWidget), Category = "MainMenuSettingsWidget|Variable")
	TObjectPtr<USizeBox> SizeBoxSwitcher;

	/** *  */
	UPROPERTY(BlueprintReadOnly, Meta = (BindWidget), Category = "MainMenuSettingsWidget|Variable")
	TObjectPtr<UScrollBox> ScrollBoxSwitcher;

	/** *  */
	UPROPERTY(BlueprintReadOnly, Meta = (BindWidget), Category = "MainMenuSettingsWidget|Variable")
	TObjectPtr<USizeBox> SizeBoxSwitcherExtension;

	/** * 扩展选项框控件 */
	UPROPERTY(BlueprintReadOnly, Meta = (BindWidget), Category = "MainMenuSettingsWidget|Variable")
	TObjectPtr<USelectScrollBox>  ExtensionSelectScrollBox; 

	/** *  */
	UPROPERTY(BlueprintReadOnly, Meta = (BindWidget), Category = "MainMenuSettingsWidget|Variable")
	TObjectPtr<UTextBlock> PromptTextWidget;

	/** * 识别的UID */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "MainMenuSettingsWidget|Variable")
	TArray<FString> IDs; 

	/** * 按键名字 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "MainMenuSettingsWidget|Variable")
	TArray<FText> ButtonNames; 

	/** * 已生成的控件组 */
	UPROPERTY(BlueprintReadWrite, Category = "MainMenuSettingsWidget|Variable")
	TArray<TObjectPtr<UWidget>> WidgetSwitcherWidgets;

	/** * 对应按钮点击生成的控件类组 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "MainMenuSettingsWidget|Variable")
	TArray<TSoftClassPtr<class UWidget>> WidgetSwitcherSoftClassPtr;
		
	/** *  */
	UPROPERTY(BlueprintReadWrite, Category = "MainMenuSettingsWidget|Variable")
	FString SettingSaveName = TEXT("SettingSave");

	/** *  */
	UPROPERTY(BlueprintReadWrite, Category = "MainMenuSettingsWidget|Variable")
	TObjectPtr<USettingSave> MySettingSave;
	

protected:

	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;

public:

	/** * 初始化控件 */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "MainMenuSettingsWidget|Function")
	void InitWdiget();

	/** * 调用触发事件 */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "MainMenuSettingsWidget|Function")
	void OnTrigger_Event(const FString& OnID, const FString& SelectID);
	void NativeOnTrigger_Event(const FString& OnID, const FString& SelectID);

	/** *  */
	UFUNCTION(BlueprintCallable, Category = "MainMenuSettingsWidget|Function")
	virtual USettingSave* GetSettingSave(int32 UserIndex = 0);

	/** *  */
	UFUNCTION(BlueprintCallable, Category = "MainMenuSettingsWidget|Function")
	virtual bool SaveSettingSave(USettingSave* InSettingSave, int32 UserIndex = 0);

	/** *  */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "MainMenuSettingsWidget|Function")
	void ExtensionNames(const TArray<FText>& ExtensionButtonNames);
	
	/** * 调用触发事件 */
	UFUNCTION(BlueprintCallable, Category = "MainMenuSettingsWidget|Function")
	virtual void OnExtensionTrigger_Event(const FString& OnID, const FString& SelectID);

	/** * 调用触发事件 */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "MainMenuSettingsWidget|Function")
	void PromptText(const FText& InText);
	virtual void NativePromptText(const FText& InText);

};
