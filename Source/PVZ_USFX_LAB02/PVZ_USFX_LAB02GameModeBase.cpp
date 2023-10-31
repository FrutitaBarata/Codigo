// Copyright Epic Games, Inc. All Rights Reserved.


#include "PVZ_USFX_LAB02GameModeBase.h"
#include "Spawns.h"
#include "Zombie.h"
#include "Plant.h"
//#include "Sol.h"
#include "Math/UnrealMathUtility.h"
#include "Engine/Engine.h"
#include "TimerManager.h"

#include "Jugador.h"
#include "Controlador.h"
#include "HUDPlantas.h"


#include "Planta_Ataque.h"
#include "Lanza_Guisantes.h"

#include "ZombieComun.h"

#include "NotificarPlantas.h"



APVZ_USFX_LAB02GameModeBase::APVZ_USFX_LAB02GameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;



	//Definiendo el Pawn o Peon
	DefaultPawnClass = AJugador::StaticClass();
	//Definiendo el Controlador
	PlayerControllerClass = AControlador::StaticClass();
	//Definiendo el HUD
	//HUDClass = AHUDPlantas::StaticClass();



	contador = FVector(0, 0, 0);
	localizacion = FVector(400.0, 200.0, 100.0);
	contador2 = 0;

	TiempoTranscurrido = 0.0f;

	RangoAtaque = 2000.0f;



}

void APVZ_USFX_LAB02GameModeBase::BeginPlay()
{
	Super::BeginPlay();


	Notificador = GetWorld()->SpawnActor<ANotificarPlantas>(ANotificarPlantas::StaticClass(), FVector(0, 0, 0), FRotator::ZeroRotator);


	//Definiendo la posici�n de los zombies
	FVector SpawnLocationZombie = FVector(-920.0f, 600.0f, 22.0f);

	for (CantidadZombies = 0; CantidadZombies < 4; CantidadZombies++) {
		// Define una posici�n temporal para el zombie en X
		SpawnLocationZombie.X += 200;

		NuevoZombie = GetWorld()->SpawnActor<AZombieComun>(AZombieComun::StaticClass(), SpawnLocationZombie, FRotator::ZeroRotator);

		NuevoZombie->Velocidad = 0.1f;

		NuevoZombie->energia = FMath::RandRange(100, 200);

		Zombies.Add(NuevoZombie);

		NuevoZombie->Columna_Zombie = CantidadZombies;
	}




	//Definiendo la posici�n de las plantas
	FVector SpawnLocationPlant = FVector(-920.0f, -600.0f, 22.0f);
	SpawnLocationPlantTemp = SpawnLocationPlant;

	// Genera 5 plantas
	for (CantidadPlantas = 0; CantidadPlantas < 4; CantidadPlantas++)
	{
		SpawnLocationPlantTemp.X += 200;



		NombrePlanta = FString::Printf(TEXT("Planta %d"), CantidadPlantas + 1); // Cambio en la generación del nombre

		// Genera una planta en la posicion temporal
		NuevaPlantaGuisante = GetWorld()->SpawnActor<ALanza_Guisantes>(ALanza_Guisantes::StaticClass(), SpawnLocationPlantTemp, FRotator::ZeroRotator);

		Plantas2.Add(NuevaPlantaGuisante);

		// Agrega la planta al contenedor de plantas
		Plantas.Add(NombrePlanta, NuevaPlantaGuisante);

		NuevaPlantaGuisante->DefinirNotificarPlantas(Notificador);

		NuevaPlantaGuisante->Columna_Planta = CantidadPlantas;

		//Mensaje con el nombre de la planta
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Planta: %s"), *NombrePlanta));


	}



}




void APVZ_USFX_LAB02GameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);



	for (AZombie* Zombie : Zombies) {

		for (APlant* Planta : Plantas2) {

			FVector LocalizacionZombies = Zombie->GetActorLocation();

			if (Zombie->Columna_Zombie == Planta->Columna_Planta && FMath::Abs(LocalizacionZombies.Y) <= RangoAtaque) {

				Notificador->DefinirEstado("Zombie a la vista");
				//Mostrando el estado de cada planta

				//Plantas["Planta 1"]->Estado = Notificador->GetEstado();
				//Plantas["Planta 2"]->Estado = Notificador->GetEstado();


				//Plantas2[1]->Columna_Planta = Zombies[1]->Columna_Zombie;

				Plantas2[2]->Estado = Notificador->GetEstado();

				GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("El estado de la %s es: %s"), *NombrePlanta, *Plantas[NombrePlanta]->Estado));


				/*GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("la columna z es:%i, lac de p es: %i "), Zombie->Columna_Zombie, Planta->Columna_Planta));*/

			}
			else {
				if (Zombies.Num() > 0) {
					if (NuevoZombie->IsActorDestroyed()) {
						GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("son: %i"), Zombies.Num()));
						Zombies.Remove(Zombie);
						//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("El zombie fue removido: %i"), Zombies.Num()));

					}
				}
				else {
					GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("El codigo deberia terminar")));
					Notificador->DefinirEstado("Zombie sin vista");

				}

			}
		}
	}





}





void APVZ_USFX_LAB02GameModeBase::Spawn()
{


}

void APVZ_USFX_LAB02GameModeBase::aumentovelocidad()
{


}

void APVZ_USFX_LAB02GameModeBase::MostrarEnergiaDePlantas()
{
}

