// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sound/SoundCue.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"
#include "TopDownShmup.h"

#include "Weapon.generated.h"

UCLASS()
class TOPDOWNSHMUP_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Weapon);
	USkeletalMeshComponent* WeaponMesh;
	UPROPERTY(EditDefaultsOnly, Category = Sound);
	USoundCue* FireLoopSound;
	UPROPERTY(EditDefaultsOnly, Category = Sound);
	USoundCue* FireFinishSound;
	UAudioComponent* AC;
	UParticleSystemComponent* Muzz;
	UPROPERTY(EditDefaultsOnly, Category = Effects);
	UParticleSystem* MuzzleFX;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UAudioComponent* PlayWeaponSound(USoundCue* Sound);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void OnStartFire();
	virtual void OnStopFire();
	APawn* MyPawn;
};
