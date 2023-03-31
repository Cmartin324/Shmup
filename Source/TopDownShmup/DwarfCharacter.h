// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyCharacter.h"
#include "AIDwarfController.h"
#include "Animation/AnimMontage.h"
#include "DwarfCharacter.generated.h"


/**
 * 
 */
UCLASS()
class TOPDOWNSHMUP_API ADwarfCharacter : public AEnemyCharacter
{
	GENERATED_BODY()
	ADwarfCharacter();
	UPROPERTY(EditAnywhere, Category = Health);
	float Health = 20;
	UPROPERTY(EditDefaultsOnly, Category = Death);
	UAnimMontage* DeathAnim;
	void OnAnimationEnded(UAnimMontage* DeathAnim, bool bInterrupted);
	float score = 0;
	FTimerHandle Death;
	void DestroyDead();
	
public:
	virtual float TakeDamage(float, const FDamageEvent&, AController*, AActor*) override;
	

	
};
