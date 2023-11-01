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
#include "Zombie_Tank.h"
#include "NotificarPlantas.h"
#include "AZombieMallaCambiable.h"


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

	
	//-------------------------------------------------------------------------------
	RangoAtaque = 300.0f;

}

void APVZ_USFX_LAB02GameModeBase::BeginPlay()
{
	Super::BeginPlay();
	//-------------------------------------------------------------------------------

	 Notificador = GetWorld()->SpawnActor<ANotificarPlantas>(ANotificarPlantas::StaticClass(), FVector(0, 0, 0), FRotator::ZeroRotator);


	//Definiendo la posición de los zombies
	FVector SpawnLocationZombie = FVector(-920.0f, 600.0f, 22.0f);
	//for (int i = 0; i < 5; i++) {
	//	// Define una posición temporal para el zombie en X
	//	SpawnLocationZombie.X += 100;

	//	NuevoZombie = GetWorld()->SpawnActor<AZombieComun>(AZombieComun::StaticClass(), SpawnLocationZombie, FRotator::ZeroRotator);

	//	NuevoZombie->Velocidad = 0.1f;
	//	
	//	
	//		Zombies.Add(NuevoZombie);
	//		//-------------------------------------------------------------------------------
	//		NuevoZombie->Columna_Zombie = i ;
	//}
	

	for (int i = 0; i < 5; i++) {
		// Define una posición temporal para el zombie en X
		SpawnLocationZombie.X += 100;

		NuevoZombie_Decorado = GetWorld()->SpawnActor<AZombie_Tank>(AZombie_Tank::StaticClass(), SpawnLocationZombie, FRotator::ZeroRotator);

		NuevoZombie_Decorado->Velocidad = 0.1f;


		Zombies_Decorados.Add(NuevoZombie_Decorado);
		//-------------------------------------------------------------------------------
		NuevoZombie_Decorado->Columna_Zombie = i;

		


	}
	

	//Definiendo la posición de las plantas
	FVector SpawnLocationPlant = FVector(-920.0f, -600.0f, 22.0f);
	SpawnLocationPlantTemp = SpawnLocationPlant;

	// Genera 5 plantas
	for (int i = 0; i < 5; i++)
	{
		SpawnLocationPlantTemp.X += 100;
			
			NuevaPlantaGuisante = GetWorld()->SpawnActor<ALanza_Guisantes>(ALanza_Guisantes::StaticClass(), SpawnLocationPlantTemp, FRotator::ZeroRotator);

			Plantas2.Add(NuevaPlantaGuisante);


			//-------------------------------------------------------------------------------
			NuevaPlantaGuisante->DefinirNotificarPlantas(Notificador);
			NuevaPlantaGuisante->Columna_Planta = i;
	}
	

		
	
	
	
}




void APVZ_USFX_LAB02GameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	for (AZombie * Zombie : Zombies_Decorados) {
		
		for (APlant* Planta : Plantas2) {
			/*FVector LocalizacionZombies = Zombie->GetActorLocation();*/
			if (Zombie->Columna_Zombie==Planta->Columna_Planta /*&& FMath::Abs(LocalizacionZombies.Y) <= RangoAtaque*/) {

				Notificador->DefinirEstado("Zombie a la vista");
				/*GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("la columna z es:%i, lac de p es: %i "), Zombie->Columna_Zombie, Planta->Columna_Planta));*/
				
			}
			else {
				if (Zombies_Decorados.Num() > 0) {
					if (NuevoZombie_Decorado->IsActorDestroyed()) {
						GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("son: %i"), Zombies_Decorados.Num()));
						Zombies_Decorados.Remove(Zombie);
						GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("El zombie fue removido: %i"), Zombies_Decorados.Num() ));
						
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




