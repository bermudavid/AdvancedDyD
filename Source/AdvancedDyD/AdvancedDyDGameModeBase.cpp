// Fill out your copyright notice in the Description page of Project Settings.

#include "AdvancedDyDGameModeBase.h"


void AAdvancedDyDGameModeBase::BeginPlay(){
	
	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
	
	//GetWorld()->SpawnActor<AEntity>(Location, Rotation, SpawnInfo);
}
