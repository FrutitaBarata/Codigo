// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/BoxComponent.h"

#include "Suscriptor.h"

#include "Zombie.generated.h"

UCLASS()
class PVZ_USFX_LAB02_API AZombie : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AZombie();

	private:

	UPROPERTY()
	TArray<AActor*> Subscribers = TArray<AActor*>();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshZombie;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshZombie_Tank;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	float Velocidad;

	UPROPERTY(VisibleAnywhere)
	int energia;

	

	UFUNCTION(BlueprintCallable, Category = "Custom")
	bool IsActorDestroyed() const;

	FTimerHandle Temporizador;

	void morir();

	FString TagString;

	virtual void Destroyed() override;


	virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal,
		FVector NormalImpulse, const FHitResult& Hit)override;//esta funcion nos notifica cada golpe que de la clase.



	


	//------------------------------------------------
	int Columna_Zombie;
};
