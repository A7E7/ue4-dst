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

private:
	UPROPERTY()
	TArray<TSoftObjectPtr<UObject>> StoredObjects;

public:
	UFUNCTION(BlueprintCallable)
	void StoreCrossLevelReference(UObject* ObjectToStore) 
	{ 
		TSoftObjectPtr<UObject> objectToStoreSoftPtr(ObjectToStore);
		StoredObjects.Add(objectToStoreSoftPtr);
	}

	UFUNCTION(BlueprintCallable)
	const TArray<TSoftObjectPtr<UObject>> GetSoftObjects()
	{
		return StoredObjects;
	}
	
};
