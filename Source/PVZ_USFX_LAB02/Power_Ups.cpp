// Fill out your copyright notice in the Description page of Project Settings.


#include "Power_Ups.h"

// Sets default values
APower_Ups::APower_Ups()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshPower_Up = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh del Power up"));

	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshPower_UpAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));

	MeshPower_Up->SetStaticMesh(MeshPower_UpAsset.Object);

	MeshPower_Up->SetRelativeScale3D(FVector(1.f, 1.f, 1.f));


}

// Called when the game starts or when spawned
void APower_Ups::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APower_Ups::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

