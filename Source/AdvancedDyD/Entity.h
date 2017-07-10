// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Dice.h"
#include "LongSword.h"
#include "Classes/Components/SplineComponent.h"
#include "Classes/Components/SplineMeshComponent.h"
#include "Entity.generated.h"


USTRUCT(BlueprintType)
struct FCharac {
	GENERATED_USTRUCT_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Caracterísrticas")
		int32 Fue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Caracterísrticas")
		int32 Dex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Caracterísrticas")
		int32 Con;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Caracterísrticas")
		int32 Int;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Caracterísrticas")
		int32 Sab;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Caracterísrticas")
		int32 Car;


public:
	FCharac() {
		
		Fue = 0;
		Dex = 0;
		Con = 0;
		Int = 0;
		Sab = 0;
		Car = 0;

	}

	void SetFue(int32 Fue) {
		this->Fue = Fue;
	}
	int32 GetFue() {
		return this->Fue;
	}
	void SetDex(int32 Dex) {
		this->Dex = Dex;
	}
	int32 GetDex() {
		return this->Dex;
	}
	void SetCon(int32 Con) {
		this->Con = Con;
	}
	int32 GetCon() {
		return this->Con;
	}
	void SetInt(int32 Int) {
		this->Int = Int;
	}
	int32 GetInt() {
		return this->Int;
	}
	void SetSab(int32 Sab) {
		this->Sab = Sab;
	}
	int32 GetSab() {
		return this->Sab;
	}
	void SetCar(int32 Car) {
		this->Car = Car;
	}
	int32 GetCar() {
		return this->Car;
	}
};

UCLASS(ABSTRACT)
class ADVANCEDDYD_API AEntity : public APawn
{
	GENERATED_BODY()



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Sets default values for this character's properties
	AEntity();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	FString nombre;
	FString AssignedTo;
	int level;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Caracterísrticas")
	AWeapon *CurrentWeapon;
	//características
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Caracterísrticas")
	FCharac characs;
//This must be a specific structure in future versions
	FString Race;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Caracterísrticas")
		int32 CA;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Caracterísrticas")
		int32 maxPG;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Caracterísrticas")
		int32 pg;
	//velocidad en pies
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Caracterísrticas")
		int32 Velocidad;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Caracterísrticas")
		class USplineComponent* PathSpline;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Caracterísrticas")
		TArray<AWeapon*> Inventory;
	
public:
	/**
	 * This method returns a mod of a characteristic
	 * @return modificator of charact
	 */
	UFUNCTION(BlueprintCallable)
	int32 GetMod(int32 charac);
	//Getters & setters

	int32 GetCA();
	void SetCA(int32 CA);

	int32 GetMaxPG();
	void SetMaxPG(int32 maxPG);

	int32 GetPG();
	void SetPG(int32 pg);
	FCharac GetCharacs();

	int32 GetVelocidad();
	void SetVelocidad(int32 velocidad);


	/**
	* Generates a random values for the characteristics 
	*/
	UFUNCTION(BlueprintCallable)
		void GenerateChars();
	UFUNCTION(BlueprintCallable)
		bool ToAttackTest(AEntity* target);
	UFUNCTION(BlueprintCallable)
		int32 DistanceToTarget(AActor* target);
	UFUNCTION(BlueprintCallable)
		int32 DistanceToTransform(FTransform target);

	
	
};

