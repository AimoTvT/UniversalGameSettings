// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"


#include "SettingsLatticeWidget.generated.h"

/**
 * 
 */
UCLASS()
class UNIVERSALGAMESETTINGS_API USettingsLatticeWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly, Meta = (BindWidget), Category = "Aimo|Variable")
		/** 按钮 */
		UButton* Button_Widget;

	UPROPERTY(BlueprintReadOnly, Meta = (BindWidget), Category = "Aimo|Variable")
		/** 按钮 */
		UTextBlock* TextBlock_Widget;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Aimo|Variable")
		/** 识别的UID */
		FString UID;

	/** * 委托宏2个输入 */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCommunication, int, OnType, FString, OnUID);

	UPROPERTY(BlueprintAssignable, Category = "Aimo|On") //蓝图公开并分类
		/** * 触发的委托变量 */
		FCommunication OnTrigger; //2 参数的委托定义变量

protected:

	virtual void NativeConstruct() override;

public:

	UFUNCTION(BlueprintNativeEvent, Category = "Aimo|Function")
		/** * 触发的委托事件 */
		void OnPressed_Event();
		/** * 原生触发的委托事件 */
	virtual void NativeOnPressed_Event();

	UFUNCTION(BlueprintNativeEvent, Category = "Aimo|Function")
		/** * 初始化数据 */
		void InitData(const FString& OUID, const FText& OText);
		/** * 原生初始化数据 */
	virtual void NativeInitData(const FString& OUID, const FText& OText);

	

};
