// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ChildSettingWidget.generated.h"

class UMainMenuSettingsWidget;

/**
 * 
 */
UCLASS()
class UNIVERSALGAMESETTINGS_API UChildSettingWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	/** *  */
	UPROPERTY(BlueprintReadWrite, Category = "MainMenuSettingsWidget|Variable")
	TObjectPtr<UMainMenuSettingsWidget> MyMainMenuSettingsWidget;


	/** * 类型名字 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "MainMenuSettingsWidget|Variable")
	TArray<FText> ExtensionButtonNames;

public:

	/** *  */
	UFUNCTION(BlueprintCallable, Category = "MainMenuSettingsWidget|Function")
	virtual UMainMenuSettingsWidget* GetMyMainMenuSettingsWidget();

	/** *  */
	UFUNCTION(BlueprintCallable, Category = "MainMenuSettingsWidget|Function")
	virtual void SetMyMainMenuSettingsWidget(UMainMenuSettingsWidget* InMainMenuSettingsWidget);

	/** *  */
	UFUNCTION(BlueprintCallable, Category = "MainMenuSettingsWidget|Function")
	virtual USettingSave* GetSettingSave(int32 UserIndex = 0);

	/** *  */
	UFUNCTION(BlueprintCallable, Category = "MainMenuSettingsWidget|Function")
	virtual bool SaveSettingSave(int32 UserIndex = 0);

	/** * 调用触发事件 */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "MainMenuSettingsWidget|Function")
	void ExtensionTrigger(int InIndex);

	/** * 调用触发事件 */
	UFUNCTION(BlueprintCallable, Category = "MainMenuSettingsWidget|Function")
	virtual void PromptText(FText InText);


};
