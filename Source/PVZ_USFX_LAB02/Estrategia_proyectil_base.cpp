// Fill out your copyright notice in the Description page of Project Settings.


#include "Estrategia_proyectil_base.h"

// Sets default values
AEstrategia_proyectil_base::AEstrategia_proyectil_base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstrategia_proyectil_base::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstrategia_proyectil_base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

