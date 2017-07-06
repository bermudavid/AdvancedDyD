// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Coins.generated.h"
/**
 * 
 */
UCLASS()
class ADVANCEDDYD_API ACoins: public AActor
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
	/*
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Item Config")
		class UStaticMeshComponent* coin;
	*/
	ACoins();
	ACoins(int32 pt, int32 g,int32 p, int32 c);
	~ACoins();
	//Getters
	UFUNCTION(BlueprintCallable, Category = Properties)
		int32 GetPT();
	UFUNCTION(BlueprintCallable, Category = Properties)
		int32 GetG();
	UFUNCTION(BlueprintCallable, Category = Properties)
		int32 GetP();
	UFUNCTION(BlueprintCallable, Category = Properties)
		int32 GetC();
	//Setters
	void SetPT(int32 pt);
	void SetG(int32 g);
	void SetP(int32 p);
	void SetC(int32 c);

	//convertion 1
	void CtoP();
	void CtoG();
	void CtoPT();
	//convertion 2
	void PtoG();
	void PtoC();
	void PtoPT();
	//convertion 3
	void GtoC();
	void GtoP();
	void GtoPT();
	//convertion 4
	void PTtoC();
	void PTtoP();
	void PTtoG();


	UFUNCTION(BlueprintCallable, Category = Properties)
	int32 TotalInG();

	

};
