// Fill out your copyright notice in the Description page of Project Settings.


#include "DwarfCharacter.h"

ADwarfCharacter::ADwarfCharacter() {
	AIControllerClass = AAIDwarfController::StaticClass();

}




float ADwarfCharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent,
	AController* EventInstigator, AActor* DamageCauser)
{
	float ActualDamage = Super::TakeDamage(Damage, DamageEvent,
		EventInstigator, DamageCauser);
	if (ActualDamage > 0.0f)
	{
		//TODO: Add a debug message on screen to know dwarf got hit
		//Reduce health points
		Health -= ActualDamage;
		if (Health <= 0.0f)
		{
			// TODO: Process death
			// Stop attack animation,
			GetController();
			PlayAnimMontage(DeathAnim);
			SetCanBeDamaged(false); // Don't allow further damage
			GetWorldTimerManager().SetTimer(Death, this, &ADwarfCharacter::DestroyDead, 7.0f, true, 0.75f);
			
			// Remove the dwarf from the world
		}
		
	}
	return ActualDamage;
}

void ADwarfCharacter::DestroyDead() {
	Destroy();
}

