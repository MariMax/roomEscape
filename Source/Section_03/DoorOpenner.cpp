// Fill out your copyright notice in the Description page of Project Settings.

#include "DoorOpenner.h"
#include <GameFramework/Actor.h>


// Sets default values for this component's properties
UDoorOpenner::UDoorOpenner()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoorOpenner::BeginPlay()
{
	Super::BeginPlay();

    auto door = GetOwner();
    const auto doorTransform = door->GetTransform();
	
}


// Called every frame
void UDoorOpenner::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

