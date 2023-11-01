// Fill out your copyright notice in the Description page of Project Settings.

#include "Zombie.h"

#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"

#include "Plant.h"
#include "Proyectil.h"
// Sets default values
AZombie::AZombie()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//MeshZombie = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Zombie Mesh"));

	//MeshZombie->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	////MeshZombie->SetSimulatePhysics(true);
	//MeshZombie->SetCollisionObjectType(ECollisionChannel::ECC_Pawn);

	//MeshZombie->SetCollisionProfileName(UCollisionProfile::BlockAllDynamic_ProfileName);
	//MeshZombie->SetupAttachment(RootComponent);

	//RootComponent = MeshZombie;

	//ConstructorHelpers::FObjectFinder<UStaticMesh> ZombieMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_QuadPyramid.Shape_QuadPyramid'"));


	////Mesh o aspecto alternativo
	////static ConstructorHelpers::FObjectFinder<UStaticMesh> ZombieMeshAsset2(TEXT("StaticMesh'/Game/StarterContent/Architecture/Pillar_50x500.Pillar_50x500'"));


	////Definición del mesh
	//MeshZombie->SetStaticMesh(ZombieMeshAsset.Object);

	//MeshZombie->SetRelativeScale3D(FVector(1.f, 1.f, 1.f));


	energia = 2000;
	Velocidad = 0.1f;

	Tags.Add(TEXT("Zombie"));

	//InitialLifeSpan = 5; //Para que el actor se destruya




}

// Called when the game starts or when spawned
void AZombie::BeginPlay()
{
	Super::BeginPlay();


	UWorld* const World = GetWorld();

	//Otra forma para que el actor se destruya
	//World->GetTimerManager().SetTimer(Temporizador, this, &AZombie::morir, 2, false);

}



// Called every frame
void AZombie::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector LocalizacionObjetivo = FVector(-800.0f, -600.0f, 160.0f); // Cambia la ubicación objetivo según tus necesidades
	// Calcula la dirección y distancia al objetivo
	FVector Direccion = LocalizacionObjetivo - FVector(-800.0f, 400.0f, 160.0f);
	// Calcula la distancia de al objetivo
	float DistanciaAlObjetivo = FVector::Dist(LocalizacionObjetivo, this->GetActorLocation());




	// Calcula el desplazamiento en este frame
	float DeltaMove = Velocidad * GetWorld()->DeltaTimeSeconds;

	if (DeltaMove > DistanciaAlObjetivo)
	{
		// Si el desplazamiento excede la distancia al objetivo, mueve directamente al objetivo
		this->SetActorLocation(LocalizacionObjetivo);
		//this->SetActorRotation(NewRotation);
	}
	else
	{
		// Mueve el objeto en la dirección calculada
		this->AddActorWorldOffset(Direccion * DeltaMove);

	}



	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Este es un mensaje")));



}


bool AZombie::IsActorDestroyed() const
{
  return IsPendingKill();
}

void AZombie::morir()
{
	Destroy();			//El actor se destruye
	this->Destroy();		//El actor también se destruye
	SetActorHiddenInGame(true);	//El actor sólo desaparece
}



void AZombie::Destroyed()
{
	FString nombreZombie = this->GetName();
	/*GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Si hay un zombie: &s"), *nombreZombie));*/

}

void AZombie::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	//Destroy();
	AProyectil* proyectil = Cast<AProyectil>(Other);

	if (Other != proyectil) {
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Este es un mensaje")));
		Other->Destroy();
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Nombre del otro actor: %s"), *Other->GetName()));

	}
	//Destroy();
	/*GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Este es un mensaje")));
	Other->Destroy();*/
}





