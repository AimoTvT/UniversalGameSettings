// Fill out your copyright notice in the Description page of Project Settings.

/**
 * Copyright: Aimo_皑墨
 * Open source protocol: MIT License
 * Open Source Date: December 27, 2022
 * BiLiBiLi (哔哩哔哩) address: https://space.bilibili.com/146962867
 * making address: https://github.com/AimoTvT/UniversalGameSettings
 * We welcome the contributions of powerful movers and movers to join this plugin
 * Build powerful plugins together!!
 *
 * 版权所有权: Aimo_皑墨
 * 开源协议: MIT License
 * 开源时间: 2022年12月27号
 * BiLiBiLi(哔哩哔哩)地址: https://space.bilibili.com/146962867
 * GitHub地址: https://github.com/AimoTvT/UniversalGameSettings
 * 欢迎有实力的大佬/萌新加入本插件的贡献
 * 一起打造强大的插件!!!
 */

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Components/VerticalBox.h"
#include "Components/WidgetSwitcher.h"

#include "MainMenuSettingsWidget.generated.h"

/**
 * 
 */
UCLASS()
class UNIVERSALGAMESETTINGS_API UMainMenuSettingsWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadOnly, Meta = (BindWidget), Category = "Aimo|Variable")
		/** 设置类型选项框 */
		UVerticalBox* VerticalBox_Lootices;

	UPROPERTY(BlueprintReadOnly, Meta = (BindWidget), Category = "Aimo|Variable")
		/** 切换控件 */
		UWidgetSwitcher* WidgetSwitcher;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Aimo|Variable")
		/** 类型名字 */
		TArray<FText> ButtonNames;

	UPROPERTY(BlueprintReadWrite, Category = "Aimo|Variable")
		/** 控件组 */
		TArray<UWidget*> WidgetSwitcherWidgets;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Aimo|Variable")
		/** 控件类组 */
		TArray<TSoftClassPtr<class UWidget>> WidgetSwitcherSoftClassPtr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Aimo|Variable")
		/** 控件类组 */
		TSoftClassPtr<class UUserWidget> ButtonSoftClassPtr;
		

protected:

	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;

public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Aimo|Function")
		void InitWdiget();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Aimo|Function")
		void OnTrigger_Event(int& OnType, FString& OnUID);
		void NativeOnTrigger_Event(int OnType, FString OnUID);
};
