// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombie_con_V.h"
#include "Proyectil.h"
AZombie_con_V::AZombie_con_V()
{
	PrimaryActorTick.bCanEverTick = true;

	MeshZombie_V = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Zombie_V Mesh"));

	MeshZombie_V->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	//MeshZombie->SetSimulatePhysics(true);
	MeshZombie_V->SetCollisionObjectType(ECollisionChannel::ECC_Pawn);

	MeshZombie_V->SetCollisionProfileName(UCollisionProfile::BlockAllDynamic_ProfileName);
	MeshZombie_V->SetupAttachment(RootComponent);

	RootComponent = MeshZombie_V;

	ConstructorHelpers::FObjectFinder<UStaticMesh> ZombieMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'"));

	MeshZombie_V->SetStaticMesh(ZombieMeshAsset.Object);

	MeshZombie_V->SetRelativeScale3D(FVector(2.f, 2.f, 2.f));



}


void AZombie_con_V::BeginPlay()
{
	Super::BeginPlay();


	UWorld* const World = GetWorld();

	//Otra forma para que el actor se destruya
	//World->GetTimerManager().SetTimer(Temporizador, this, &AZombie::morir, 2, false);

}
void AZombie_con_V::Tick(float DeltaTime)
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

void AZombie_con_V::SetZombieName(const FString& Name)
{
	ZombieName = Name;
}

bool AZombie_con_V::IsActorDestroyed() const
{
	return IsPendingKill();
}

void AZombie_con_V::morir()
{
	Destroy();			//El actor se destruye
	this->Destroy();		//El actor también se destruye
	SetActorHiddenInGame(true);	//El actor sólo desaparece
}
void AZombie_con_V::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
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