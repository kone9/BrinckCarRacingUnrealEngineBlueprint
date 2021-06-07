// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorWithMovement.h"

// Sets default values
AActorWithMovement::AActorWithMovement()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AActorWithMovement::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActorWithMovement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	velocidadDesdeCpp = velocidadDesdeCpp + GetActorLocation().X * DeltaTime;
	
	AddActorWorldOffset( FVector( 0 ,velocidadDesdeCpp * DeltaTime, 0 ) );
	
	// SetActorLocation(FVector(GetActorLocation().X, velocidadDesdeCpp, GetActorLocation().Z));
	/*if (GetActorLocation().Y > cuandoLlegaHastaCpp.Y)
	{
		SetActorLocation(posicionDeReinicioDesdeCpp);
	}*/
}

void AActorWithMovement::MoverDesdeCPP()
{
	
	// velocidadDesde += velocidadDesde * tiempo;
	// // movimientoDesdeCpp.Y = velocidadDesdeCpp;

	// SetActorLocation(FVector(0, velocidadDesdeCpp, 0));

	/*if (GetActorLocation().Y > cuandoLlegaHastaCpp.Y)
	{
		SetActorLocation(posicionDeReinicioDesdeCpp);
	}*/

}


