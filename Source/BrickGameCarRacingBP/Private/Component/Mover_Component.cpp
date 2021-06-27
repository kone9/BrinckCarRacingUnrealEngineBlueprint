// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/Mover_Component.h"

// Sets default values for this component's properties
UMover_Component::UMover_Component()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMover_Component::BeginPlay()
{
	Super::BeginPlay();

	// ...
	owner = GetOwner();
}


// Called every frame
void UMover_Component::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if(puedoMover == true)
	{
		owner->AddActorWorldOffset(FVector(0,velocidad,0));
	}
}

