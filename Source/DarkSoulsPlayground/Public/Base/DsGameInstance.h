// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "DsGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class DARKSOULSPLAYGROUND_API UDsGameInstance : public UGameInstance
{
	GENERATED_BODY()

#pragma region Save
public:
	UPROPERTY(EditDefaultsOnly, Category = Save)
		FString SlotSaveName;

	UFUNCTION(BlueprintCallable, Category = Save)
		bool Save();

	UFUNCTION(BlueprintCallable, Category = Save)
		class UDsSaveGame* GetSaveGame();

	UFUNCTION(BlueprintCallable, Category = Save)
		bool ClearSaveGame();

	UFUNCTION(BlueprintCallable, Category = Save)
		void RegisterVanishedObject(UObject* Object);

private:
	UPROPERTY()
		UDsSaveGame* SaveGame;

#pragma endregion
};
