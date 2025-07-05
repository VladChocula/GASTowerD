// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/TD1_PlayerPawn.h"

// Sets default values
ATD1_PlayerPawn::ATD1_PlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATD1_PlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATD1_PlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATD1_PlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

