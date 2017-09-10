// Fill out your copyright notice in the Description page of Project Settings.

#include "DoorOpenner.h"
#include <GameFramework/Actor.h>
#include <Math/Rotator.h>
#include <Engine/EngineTypes.h>
#include <Engine/World.h>


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
    auto world = GetWorld();
    auto playerController = world->GetFirstPlayerController();
    auto pawn = playerController->GetPawn();
    whoCanOpenThisDoor = pawn;
	
}

void UDoorOpenner::openTheDoor(){
    auto door = GetOwner();
    FRotator rotator = FRotator(0.f, 360.f, 0.f);
    door->SetActorRotation(rotator, ETeleportType::None);
}


// Called every frame
void UDoorOpenner::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    if(pressurePlate->IsOverlappingActor(whoCanOpenThisDoor)){
        openTheDoor();
    }
	// ...
}

