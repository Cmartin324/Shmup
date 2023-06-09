// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIEnemyController.h"

#include "AIDwarfController.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNSHMUP_API AAIDwarfController : public AAIEnemyController
{
	GENERATED_BODY()
	APawn* enemyAttached;
	virtual void OnPossess(APawn* InPawn) override;
	virtual void BeginPlay() override;
	
	APawn* Player;

	
};
