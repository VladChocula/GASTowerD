// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "TD1.generated.h"

UENUM(BlueprintType)
enum class EEnemyType : uint8
{
	None,
	Green,
	Purple,
	Red,
	Yellow
};

USTRUCT(BlueprintType)
struct FWaveData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float StartTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EEnemyType EnemyType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 SpawnCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SpawnDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DelayRemaining;
};