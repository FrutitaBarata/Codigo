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
#include "Zombie_con_V.h"
#include "Zombie_Interface.h"
#include "NotificarPlantas.h"
#include "AZombieMallaCambiable.h"


APVZ_USFX_LAB02GameModeBase::APVZ_USFX_LAB02GameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;




	DefaultPawnClass = AJugador::StaticClass();
	
	PlayerControllerClass = AControlador::StaticClass();
	



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
	//Decorador_V = GetWorld()->SpawnActor<ADecorador_V>(ADecorador_V::StaticClass(), FVector(0, 0, 0), FRotator::ZeroRotator);

	
	FVector SpawnLocationZombie = FVector(-820.0f, 600.0f, 22.0f);



	for (int32 i = 1; i <= 2; ++i) {
		

		NuevoZombie_Decorado = GetWorld()->SpawnActor<AZombie_con_V>(AZombie_con_V::StaticClass(), SpawnLocationZombie, FRotator::ZeroRotator);

		// Asignar nombre al zombi basado en el índice del contador
		FString ZombieName = FString::Printf(TEXT("Zombie %d"), i);
		NuevoZombie_Decorado->SetZombieName(ZombieName);
		NuevoZombie_Decorado->Velocidad = 0.1f;
		// Almacenar el zombi en el TMap
		Zombies_Map.Add(ZombieName, NuevoZombie_Decorado);
		SpawnLocationZombie.Y += 100;
		NuevoZombie_Decorado->Columna_Zombie = i;
	}


	//for (int i = 0; i < 1; i++) {
	//	SpawnLocationZombie.X += 100;

	//	NuevoZombie_Decorado = GetWorld()->SpawnActor<AZombie_con_V>(AZombie_con_V::StaticClass(), SpawnLocationZombie, FRotator::ZeroRotator);

	//	NuevoZombie_Decorado->Velocidad = 0.1f;


	//	Zombies_Decorados.Add(NuevoZombie_Decorado);
	//	//-------------------------------------------------------------------------------
	//	NuevoZombie_Decorado->Columna_Zombie = i;

	//}

	/*FVector SpawnLocationPower_Up = FVector(-920.0f, 300.0f, 22.0f);

	for (int i = 0; i < 5; i++) {
		SpawnLocationPower_Up.X += 100;

		Nuevo_Power_Up = GetWorld()->SpawnActor<APower_Ups>(APower_Ups::StaticClass(), SpawnLocationPower_Up, FRotator::ZeroRotator);




		Mis_Power_Ups.Add(Nuevo_Power_Up);


	}*/


	FVector SpawnLocationPlant = FVector(-920.0f, -600.0f, 22.0f);
	SpawnLocationPlantTemp = SpawnLocationPlant;

	// Genera 5 plantas
	for (int i = 1; i <= 2; i++)
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

	TArray<FString> ZombisAEliminar;

	for (const TPair<FString, AZombie_con_V*>& ZombiePair : Zombies_Map)
	{
		AZombie_con_V* Zombie = ZombiePair.Value;
		FVector LocalizacionZombies = Zombie->GetActorLocation();

		/*for (APower_Ups* Power_Up : Mis_Power_Ups) {
			FVector loc_Power_Up = Power_Up->GetActorLocation();
			if (FVector::DistSquared(loc_Power_Up, LocalizacionZombies) < (MaxDistance * MaxDistance)) {
				if (!(Power_Up->IsActorDestroyed())) {
					Power_Up->Destroy();
					if (Power_Up->IsActorDestroyed()) {
						Decorador_V->Decorar_con_V(Zombie);
					}
				}
			}
		}*/

		for (APlant* Planta : Plantas2) {
			if (Zombie->Columna_Zombie == Planta->Columna_Planta && FMath::Abs(LocalizacionZombies.Y) <= RangoAtaque) {
				Notificador->DefinirEstado("Zombie a la vista");
			}
			else {
				// Verificar si el zombi está destruido
				if (Zombie->IsActorDestroyed()) {
					// Agregar el nombre del zombi a la lista temporal de zombis a eliminar
					ZombisAEliminar.Add(ZombiePair.Key);
				}
			}
		}
	}

	// Eliminar los zombis destruidos del TMap
	for (const FString& ZombiAEliminar : ZombisAEliminar)
	{
		Zombies_Map.Remove(ZombiAEliminar);
	}

	// Verificar si el TMap está vacío
	if (Zombies_Map.Num() == 0)
	{
		Notificador->DefinirEstado("Zombie sin vista");
	}
	
	//---------------------------------------------------------------------------------------------
	//for (const TPair<FString, AZombie_con_V*>& ZombiePair : Zombies_Map)
	//{
	//	AZombie_con_V* Zombie = ZombiePair.Value;
	//	FVector LocalizacionZombies = Zombie->GetActorLocation();

	//	/*for (APower_Ups* Power_Up : Mis_Power_Ups) {

	//		FVector loc_Power_Up = Nuevo_Power_Up->GetActorLocation();

	//		if (FVector::DistSquared(loc_Power_Up, LocalizacionZombies) < (MaxDistance * MaxDistance)) {
	//			if (!(Power_Up->IsActorDestroyed())) {
	//				Power_Up->Destroy();
	//				if (Power_Up->IsActorDestroyed()) {
	//					Decorador_V->Decorar_con_V(Zombie);
	//				}
	//			}

	//		}
	//	}*/

	//	for (APlant* Planta : Plantas2) {

	//		if (Zombie->Columna_Zombie == Planta->Columna_Planta && FMath::Abs(LocalizacionZombies.Y) <= RangoAtaque) {

	//			Notificador->DefinirEstado("Zombie a la vista");

	//		}
	//		else {
	//			if (Zombies_Decorados.Num() > 0) {
	//				if (NuevoZombie_Decorado->IsActorDestroyed()) {
	//					
	//					Zombies_Decorados.Remove(Zombie);
	//					

	//				}
	//			}
	//			else {
	//				GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("El codigo deberia terminar")));
	//				Notificador->DefinirEstado("Zombie sin vista");

	//			}

	//		}
	//	}
	//}

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