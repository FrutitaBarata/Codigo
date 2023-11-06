// Fill out your copyright notice in the Description page of Project Settings.


#include "Decorador_Zombie.h"

// Sets default values
ADecorador_Zombie::ADecorador_Zombie()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADecorador_Zombie::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADecorador_Zombie::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADecorador_Zombie::Definir_Zombi(IZombie_Interface* _Zombie_Interface)
{
	 Zombie_Interface = _Zombie_Interface; 
	 GetEnemigo();
}

IZombie_Interface* ADecorador_Zombie::GetEnemigo()
{
	return Zombie_Interface;
}


