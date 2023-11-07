// Fill out your copyright notice in the Description page of Project Settings.


#include "Decorador_Zombie.h"
#include "Decorador_V.h"

// Sets default values
ADecorador_Zombie::ADecorador_Zombie()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;



	/*Decorador_Zombie->energia =Decorador_V->energia;
	* Valor_Nuevo= Decorador_V->GetEnergia();
	energia = Valor_Nuevo;*/
	/*Decorador_Zombie->energia = Decorador_V->GetEnergia();*/


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




