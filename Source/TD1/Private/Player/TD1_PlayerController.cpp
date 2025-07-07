// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/TD1_PlayerController.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

ATD1_PlayerController::ATD1_PlayerController()
{
}

void ATD1_PlayerController::BeginPlay()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
}

void ATD1_PlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;

	//TODO: Move Highlight base tower functionality into Cursor Trace function here.
}
