// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/TD1_TowerPawn.h"
#include "AbilitySystemComponent.h"

// Sets default values
ATD1_TowerPawn::ATD1_TowerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = StaticMeshComp;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComp");

}

// Called when the game starts or when spawned
void ATD1_TowerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

UAbilitySystemComponent* ATD1_TowerPawn::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ATD1_TowerPawn::InitializeASC()
{
	if (HasAuthority() && DefaultAbility)
	{
		AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(DefaultAbility, 1, -1, this));
	}

	FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
	EffectContext.AddSourceObject(this);

	FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(DefaultEffect, 1, EffectContext);
	if (SpecHandle.IsValid())
	{
		AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
	}
}

// Called every frame
void ATD1_TowerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATD1_TowerPawn::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	AbilitySystemComponent->InitAbilityActorInfo(this, this);

	InitializeASC();
}

