// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AdvancedDyDGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCEDDYD_API AAdvancedDyDGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
		int32 funciona;
	void BeginPlay() override;


};
