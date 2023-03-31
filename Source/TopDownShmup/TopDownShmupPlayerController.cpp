// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "TopDownShmupPlayerController.h"
#include "TopDownShmup.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

ATopDownShmupPlayerController::ATopDownShmupPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void ATopDownShmupPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	updateMouseLook();
	// keep updating the destination every tick while desired
	if (bMoveToMouseCursor)
	{
		//MoveToMouseCursor();
	}
}

void ATopDownShmupPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();
	InputComponent->BindAxis("MoveForward", this, &ATopDownShmupPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ATopDownShmupPlayerController::MoveRight);
	InputComponent->BindAction("Fire", IE_Pressed, this, &ATopDownShmupPlayerController::OnStartFire);
	InputComponent->BindAction("Fire", IE_Released, this, &ATopDownShmupPlayerController::OnStopFire);


	
}


void ATopDownShmupPlayerController::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		APawn* const Pawn = GetPawn();
		if (Pawn)
		{
			Pawn->AddMovementInput(FVector(1.0f, 0.0f, 0.0f), Value);
		}
	}
}

void ATopDownShmupPlayerController::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		APawn* const Pawn = GetPawn();
		if (Pawn)
		{
			Pawn->AddMovementInput(FVector(0.0f, 1.0f, 0.0f), Value);
		}
	}
}

void ATopDownShmupPlayerController::OnStartFire() {
	APawn* const Pawn = GetPawn();
	ATopDownShmupCharacter* MyCharacter = Cast<ATopDownShmupCharacter>(Pawn);
	MyCharacter->OnStartFire();
	
	
}
void ATopDownShmupPlayerController::OnStopFire() {
	APawn* const Pawn = GetPawn();
	if (Pawn) {
		ATopDownShmupCharacter* MyCharacter = Cast<ATopDownShmupCharacter>(Pawn);
		MyCharacter->OnStopFire();
	}
}





void ATopDownShmupPlayerController::updateMouseLook() {
	APawn* const Pawn = GetPawn();
	if (Pawn) {

		// Trace to see what is under the mouse cursor
		FHitResult Hit;
		GetHitResultUnderCursor(ECC_Visibility, false, Hit);

		if (Hit.bBlockingHit)
		{
			FVector turnToMouse = Hit.ImpactPoint - Pawn->GetActorLocation();
			turnToMouse.Z = 0.0f;
			turnToMouse.GetSafeNormal(1.0f);
			turnToMouse.Normalize(1.0f);
			FVector normalized;
			normalized = turnToMouse;
			FRotator rotator = normalized.Rotation();
			Pawn->SetActorRotation(rotator);
		}

	}



}