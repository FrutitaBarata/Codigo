// Fill out your copyright notice in the Description page of Project Settings.


#include "NotificarPlantas.h"

void ANotificarPlantas::EstadoCambiado()
{
	//When the time has changed, this Clock Tower (that is a Publisher) notifies to all the subscribers that the time has changed
	NotificarSuscriptores();

}

void ANotificarPlantas::DefinirEstado(FString myEstado)
{
	//Set the time using the passed parameter and warn that it's changed
	Estado = myEstado;
	EstadoCambiado();
}
