// Fill out your copyright notice in the Description page of Project Settings.


#include "AZombieMallaCambiable.h"



AAZombieMallaCambiable::AAZombieMallaCambiable()
    
{
    
}

void AAZombieMallaCambiable::CambiarTamanoCuandoVidaAMitad()
{
    

        if (energia <= energia / 2) {
            // Cambiar la malla a la malla dañada.
            MeshZombie_Tank->SetRelativeScale3D(FVector(1.f, 1.f, 1.f));
        }
    
}





