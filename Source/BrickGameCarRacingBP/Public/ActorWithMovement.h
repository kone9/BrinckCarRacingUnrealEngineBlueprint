// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorWithMovement.generated.h"

UCLASS()
class BRICKGAMECARRACINGBP_API AActorWithMovement : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorWithMovement();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector posicionDeReinicioDesdeCpp = FVector(0,500,0);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector posicionDeOtraPlataforma = FVector(0,0,0);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector movimientoDesdeCpp;

	UPROPERTY(EditAnywhere)
	FVector cuandoLlegaHastaCpp = FVector(0, 2000, 0);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float velocidadDesdeCpp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float tiempoPorSegundoDesdeCpp;

	UFUNCTION(BlueprintCallable)
	void MoverDesdeCPP();

};
