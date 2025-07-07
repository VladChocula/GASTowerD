// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TD1_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TD1_API ATD1_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	ATD1_PlayerController();

protected:
	
	virtual void BeginPlay() override;

private:
	
	void CursorTrace();
	
};
