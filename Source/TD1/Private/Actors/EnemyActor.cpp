// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/EnemyActor.h"
#include "AbilitySystem/Attributes/TD1_EnemyAS.h"

// Sets default values
AEnemyActor::AEnemyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = StaticMeshComp;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");

	EnemyAttributeSet = CreateDefaultSubobject<UTD1_EnemyAS>("EnemyAttributeSet");

}

// Called when the game starts or when spawned
void AEnemyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

UAbilitySystemComponent* AEnemyActor::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

// Called every frame
void AEnemyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemyActor::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

