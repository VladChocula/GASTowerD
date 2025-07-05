// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Attributes/TD1_EnemyAS.h"

UTD1_EnemyAS::UTD1_EnemyAS()
	: Health(10.f),
	MaxHealth(10.f),
	MoveSpeed(100.f),
	Damage(10.f)
{
}

void UTD1_EnemyAS::ClampAttributeOnChange(const FGameplayAttribute& Attribute, float& NewValue) const
{

}
