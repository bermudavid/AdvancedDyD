// Fill out your copyright notice in the Description page of Project Settings.
//#define D(x) if(GEngine){GEngine->AddOnScreenDebugMessage(-1, 12.0f, FColor::Yellow, FString(x));}
#include "Weapon.h"

AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ItemStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Mesh"));
	this->daño = Dice(1, 1); //1d1

}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	FString NewString = FString::FromInt(daño.DoRoll());
	//D(NewString);
	
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AWeapon::SetDano(Dice dice) {
	this->daño = dice;
}
uint32 AWeapon::GetDano() {
	return this->daño.DoRoll();
}


#if WITH_EDITOR
void AWeapon::PostEditChangeProperty(FPropertyChangedEvent & PropertyChangedEvent) {
	Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif
