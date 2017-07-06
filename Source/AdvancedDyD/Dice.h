// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DrawDebugHelpers.h"

/**
 * 
 */
class ADVANCEDDYD_API Dice
{

public:
	//constructors
	Dice(uint32 num ,uint32 faces);
	Dice(uint32 faces);
	Dice();
	~Dice();
	//getters & setters
	uint32 getNum();
	uint32 DoRoll();
	/**
	 * hace una tirada aleatoria de los dados almacenados
	 * @param num - número de dados más pequeños a restar
	 */
	uint32 DoRollMinusLowers(int numMinus);
private:
	uint32 num ;
	uint32 faces;

};
