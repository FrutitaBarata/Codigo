// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Decorador_Zombie.h"
#include "Decorador_V.generated.h"

/**
 * 
 */
UCLASS()
class PVZ_USFX_LAB02_API ADecorador_V : public ADecorador_Zombie
{
	GENERATED_BODY()
public:
	ADecorador_V();
	void Decorar_con_V(class AZombie_con_V* ZZ);
	int Energia;
	int GetEnergia() { return Energia; };
	ADecorador_V* Decorador_V;
};
