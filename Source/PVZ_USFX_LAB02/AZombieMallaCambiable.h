// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Zombie.h"
#include "AZombieMallaCambiable.generated.h"


UCLASS()
class PVZ_USFX_LAB02_API AAZombieMallaCambiable : public AZombie
{
	
	GENERATED_BODY()


	class AZombi;

public:
	AAZombieMallaCambiable(/*AZombi* Zombie_A_Recibir*/);


	void CambiarTamanoCuandoVidaAMitad();
private:
	AZombie* ZombieDecorado;
};
