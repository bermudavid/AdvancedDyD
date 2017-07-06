// Fill out your copyright notice in the Description page of Project Settings.

#include "Coins.h"

ACoins::ACoins()
{
//	coin = CreateDefaultSubobject<UStaticMeshComponent>(FName("Mesh"));
	this->pt = 0;
	this->g = 0;
	this->p = 0;
	this->c = 0;
}

ACoins::ACoins(int32 pt, int32 g, int32 p, int32 c)
{
	//coin = CreateDefaultSubobject<UStaticMeshComponent>(FName("Mesh"));

	this->pt = pt;
	this->g = g;
	this->p = p;
	this->c = c;
}

ACoins::~ACoins()
{
}

int32 ACoins::GetPT()
{
	return pt;
}
int32 ACoins::GetG()
{
	return g;
}
int32 ACoins::GetP() {
	return p;
}
int32 ACoins::GetC() {
	return c;
}
//Setters
void ACoins::SetPT(int32 pt)
{
	this->pt = pt;
}
void ACoins::SetG(int32 g)
{
	this->g = g;
}
void ACoins::SetP(int32 p)
{
	this->p = p; 
}
void ACoins::SetC(int32 c) 
{
	this->c = c;
}

//convertion 1
void ACoins::CtoP()
{
	if (c >= 10) {
		p = p + (c / 10);
		c = c % 10;
	}
}
void ACoins::CtoG() 
{
	if (c >= 100) {
		g = g + (c / 100);
		c = c % 100;
	}
}
void ACoins::CtoPT() 
{
	if (c >= 1000) {
		pt = pt + (c / 1000);
		c = c % 1000;
	}
}
//convertion 2
void ACoins::PtoG() {
	if (c >= 10) {
		g = g + (p / 10);
		p = p % 10;
	}
}
void ACoins::PtoC() 
{
	if (p >= 1){
		c = c + (p * 10);
	}
}
void ACoins::PtoPT() 
{
	if (p >= 100) {
		pt = pt + p / 100;
		p = p % 100;
	}
}
//convertion 3
void ACoins::GtoC() 
{
	if (g >= 1) {
		c = c + g * 100;
	}
}
void ACoins::GtoP()
{
	if (g >= 1) {
		g = g + p * 10;
	}
}
void ACoins::GtoPT()
{
	if (g >= 10) {
		pt = pt + g / 10;
		g = g % 10;
	}
}
//convertion 4
void ACoins::PTtoC()
{
	if (pt >= 1) {
		c = c + pt * 1000;
	}
}
void ACoins::PTtoP() {
	if (pt >= 1) {
		p = p + pt * 100;
	}
}
void ACoins::PTtoG() 
{
	if (pt >= 1) {
		g = g + pt * 10;
	}
}

int32 ACoins::TotalInG()
{
	int32 resP = p, resG = g;
	if (c >= 10) {
		resP = resP + (c / 10);
	}
	if (resP>= 10) {
		resG = resG + resP / 10;
	}
	if (pt >= 1) {
		resG = resG + pt * 10;
	}
	return resG;
}