// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Zombie_Interface.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Decorador_Zombie.generated.h"

UCLASS()
class PVZ_USFX_LAB02_API ADecorador_Zombie : public AActor, public IZombie_Interface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADecorador_Zombie();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private: 
	IZombie_Interface* Zombie_Interface;


public:
	
	void Definir_Zombi(IZombie_Interface* _Zombie_Interface) { Zombie_Interface = _Zombie_Interface; }
	IZombie_Interface* GetZombi() { return Zombie_Interface; }
};

