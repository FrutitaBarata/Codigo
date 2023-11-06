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
#include "Decorador_Zombie.h"

#include "Decorador_V.h"
#include "Planta_Ataque.h"
#include "Lanza_Guisantes.h"
#include "Power_Ups.h"
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
	 Decorador_V = GetWorld()->SpawnActor<ADecorador_V>(ADecorador_V::StaticClass(), FVector(0, 0, 0), FRotator::ZeroRotator);

	//Definiendo la posición de los zombies
	// FVector SpawnLocationZombie = FVector(-920.0f, 600.0f, 22.0f);
	//for (int i = 0; i < 5; i++) {
	//	// Define una posición temporal para el zombie en X
	//	SpawnLocationZombie.X += 100;

	//	NuevoZombie_Decorado = GetWorld()->SpawnActor<AZombie>(AZombie::StaticClass(), SpawnLocationZombie, FRotator::ZeroRotator);

	//	NuevoZombie_Decorado->Velocidad = 0.1f;
	//	
	//	
	//		Zombies.Add(NuevoZombie_Decorado);
	//		//-------------------------------------------------------------------------------
	//		NuevoZombie_Decorado->Columna_Zombie = i ;
	//}
	 FVector SpawnLocationZombie = FVector(-920.0f, 600.0f, 22.0f);

	for (int i = 0; i < 5; i++) {
		// Define una posición temporal para el zombie en X
		SpawnLocationZombie.X += 100;

		NuevoZombie_Decorado = GetWorld()->SpawnActor<AZombie_Tank>(AZombie_Tank::StaticClass(), SpawnLocationZombie, FRotator::ZeroRotator);

		NuevoZombie_Decorado->Velocidad = 0.1f;


		Zombies_Decorados.Add(NuevoZombie_Decorado);
		//-------------------------------------------------------------------------------
		NuevoZombie_Decorado->Columna_Zombie = i;

	}
	
	FVector SpawnLocationPower_Up = FVector(-920.0f, 300.0f, 22.0f);
	
	for (int i = 0; i < 5; i++) {
		// Define una posición temporal para el zombie en X
		SpawnLocationPower_Up.X += 100;

		Nuevo_Power_Up = GetWorld()->SpawnActor<APower_Ups>(APower_Ups::StaticClass(), SpawnLocationPower_Up, FRotator::ZeroRotator);

		


		Mis_Power_Ups.Add(Nuevo_Power_Up);
		

	}


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

//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Detecta")));
//Decorador_V->Definir_Zombi(Zombie);
///*Decorador_V->Decorar_con_V();*/


void APVZ_USFX_LAB02GameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	for (AZombie * Zombie : Zombies_Decorados) {
		FVector LocalizacionZombies = Zombie->GetActorLocation();

		for (APower_Ups* Power_Up : Mis_Power_Ups) {

			FVector loc_Power_Up = Nuevo_Power_Up->GetActorLocation();

			if (FVector::DistSquared(loc_Power_Up, LocalizacionZombies) < (MaxDistance * MaxDistance)) {
				if (!(Power_Up->IsActorDestroyed())) {
					Power_Up->Destroy();
					if (Power_Up->IsActorDestroyed()) {
						GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Detecta")));
						/*Decorador_V->Definir_Zombi(Zombie);
						Decorador_V->Decorar_con_V();*/
					}
				}

			}
		}

		for (APlant* Planta : Plantas2) {
			
			if (Zombie->Columna_Zombie==Planta->Columna_Planta && FMath::Abs(LocalizacionZombies.Y) <= RangoAtaque) {

				Notificador->DefinirEstado("Zombie a la vista");
				/*GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("la columna z es:%i, lac de p es: %i "), Zombie->Columna_Zombie, Planta->Columna_Planta));*/
				
			}
			else {
				if (Zombies_Decorados.Num() > 0) {
					if (NuevoZombie_Decorado->IsActorDestroyed()) {
						/*GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("son: %i"), Zombies_Decorados.Num()));*/
						Zombies_Decorados.Remove(Zombie);
						/*GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("El zombie fue removido: %i"), Zombies_Decorados.Num() ));*/
						
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




