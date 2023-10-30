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

	RangoAtaque=200.0f;

	FilaActual = 1;
	ColumnaActual = 1;

}

void APVZ_USFX_LAB02GameModeBase::BeginPlay()
{
	Super::BeginPlay();


	 Notificador = GetWorld()->SpawnActor<ANotificarPlantas>(ANotificarPlantas::StaticClass(), FVector(0, 0, 0), FRotator::ZeroRotator);


	//Definiendo la posici�n de los zombies
	FVector SpawnLocationZombie = FVector(-920.0f, 600.0f, 22.0f);
	int a = 1;
	for (int i = 0; i < 5; i++) {
		// Define una posici�n temporal para el zombie en X
		SpawnLocationZombie.X += 100;

		NuevoZombie = GetWorld()->SpawnActor<AZombieComun>(AZombieComun::StaticClass(), SpawnLocationZombie, FRotator::ZeroRotator);

		NuevoZombie->Velocidad = FMath::FRandRange(0.01f, 0.1f);
		
		
			Zombies.Add(NuevoZombie);

	}
	
	

	//Definiendo la posici�n de las plantas
	FVector SpawnLocationPlant = FVector(-920.0f, -600.0f, 22.0f);
	SpawnLocationPlantTemp = SpawnLocationPlant;

	// Genera 5 plantas
	for (int i = 0; i < 5; i++)
	{
		SpawnLocationPlantTemp.X += 100;
			
			NuevaPlantaGuisante = GetWorld()->SpawnActor<ALanza_Guisantes>(ALanza_Guisantes::StaticClass(), SpawnLocationPlantTemp, FRotator::ZeroRotator);

			Plantas2.Add(NuevaPlantaGuisante);

			
			NuevaPlantaGuisante->DefinirNotificarPlantas(Notificador);

		

	}
	

		
	
	
	
}




void APVZ_USFX_LAB02GameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	for (AZombie* Zombie : Zombies) {
		FVector LocalizacionZombies = Zombie->GetActorLocation();
		for (APlant* Planta : Plantas2) {
			FVector LocalizacionPlantas = Planta->GetActorLocation();
			if (FMath::IsNearlyEqual(LocalizacionZombies.X, LocalizacionPlantas.X, SMALL_NUMBER) && FMath::Abs(LocalizacionZombies.Y) <= RangoAtaque) {
				Notificador->DefinirEstado("Zombie a la vista");
				GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Hay zombis ")));
			}
			else {
				if (Zombies.Num() > 0) {
					if (NuevoZombie->IsActorDestroyed()) {
						Zombies.Remove(Zombie);
						
					}
				}
				else {
					GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("El codigo deberia terminar")));
					Notificador->DefinirEstado("Zombie sin vista");
					LocalizacionZombies = FVector::ZeroVector;
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




