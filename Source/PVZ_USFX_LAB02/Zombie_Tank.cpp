// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombie_Tank.h"



AZombie_Tank::AZombie_Tank()
{

	energia = 100;

	

	MeshZombie_Tank = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Zombie_Tank Mesh"));

	MeshZombie_Tank->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	//MeshZombie->SetSimulatePhysics(true);
	MeshZombie_Tank->SetCollisionObjectType(ECollisionChannel::ECC_Pawn);

	MeshZombie_Tank->SetCollisionProfileName(UCollisionProfile::BlockAllDynamic_ProfileName);
	MeshZombie_Tank->SetupAttachment(RootComponent);

	RootComponent = MeshZombie_Tank;

	ConstructorHelpers::FObjectFinder<UStaticMesh> ZombieMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'"));


	//Mesh o aspecto alternativo
	//static ConstructorHelpers::FObjectFinder<UStaticMesh> ZombieMeshAsset2(TEXT("StaticMesh'/Game/StarterContent/Architecture/Pillar_50x500.Pillar_50x500'"));


	//Definición del mesh
	MeshZombie_Tank->SetStaticMesh(ZombieMeshAsset.Object);

	MeshZombie_Tank->SetRelativeScale3D(FVector(2.f, 2.f, 2.f));
}