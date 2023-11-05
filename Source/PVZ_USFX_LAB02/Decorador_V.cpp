// Fill out your copyright notice in the Description page of Project Settings.


#include "Decorador_V.h"
#include "Zombie_Interface.h"
#include "Zombie.h"
#include "Zombie_Tank.h"

void ADecorador_V::Decorar_con_V()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Vel O: %i"), this->Velocidad));
	this->Velocidad += Velocidad;
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Vel F: %i"), this->Velocidad));
}
