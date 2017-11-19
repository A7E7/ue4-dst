// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "Serialization/ArchiveUObject.h"
#include "UObject/SoftObjectPtr.h"
#include "DsSaveGame.generated.h"

UCLASS()
class DARKSOULSPLAYGROUND_API UDsSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UFUNCTION()
		void StoreCrossLevelReference(UObject* ObjectToStore) 
	{ 
		FSoftObjectPtr MyPointer(ObjectToStore);
		ToBinary << ;
	}

private:
	FArchiveUObject ToBinary;


	//UFUNCTION()
	//	const TArray<FArchiveUObject> GetSoftObjects()
	//{
	//	// StoredObject
	//}
	
};
