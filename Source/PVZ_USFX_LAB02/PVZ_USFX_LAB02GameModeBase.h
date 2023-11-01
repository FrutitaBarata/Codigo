// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PVZ_USFX_LAB02GameModeBase.generated.h"

/**
 *
 */
class AZombie;
class AZombieComun;
class APlant;
class APlanta_Ataque;
class ALanza_Guisantes;
class ANotificarPlantas;
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
	TArray<AZombie*> Zombies_Decorados;
	TArray<APlant*> Plantas2;
	/*TMap<FString, APlant*> Plantas;*/
	float TiempoTranscurrido;

	void aumentovelocidad();

	void MostrarEnergiaDePlantas();


	AZombieComun* NuevoZombie;

	AZombie_Tank* NuevoZombie_Decorado;

	FTimerHandle Temporizador2;

	FString NombrePlanta;

	ALanza_Guisantes* NuevaPlantaGuisante;



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

