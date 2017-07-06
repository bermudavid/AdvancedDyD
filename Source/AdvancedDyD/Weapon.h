// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
#include "Dice.h"
#include "Coins.h"
#include "Weapon.generated.h"

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class WeaponType : uint8
{
	LIGERA UMETA(DisplayName = "Ligera"),
	UNAMANO UMETA(DisplayName = "Una Mano"),
	DOSMANOS UMETA(DisplayName = "Dos Manos"),
	DISTANCIA UMETA(DisplayName = "A Distancia")
};
UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class WeaponClass : uint8
{
	SENCILLA UMETA(DisplayName = "Sencilla"),
	MARCIAL UMETA(DisplayName = "Marcial"),
	EXOTICA UMETA(DisplayName = "Exotica")
};
USTRUCT(BlueprintType)
struct FPrice
{

	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Coins")
		int32 pt;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Coins")
		int32 g;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Coins")
		int32 p;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Coins")
		int32 c;
public:
	FPrice() {
		pt = 0;
		g = 0;
		p = 0;
		c = 0;
	}
	FPrice(int32 pt, int32 g, int32 p, int32 c) {
		this->pt = pt;
		this->g = g;
		this->p = p;
		this->c = c;
	}
};

USTRUCT(BlueprintType)
struct FTypeOfDamage
{
	GENERATED_USTRUCT_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Propiedades")
		bool cortante;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Propiedades")
		bool perforante;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Propiedades")
		bool contundente;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Propiedades")
		bool noLetal;
		
		
public:
	/**
	 * init the class
	 */
	FTypeOfDamage() {
		
		cortante = false;
		
		perforante = false;

		contundente = false;
		noLetal = false;
	}
	FTypeOfDamage(bool cort, bool perf, bool cont) {
		cortante = cort;
		perforante = perf;
		contundente = cont;
		noLetal = false;
	}
	void SwitchNoLetal() {
		if (noLetal) {
			noLetal = false;
		}else {
			noLetal = true;
		}
	}
};

UCLASS(ABSTRACT)
class ADVANCEDDYD_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	//constructor and methods
	AWeapon();
	//Properts
protected:
	
	Dice daño;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Item Config")
		class UStaticMeshComponent* ItemStaticMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Propiedades")
		FName nombre;
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Propiedades")
		int32 dureza;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Propiedades")
		int32 pg = 2; // pg = pg/2 cat-, pg*2 cat+ 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Propiedades")
		int32 size; //Enum or Structure

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Propiedades")
		WeaponType tipoArma;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Propiedades")
		float peso;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Propiedades")
		FTypeOfDamage tipoDano;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Propiedades")
		WeaponClass claseArma; //min, max, mult
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Propiedades")
		FIntVector crit = FIntVector(20, 20, 2); //min, max, mult
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Propiedades")
		FPrice precio; //min, max, mult

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void PostEditChangeProperty(FPropertyChangedEvent & PropertyChangedEvent);
	//Change to Entity that inherits from APawn Class
	void SetDano(Dice dice);
	uint32 GetDano();
};
