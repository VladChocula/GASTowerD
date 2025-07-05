// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Attributes/TD1_BaseAS.h"
#include "GameplayEffectExtension.h"
#include "AbilitySystemBlueprintLibrary.h"

UTD1_BaseAS::UTD1_BaseAS()
{
}

void UTD1_BaseAS::PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const
{
	Super::PreAttributeBaseChange(Attribute, NewValue);

	ClampAttributeOnChange(Attribute, NewValue);
}

void UTD1_BaseAS::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	ClampAttributeOnChange(Attribute, NewValue);
}

void UTD1_BaseAS::ClampAttributeOnChange(const FGameplayAttribute& Attribute, float& NewValue) const
{

}

const void UTD1_BaseAS::SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& OutEffectProps)
{
	OutEffectProps.EffectContextHandle = Data.EffectSpec.GetContext();
	OutEffectProps.SourceASC = OutEffectProps.EffectContextHandle.GetOriginalInstigatorAbilitySystemComponent();

	if (IsValid(OutEffectProps.SourceASC) && OutEffectProps.SourceASC->AbilityActorInfo.IsValid() && OutEffectProps.SourceASC->AbilityActorInfo->AvatarActor.IsValid())
	{
		OutEffectProps.SourceAvatarActor = OutEffectProps.SourceASC->AbilityActorInfo->AvatarActor.Get();
		OutEffectProps.SourceController = OutEffectProps.SourceASC->AbilityActorInfo->PlayerController.Get();

		//In case this is a pawn and not a character
		if (OutEffectProps.SourceController == nullptr && OutEffectProps.SourceAvatarActor != nullptr)
		{
			if (const APawn* Pawn = Cast<APawn>(OutEffectProps.SourceAvatarActor))
			{
				OutEffectProps.SourceController = Pawn->GetController();
			}
		}

		if (OutEffectProps.SourceController)
		{
			OutEffectProps.SourceCharacter = Cast<ACharacter>(OutEffectProps.SourceController->GetPawn());
		}
	}

	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		OutEffectProps.TargetAvatarActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		OutEffectProps.TargetCharacter = Cast<ACharacter>(OutEffectProps.TargetAvatarActor);
		OutEffectProps.TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();
		OutEffectProps.TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(OutEffectProps.TargetAvatarActor);
	}


}
