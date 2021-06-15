// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorWithMovement.h"
#include "Components/ArrowComponent.h"
#include "Engine/World.h"
#include "TimerManager.h"

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
	// GetWorldTimerManager().SetTimer(MovePlatform, this, &AActorWithMovement::Move, delayTimeMove, true);

}

// Called every frame
void AActorWithMovement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// velocidadDesdeCpp = velocidadDesdeCpp * DeltaTime;//ojo se modifica desde blueprint el valor desde Cpp
	// // UE_LOG(LogTemp, Warning, TEXT("la velocidad es %f"), velocidadDesdeCpp);

	//varios tipos de logs Prueba
	// // UE_LOG(LogTemp, Display, TEXT("Your message"));// UE_LOG(LogTemp, Warning, TEXT("Your message"));
	// // UE_LOG(LogTemp, Warning, TEXT("Your message"));
	// // UE_LOG(LogTemp, Error, TEXT("Your message"));
	// // UE_LOG(LogTemp, Fatal, TEXT("Your message"));

	if (GetActorLocation().Y < cuandoLlegaHastaCpp.Y - velocidadDesdeCpp)//para que funcione hay que restar a la posición la velocidad
	{
		AddActorWorldOffset( FVector( 0 ,velocidadDesdeCpp, 0 ) );
		GEngine->AddOnScreenDebugMessage(0, 2.0f, FColor::Red, FString::Printf(TEXT("la posicion es: X= %f  Y= %f  Z= %f "),GetActorLocation().X, GetActorLocation().Y + 2000,GetActorLocation().Z));
	}
	else
	{
		UArrowComponent* componentFlechaOtraColumna = Cast<UArrowComponent> ( refSueloPruebaDesdeCpp->GetComponentsByTag(UArrowComponent::StaticClass(), TEXT("ArrowPosicionfinal"))[0] );

		posicionDeReinicioDesdeCpp.X = GetActorLocation().X;
		posicionDeReinicioDesdeCpp.Y = posicionDeReinicioDesdeCpp.Y;
		posicionDeReinicioDesdeCpp.Z = GetActorLocation().Z;
		// posicionDeReinicioDesdeCpp.Y = posicionDeOtraPlataforma.Y;
		// posicionDeReinicioDesdeCpp.Y = componentFlechaOtraColumna->GetComponentTransform().GetLocation().Y;

		SetActorLocation(posicionDeReinicioDesdeCpp);
		
		float posicionActorActual = GetActorLocation().Y;
		UE_LOG(LogTemp, Warning, TEXT("REINICIO posicion YO es: Y= %f"), posicionActorActual);
		// UE_LOG(LogTemp, Warning, TEXT("REINICIO posicion OTRO es: Y= %f"), posicionDeOtraPlataforma.Y);
		
		// float posicionOtroActor = componentFlechaOtraColumna->GetComponentTransform().GetLocation().Y;
		float posicionOtroActor = refSueloPruebaDesdeCpp->GetActorLocation().Y; 
		UE_LOG(LogTemp, Warning, TEXT("REINICIO posicion OTRO es: Y= %f"), posicionOtroActor);
		// UE_LOG(LogTemp, Warning, TEXT("REINICIO posicion OTRO es: Y= %f"), posicionDeReinicioDesdeCpp.Y);
	}
}

void AActorWithMovement::Move()
{
	if (GetActorLocation().Y < cuandoLlegaHastaCpp.Y - velocidadDesdeCpp)//para que funcione hay que restar a la posición la velocidad
	{
		AddActorWorldOffset( FVector( 0 ,velocidadDesdeCpp, 0 ) );
		GEngine->AddOnScreenDebugMessage(0, 2.0f, FColor::Red, FString::Printf(TEXT("la posicion es: X= %f  Y= %f  Z= %f "),GetActorLocation().X, GetActorLocation().Y + 2000,GetActorLocation().Z));
		
	}
	else
	{
		UArrowComponent* componentFlechaOtraColumna = Cast<UArrowComponent> ( refSueloPruebaDesdeCpp->GetComponentsByTag(UArrowComponent::StaticClass(), TEXT("ArrowPosicionfinal"))[0] );

		posicionDeReinicioDesdeCpp.X = GetActorLocation().X;
		posicionDeReinicioDesdeCpp.Y = posicionDeReinicioDesdeCpp.Y;
		posicionDeReinicioDesdeCpp.Z = GetActorLocation().Z;
		// posicionDeReinicioDesdeCpp.Y = posicionDeOtraPlataforma.Y;
		// posicionDeReinicioDesdeCpp.Y = componentFlechaOtraColumna->GetComponentTransform().GetLocation().Y;

		SetActorLocation(posicionDeReinicioDesdeCpp);
		
		float posicionActorActual = GetActorLocation().Y;
		UE_LOG(LogTemp, Warning, TEXT("REINICIO posicion YO es: Y= %f"), posicionActorActual);
		// UE_LOG(LogTemp, Warning, TEXT("REINICIO posicion OTRO es: Y= %f"), posicionDeOtraPlataforma.Y);
		
		// float posicionOtroActor = componentFlechaOtraColumna->GetComponentTransform().GetLocation().Y;
		float posicionOtroActor = refSueloPruebaDesdeCpp->GetActorLocation().Y; 
		UE_LOG(LogTemp, Warning, TEXT("REINICIO posicion OTRO es: Y= %f"), posicionOtroActor);
		// UE_LOG(LogTemp, Warning, TEXT("REINICIO posicion OTRO es: Y= %f"), posicionDeReinicioDesdeCpp.Y);

	}
}

void AActorWithMovement::Reload()
{
	
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


//NOTAS:
//TRAYECTO: direccion donde se va a ir
//DESPLAZAMIENTO: Resta de posicion final - posicion inicial
//VELOCIDAD: relación de la distancia recorrida con respecto al tiempo esto es un vector con una dirección "Metros/s"
//RAPIDES: distancia recorrida divide el tiempo empleado para dicha distancía. se emplean unidades de longitud y tiempo. NO ES UN VECTOR CON UNA DIRECCION "Metros/Segundos"
//ACELERACION: cambio de velocidad en un intervalo de tiempo.. A la velocidad final siempre se resta la velocidad inicial y se divide entre el tiempo final y tiempo inicial.. (Metros/segundos)/segundos
//DESACELERACION: Cuando cambiamos de una velocidad mayor a una menor