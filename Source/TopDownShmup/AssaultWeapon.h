// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "TimerManager.h"
#include "DwarfCharacter.h"
#include "AssaultWeapon.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNSHMUP_API AAssaultWeapon : public AWeapon
{
	GENERATED_BODY()
	virtual void OnStartFire() override;
	virtual void OnStopFire() override;
	float Damage = 2;
	float FireRate = 0.05f;
	float WeaponRange = 10000.0f;
	UPROPERTY(EditDefaultsOnly)
	UParticleSystem* HitEffect;
	FTimerHandle fire;
	
protected:
	void WeaponTrace();

};
