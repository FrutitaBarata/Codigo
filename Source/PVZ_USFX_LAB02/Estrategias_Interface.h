// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Estrategias_Interface.generated.h"
class AZombie_con_V;
// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEstrategias_Interface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PVZ_USFX_LAB02_API IEstrategias_Interface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual void Da�o(/*AZombie_con_V* _Actual*/) = 0;
};
