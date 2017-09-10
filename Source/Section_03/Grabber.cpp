// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include <Public/DrawDebugHelpers.h>


// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    auto world = GetWorld();
    auto playerController = world->GetFirstPlayerController();
    
    FVector location;
    FRotator rotation;
    
    playerController->GetPlayerViewPoint(location, rotation);
    
//    auto locationS = location.ToString();
//    auto rotationS = rotation.ToString();
//    FColor color = FColor(255, 0, 0, 255);
    
//    UE_LOG(LogTemp, Error, TEXT("location %s rotation %s"), *locationS, *rotationS);
    
    FVector endOfPlayerReach = location + rotation.Vector() * maximumReach;
    FCollisionObjectQueryParams collisionParams(ECollisionChannel::ECC_PhysicsBody);
    FCollisionQueryParams collisionQueryParams(
                                               FName(TEXT("")),
                                               false,
                                               GetOwner()
    );
//    DrawDebugLine(
//                  world,
//                  location,
//                  endOfPlayerReach,
//                  color,
//                  false,
//                  1.f,
//                  1,
//                  5.f
//                  );
    FHitResult hitObject;
    world->LineTraceSingleByObjectType(
                                          hitObject,
                                          location,
                                          endOfPlayerReach,
                                          collisionParams,
                                          collisionQueryParams
                                          );
    auto hitActor = hitObject.GetActor();
    if (hitActor)
        UE_LOG(LogTemp, Error, TEXT("actor name %s"), *hitActor->GetName());
	// ...
}

