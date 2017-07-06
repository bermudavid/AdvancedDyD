// Fill out your copyright notice in the Description page of Project Settings.

#include "LongSword.h"


//return true if is done and false if the owner are failed the Attack


ALongSword::ALongSword() : AWeapon_CC() {

	pg = 5;
	nombre = "Long Sword";
	daño = Dice(1, 8); // no blueprinteable
	crit = FIntVector(19, 20, 2);
	dureza = 1;
	precio = FPrice(0, 15, 0, 0);
	peso = 4;


	tipoArma = WeaponType::UNAMANO;
	claseArma = WeaponClass::MARCIAL;
	tipoDano = FTypeOfDamage(true, false, false);

}

