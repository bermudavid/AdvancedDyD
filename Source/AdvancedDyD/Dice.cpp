// Fill out your copyright notice in the Description page of Project Settings.

#include "Dice.h"

Dice::Dice()
{
}

Dice::Dice(uint32 num, uint32 faces)
{
	this->num = num;
	this->faces = faces;
}
Dice::Dice(uint32 faces)
{
	num = 1;
	this->faces = faces;
}
Dice::~Dice()
{
}
uint32 Dice::getNum() {
	return this->num;
}

uint32 Dice::DoRoll()
{
	uint32 res = 0;
	FMath a = FMath();
	
	for (uint32 i = 0; i < getNum();i = i +1) {
		res = res + uint32(a.RandRange(1,faces));
	}
	return res;
	
}

uint32 Dice::DoRollMinusLowers(int numMinus)
{
	if ((num - numMinus) <= 0) {
		return 0;
	}

	uint32 * split_results = new uint32[num];
	uint32 res = 0;
	FMath a = FMath();

	for (uint32 i = 0; i < num; i++) {
		split_results[i] = a.RandRange(1, faces);
	}


	for (uint32 i = 0; i < num; i++) {
		uint32 mayor = split_results[0];
		uint32 aux=0;



		if (i == 0) {
		
		}
		else {
			if (mayor < split_results[i]) {
				aux = split_results[i];
				split_results[i] = mayor;
				split_results[i - 1] = aux;
				mayor = split_results[i];
			}
		}

	}
	for (uint32 i = 0; i < num - numMinus; i++ ) {
		res += split_results[i];	
	}
	delete[] split_results;
	return res;
}
