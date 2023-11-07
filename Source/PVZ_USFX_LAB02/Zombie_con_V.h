// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Decorador_Zombie.h"
#include "Zombie_con_V.generated.h"

/**
 * 
 */
UCLASS()
class PVZ_USFX_LAB02_API AZombie_con_V : public ADecorador_Zombie
{
	GENERATED_BODY()


public:
	AZombie_con_V();

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshZombie_V;

	int Columna_Zombie;
	UFUNCTION(BlueprintCallable, Category = "Custom")
	bool IsActorDestroyed() const;
	void morir();
	virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal,
		FVector NormalImpulse, const FHitResult& Hit)override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:

	UPROPERTY()
	TArray<AActor*> Subscribers = TArray<AActor*>();


};
