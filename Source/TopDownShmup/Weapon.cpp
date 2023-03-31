// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"


// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = WeaponMesh;
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Gun"));
	
}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
UAudioComponent* AWeapon::PlayWeaponSound(USoundCue* Sound)
{
	UAudioComponent* AC = NULL;
	if (Sound)
	{
		AC = UGameplayStatics::SpawnSoundAttached(Sound, RootComponent);
	}
	return AC;
}
void AWeapon::OnStartFire() {
	AC = PlayWeaponSound(FireLoopSound);
	Muzz= UGameplayStatics::SpawnEmitterAttached(MuzzleFX, RootComponent, TEXT("MuzzleFlashSocket"));

	
}
void AWeapon::OnStopFire() {
	
	AC->Stop();
	PlayWeaponSound(FireFinishSound);
	Muzz->DeactivateSystem();

}



