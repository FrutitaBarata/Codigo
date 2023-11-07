// Fill out your copyright notice in the Description page of Project Settings.


#include "Decorador_V.h"
#include "Zombie_Interface.h"
#include "Zombie.h"
#include "Zombie_Tank.h"
#include "Zombie_con_V.h"
#include "Decorador_Zombie.h"

ADecorador_V::ADecorador_V()
{
	Energia = 100;
}

void ADecorador_V::Decorar_con_V(AZombie_con_V* ZZ)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("halo? :%i "), ZZ->energia));
	ZZ->energia = 100;
	/*GetEnergia();*/
	
	
}
