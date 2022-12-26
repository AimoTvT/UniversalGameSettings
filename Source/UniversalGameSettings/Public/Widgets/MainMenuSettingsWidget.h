// Fill out your copyright notice in the Description page of Project Settings.

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
