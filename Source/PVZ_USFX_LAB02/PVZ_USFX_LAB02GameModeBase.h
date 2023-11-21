// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PVZ_USFX_LAB02GameModeBase.generated.h"

/**
 *
 */
class APower_Ups;
class AZombie;
class AZombieComun;
class IZombie_Interface;
class APlant;
class APlanta_Ataque;
class ALanza_Guisantes;
class ANotificarPlantas;
class AZombie_con_V;
class Decorador_Zombie;
class Decorador_V;
class AZombieCubo;
class AZombie_Tank;
UCLASS()
class PVZ_USFX_LAB02_API APVZ_USFX_LAB02GameModeBase : public AGameModeBase
{
	GENERATED_BODY()


public:
	// Sets default values for this actor's properties
	APVZ_USFX_LAB02GameModeBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FTimerHandle Temporizador;

	void Spawn();

	FVector contador;
	// Puedes ajustar este valor según tus necesidades


	int contador2;


	FVector localizacion;


	// Declarar un vector de objetos
	TArray<AZombie*> Zombies;
	/*TArray<AZombie_con_V*> Zombies_Decorados;*/
	TArray<APlant*> Plantas2;
	TArray<APower_Ups*> Mis_Power_Ups;
	TMap<FString, AZombie_con_V*> Zombies_Map;
	const int32 NumColumns = 2;

	/*TMap<FString, APlant*> Plantas;*/
	float TiempoTranscurrido;

	void aumentovelocidad();

	void MostrarEnergiaDePlantas();



	AZombie* NuevoZombie;



	FTimerHandle Temporizador2;

	FString NombrePlanta;

	ALanza_Guisantes* NuevaPlantaGuisante;
	//.--------------------------------------
	IZombie_Interface* Zombie_Interface;
	AZombie_con_V* NuevoZombie_Decorado;
	APower_Ups* Nuevo_Power_Up;

	ADecorador_V* Decorador_V;

	const float MaxDistance = 1.0f;

	int FilaActual;
	int ColumnaActual;
	void prueba();



	AZombieCubo* NewZombieCubo;

	FVector SpawnLocationPlantTemp;

	/*FVector ZombieLocation;
	FVector PlantaLocation;*/
	//-------------------------------------------------------------------------------------------------------------


	ANotificarPlantas* Notificador;
	float RangoAtaque;
};

