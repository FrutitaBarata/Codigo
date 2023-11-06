// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Power_Ups.generated.h"

UCLASS()
class PVZ_USFX_LAB02_API APower_Ups : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APower_Ups();
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshPower_Up;
	bool IsActorDestroyed() const;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
