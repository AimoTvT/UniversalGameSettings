// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/SizeBox.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/HorizontalBox.h"

#include "SelectLatticesWidget.generated.h"

/**
 * 
 */
UCLASS()
class UNIVERSALGAMESETTINGS_API USelectLatticesWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadOnly, Meta = (BindWidget), Category = "Aimo|Variable")
		/** 按钮 */
		USizeBox* SizeBoxWidget;

	UPROPERTY(BlueprintReadOnly, Meta = (BindWidget), Category = "Aimo|Variable")
		/** 按钮 */
		UHorizontalBox* HorizontalBoxWidget;

	UPROPERTY(BlueprintReadOnly, Meta = (BindWidget), Category = "Aimo|Variable")
		/** 按钮(不一定需要) */
		TArray<UButton*> Buttons;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Aimo|Variable")
		/**  */
		TArray<UObject*> ImageResources;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Aimo|Variable")
		/**  */
		int SelectInde;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Aimo|Variable")
		/**  */
		FString UID;


	/** * 委托宏2个输入 */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCommunication, FString, OnUID, int, OnIndex);

	UPROPERTY(BlueprintAssignable, Category = "Aimo|On") //蓝图公开并分类
		/** * 触发的委托变量 */
		FCommunication OnSelect; //2 参数的委托定义变量

protected:

	virtual void NativeConstruct() override;

public:

	UFUNCTION(BlueprintCallable, Category = "Aimo|Function")
	/* * 删除所有按钮,重新生成按钮,如果Text不为空生成文字 */
	void InitWidget(FString InUID, TArray<UObject*> InResources, TArray<FText> InTexts,int ButtonNum = 4);

	UFUNCTION(BlueprintCallable, Category = "Aimo|Function")
	void SetSelect(int InIndex, UObject* InResource = nullptr);

	void SetButtonResource(UButton* InButton, UObject* InResource = nullptr);

	UFUNCTION(BlueprintCallable)
	void OnPressed0_Event();
	UFUNCTION(BlueprintCallable)
	void OnPressed1_Event();
	UFUNCTION(BlueprintCallable)
	void OnPressed2_Event();
	UFUNCTION(BlueprintCallable)
	void OnPressed3_Event();
	UFUNCTION(BlueprintCallable)
	void OnPressed4_Event();
	UFUNCTION(BlueprintCallable)
	void OnPressed5_Event();
	UFUNCTION(BlueprintCallable)
	void OnPressed6_Event();
	UFUNCTION(BlueprintCallable)
	void OnPressed7_Event();
	

};
