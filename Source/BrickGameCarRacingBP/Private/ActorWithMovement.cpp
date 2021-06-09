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

	velocidadDesdeCpp = velocidadDesdeCpp * DeltaTime;//ojo se modifica desde blueprint el valor desde Cpp
	// UE_LOG(LogTemp, Warning, TEXT("la velocidad es %f"), velocidadDesdeCpp);
	
	// UE_LOG(LogTemp, Display, TEXT("Your message"));// UE_LOG(LogTemp, Warning, TEXT("Your message"));
	// UE_LOG(LogTemp, Warning, TEXT("Your message"));
	// UE_LOG(LogTemp, Error, TEXT("Your message"));
	// UE_LOG(LogTemp, Fatal, TEXT("Your message"));

	// SetActorLocation(FVector(GetActorLocation().X, velocidadDesdeCpp, GetActorLocation().Z));
	if (GetActorLocation().Y < cuandoLlegaHastaCpp.Y)
	{
		AddActorWorldOffset( FVector( 0 ,velocidadDesdeCpp, 0 ) );
		GEngine->AddOnScreenDebugMessage(0, 0.f, FColor::Red, FString::Printf(TEXT("la posicion es: X= %f  Y= %f  Z= %f "),GetActorLocation().X, GetActorLocation().Y,GetActorLocation().Z));
	
	}
	else
	{
		posicionDeReinicioDesdeCpp.X = GetActorLocation().X;
		posicionDeReinicioDesdeCpp.Y = posicionDeOtraPlataforma.Y;
		posicionDeReinicioDesdeCpp.Z = GetActorLocation().Z;

		SetActorLocation(posicionDeReinicioDesdeCpp);
		
		UE_LOG(LogTemp, Warning, TEXT("REINICIO posicion YO es: Y= %f"), GetActorLocation().Y);
		UE_LOG(LogTemp, Warning, TEXT("REINICIO posicion OTRO es: Y= %f"), posicionDeOtraPlataforma.Y);
	
	}

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


