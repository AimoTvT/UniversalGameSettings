// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SettingSave.generated.h"

/**
 * 
 */
UCLASS()
class UNIVERSALGAMESETTINGS_API USettingSave : public USaveGame
{
	GENERATED_BODY()
	
public:

	/** *  */
	UPROPERTY(BlueprintReadWrite, Category = "SettingSave|Variable")
	float MobileContentScaleFactor = 0.5f;


	/** *  */
	UPROPERTY(BlueprintReadWrite, Category = "SettingSave|Variable")
	float AllSoundVolume = 1.0f;

	/** *  */
	UPROPERTY(BlueprintReadWrite, Category = "SettingSave|Variable")
	float MusicSoundVolume = 1.0f;

	/** *  */
	UPROPERTY(BlueprintReadWrite, Category = "SettingSave|Variable")
	float SFXSoundVolume = 1.0f;

	/** *  */
	UPROPERTY(BlueprintReadWrite, Category = "SettingSave|Variable")
	float VoiceSoundVolume = 1.0f;


};
