// Fill out your copyright notice in the Description page of Project Settings.

#include "Entity.h"
#include "DrawDebugHelpers.h"


// Sets default values
AEntity::AEntity()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void AEntity::BeginPlay()
{
	Super::BeginPlay();
	CurrentWeapon = NewObject<ALongSword>();

}

// Called every frame
void AEntity::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEntity::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

int32 AEntity::GetMod(int32 charac) {
	return floor(charac / 2 - 5);
}
void AEntity::GenerateChars() {
	int32 tiradas[7] = { 0,0,0,0,0,0,0 };
	Dice dices = Dice(4, 6);

	for (int i = 0; i < 7; i++) {
		tiradas[i] = dices.DoRollMinusLowers(1);
	}

	characs.SetFue(tiradas[0]);
	characs.SetDex(tiradas[1]);
	characs.SetCon(tiradas[2]);
	characs.SetInt(tiradas[3]);
	characs.SetSab(tiradas[4]);
	characs.SetCar(tiradas[5]);
}

int32 AEntity::GetCA() {
	return this->CA;
}

void AEntity::SetCA(int32 CA) {
	this->CA = CA;
}
int32 AEntity::GetPG() {
	return pg;
}
void AEntity::SetPG(int32 pg) {
	this->pg = pg;
}

int32 AEntity::GetMaxPG() {
	return maxPG;
}
void AEntity::SetMaxPG(int32 maxPG) {
	this->maxPG = maxPG;
}

FCharac AEntity::GetCharacs() {
	return characs;
}



/**
 * @return distance to target in ft.
 */
int32 AEntity::DistanceToTarget(AActor * target) {
	
	DrawDebugDirectionalArrow(
		GetWorld(),
		GetActorLocation(),
		target->GetActorLocation(),
		500,
		FColor(200, 200, 200),
		true, -1, 0,
		4
	);
	FVector InitPoint = GetActorLocation();
	FVector EndPoint = target->GetActorLocation();

	FVector dif = GetActorLocation() - target->GetActorLocation();
	//para hayar la distancia necesitamos el tamaño de la diferencia de vectores
	float size = dif.Size();
	// para pasar a pies sabemos que cada 100 de distancia son 5 pies, porque 100 mide cada casilla de centro a centro)
	int32 ftsize = int32((size / 100) * 5);

	DrawDebugString(
		GetWorld(),
		FVector(
			(InitPoint.X + EndPoint.X) / 2,
			(InitPoint.Y + EndPoint.Y) / 2,
			(InitPoint.Z + EndPoint.Z) / 2 +25
		),
		FString::FromInt(ftsize).Append(" ft."),
		NULL,
		FColor::White,
		-1.0f
	);



	
	return ftsize; // puede que haya que redondear a múltiplos de 5
}


bool AEntity::ToAttackTest(AEntity* target) {
	TArray<FVector> arra = { 
		FVector(0,0,0),
		FVector(100,0,0),
		FVector(-100,0,0),
		FVector(0,100,0),
		FVector(0,-100,0),
		FVector(0,0,100),
		FVector(0,0,-100),
		FVector(-15,10,25)
	};
	/*
	DrawDebugBox(
		GetWorld(),
		target->GetActorLocation(),
		target->GetActorLocation()+100,
		FColor::White,
		true
	);*/
	DrawDebugCone(
		GetWorld(),
		GetActorLocation(),
		(GetActorLocation() - target->GetActorLocation())*-1,
		600.f, //30ft
		.5f,
		.5f,
		8,
		FColor::White,
		true
	);


 	FBox box = FBox(arra);
	/*
	DrawDebugSolidBox(
		GetWorld(),
		box,
		FColor::White,
		FTransform::Identity,
		true
		
	);*/


	Dice d20 = Dice(1, 20);
	uint32 attackRoll = d20.DoRoll();
	FCharac characs = this->GetCharacs();
	int32 modFue = this->GetMod(characs.GetFue());

	/*
	if (AWeapon_CC* weaponcc = dynamic_cast<AWeapon_CC*>(&CurrentWeapon)) {
		//this is a cc weapon;
		//get distance in ft
	}
	*/

	if (int32((attackRoll + modFue)) >= target->GetCA()) {	
		int32 damage = int32(CurrentWeapon->GetDano()) + modFue;
		target->SetPG(target->GetPG() - damage);
		return true;
	}
	else {
		return false;
	}
	
}