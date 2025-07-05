// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Attributes/TD1_BaseAS.h"
#include "AbilitySystemComponent.h"
#include "TD1_TowerAS.generated.h"

/**
 * 
 */
UCLASS()
class TD1_API UTD1_TowerAS : public UTD1_BaseAS
{
	GENERATED_BODY()
	
public:
	
	UTD1_TowerAS();

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
	FGameplayAttributeData Range;
	ATTRIBUTE_ACCESSORS(UTD1_TowerAS, Range);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
	FGameplayAttributeData FireRate;
	ATTRIBUTE_ACCESSORS(UTD1_TowerAS, FireRate);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS(UTD1_TowerAS, Damage);
};
