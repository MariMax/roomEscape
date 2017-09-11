#include "DoorOpenner.h"
#include <GameFramework/Actor.h>
#include <Math/Rotator.h>
#include <Engine/EngineTypes.h>
#include <Engine/World.h>

// Sets default values for this component's properties
UDoorOpenner::UDoorOpenner()
{
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UDoorOpenner::BeginPlay()
{
	Super::BeginPlay();
    auto world = GetWorld();
    auto playerController = world->GetFirstPlayerController();
    auto pawn = playerController->GetPawn();
    owner = GetOwner();
    FRotator rotator = owner->GetActorRotation();
        if(!pressurePlate){
            UE_LOG(LogTemp, Error, TEXT("Pressure Plate(trigger volume) is not assigned to %s"), *owner->GetName());
        }
}

// Called every frame
void UDoorOpenner::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if(getTotalMassOnThePlate() > triggerMass){
        OnDoorOpenRequest.Broadcast();
        return;
    }
    
    OnDoorCloseRequest.Broadcast();
}

const float UDoorOpenner::getTotalMassOnThePlate() const {
    TArray<AActor*> actors;
    float total = 0.f;
    
    if (!pressurePlate) return total;
    
    pressurePlate->GetOverlappingActors(OUT actors);
    for (const auto& item: actors){
        const UPrimitiveComponent* component = item->FindComponentByClass<UPrimitiveComponent>();
        total+=component->GetMass();
    }
    
    return total;
}
