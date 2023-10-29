// Fill out your copyright notice in the Description page of Project Settings.


#include "Girasol.h"
#include "Sol.h"

AGirasol::AGirasol()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshGirasol(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Trim.Shape_Trim'"));


	MeshPlanta->SetStaticMesh(MeshGirasol.Object);
	MeshPlanta->SetRelativeScale3D(FVector(3, 1, 3));
	energia = 150;

	//Message from the current location of the plant
		//GEngine->AbortInsideMemberFunction(TEXT("Ubicacion de la planta %f"), *UbicacionActual);

}

void AGirasol::BeginPlay()
{
	Super::BeginPlay();

	int Tiempo = FMath::RandRange(3, 6);

	UWorld* const World = GetWorld();

	World->GetTimerManager().SetTimer(Temporizador, this, &AGirasol::SpawnSoles, Tiempo, true);


	UbicacionActual = GetActorLocation();

	float UbicacionActualX = UbicacionActual.X;
	float UbicacionActualY = UbicacionActual.Y;
	float UbicacionActualZ = UbicacionActual.Z;

	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Ubicacion de la planta %f, %f, %f"), UbicacionActualX, UbicacionActualY, UbicacionActualZ));

}


void AGirasol::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

void AGirasol::SpawnSoles()
{
	UWorld* const World = GetWorld();

	FVector Ubicacion = GetActorLocation();

	World->SpawnActor<ASol>(ASol::StaticClass(), FVector(Ubicacion.X, Ubicacion.Y, 100), FRotator::ZeroRotator);


}
