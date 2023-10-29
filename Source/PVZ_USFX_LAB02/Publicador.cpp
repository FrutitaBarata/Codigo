// Fill out your copyright notice in the Description page of Project Settings.


#include "Publicador.h"
#include "Suscriptor.h"

// Sets default values
APublicador::APublicador()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APublicador::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APublicador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APublicador::Suscribirse(AActor* Suscriptor)
{
	//Add the passed Subscriber
	Suscriptores.Add(Suscriptor);

}

void APublicador::Desuscribirse(AActor* SuscriptorAQuitar)
{
	//Remove the passed Subscriber
	Suscriptores.Remove(SuscriptorAQuitar);

}

void APublicador::NotificarSuscriptores()
{
	//Loop for each Subscriber
	for (AActor* Actor : Suscriptores)
	{
		//Cast each of them to a concrete Subscriber
		ISuscriptor* Sub = Cast<ISuscriptor>(Actor);
		if (Sub)
		{
			//Notify each of them that something has changed, so they can execute their own routine
			Sub->NotificarZombieEnRango(this);
		}
	}
}

