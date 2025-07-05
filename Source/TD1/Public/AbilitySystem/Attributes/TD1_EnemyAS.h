// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Attributes/TD1_BaseAS.h"
#include "AbilitySystemComponent.h"
#include "TD1_EnemyAS.generated.h"

/**
 * 
 */
UCLASS()
class TD1_API UTD1_EnemyAS : public UTD1_BaseAS
{
	GENERATED_BODY()
public:
	UTD1_EnemyAS();

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UTD1_EnemyAS, Health);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UTD1_EnemyAS, MaxHealth);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
	FGameplayAttributeData MoveSpeed;
	ATTRIBUTE_ACCESSORS(UTD1_EnemyAS, MoveSpeed);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS(UTD1_EnemyAS, Damage);

protected:
	virtual void ClampAttributeOnChange(const FGameplayAttribute& Attribute, float& NewValue) const override;

};
