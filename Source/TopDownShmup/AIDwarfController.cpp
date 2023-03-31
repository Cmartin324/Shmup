// Fill out your copyright notice in the Description page of Project Settings.


#include "AIDwarfController.h"
#include "Kismet/GameplayStatics.h"

void AAIDwarfController::OnPossess(APawn* InPawn) {
	
	
	enemyAttached = InPawn;
	Super::OnPossess(enemyAttached);
	
	
}

void AAIDwarfController::BeginPlay() {
	static APawn* GetPlayerPawn(Player);
	MoveToActor(Player);
	
	Super::BeginPlay();



}

