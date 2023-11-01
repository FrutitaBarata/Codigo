// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombies_Interfaz.h"

// Sets default values
AZombies_Interfaz::AZombies_Interfaz()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AZombies_Interfaz::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AZombies_Interfaz::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

