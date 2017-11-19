// Fill out your copyright notice in the Description page of Project Settings.

#include "DsGameInstance.h"
#include "DsSaveGame.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/SoftObjectPtr.h"
#include "Serialization/ArchiveUObject.h"

bool UDsGameInstance::Save()
{
	if (!SaveGame)
	{
		SaveGame = Cast<UDsSaveGame>(UGameplayStatics::CreateSaveGameObject(UDsSaveGame::StaticClass()));
	}

	return UGameplayStatics::SaveGameToSlot(SaveGame, SlotSaveName, 0);
}

UDsSaveGame* UDsGameInstance::GetSaveGame()
{
	if (SaveGame)
		return SaveGame;

	if(UGameplayStatics::DoesSaveGameExist(SlotSaveName, 0))
	{
		SaveGame = Cast<UDsSaveGame>(UGameplayStatics::LoadGameFromSlot(SlotSaveName, 0));
	}
	else
	{
		SaveGame = Cast<UDsSaveGame>(UGameplayStatics::CreateSaveGameObject(UDsSaveGame::StaticClass()));
		UGameplayStatics::SaveGameToSlot(SaveGame, SlotSaveName, 0);
	}

	return SaveGame;
}

bool UDsGameInstance::ClearSaveGame()
{
	return UGameplayStatics::DeleteGameInSlot(SlotSaveName, 0);

}

void UDsGameInstance::RegisterVanishedObject(UObject* Object)
{
	GetSaveGame()->StoreCrossLevelReference(Object);
	Save();
}

