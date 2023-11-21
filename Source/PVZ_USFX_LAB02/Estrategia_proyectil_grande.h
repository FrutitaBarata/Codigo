// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Estrategias_Interface.h"
#include "Estrategia_proyectil_grande.generated.h"

UCLASS()
class PVZ_USFX_LAB02_API AEstrategia_proyectil_grande : public AActor, public IEstrategias_Interface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEstrategia_proyectil_grande();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
