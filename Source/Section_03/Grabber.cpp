// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include <Public/DrawDebugHelpers.h>

#define OUT


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
    owner  = GetOwner();
    initPhysicsHandler();
    initInputHandler();
}

void UGrabber::initPhysicsHandler(){
    auto componentName = owner->GetName();
    physicsHandle =  owner->FindComponentByClass<UPhysicsHandleComponent>();
    if (!physicsHandle)
        UE_LOG(LogTemp, Error, TEXT("handle is missing on %s"), *componentName);
}

void UGrabber::initInputHandler() {
    inputComponent =  owner->FindComponentByClass<UInputComponent>();
    auto componentName = owner->GetName();
    if (!inputComponent){
        UE_LOG(LogTemp, Error, TEXT("input is missing is missing on %s"), *componentName);
    } else {
        UE_LOG(LogTemp, Error, TEXT("input is FOUND"));
        inputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::grab);
        inputComponent->BindAction("Grab", IE_Released, this, &UGrabber::release);
    }
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// ...
    // if we hold something move it around
}

void UGrabber::grab() {
    auto hitObject = lineTrace();
    auto hitActor = hitObject.GetActor();
    if (!hitActor) return;
    UE_LOG(LogTemp, Error, TEXT("grab actor %s"), *hitActor->GetName());
}

void UGrabber::release() {
    UE_LOG(LogTemp, Error, TEXT("release item"));
}

const FHitResult UGrabber::lineTrace() const {
    auto world = GetWorld();
    auto playerController = world->GetFirstPlayerController();
    
    FVector location;
    FRotator rotation;
    
    playerController->GetPlayerViewPoint(OUT location, OUT rotation);
    FVector endOfPlayerReach = location + rotation.Vector() * maximumReach;
    FCollisionObjectQueryParams collisionParams(ECollisionChannel::ECC_PhysicsBody);
    FCollisionQueryParams collisionQueryParams(
                                               FName(TEXT("")),
                                               false,
                                               owner
                                               );
    //    DrawDebugLine(world,location,endOfPlayerReach,color,false,1.f,1,5.f);
    FHitResult hitObject;
    world->LineTraceSingleByObjectType(
                                       OUT hitObject,
                                       location,
                                       endOfPlayerReach,
                                       collisionParams,
                                       collisionQueryParams
                                       );
    return hitObject;
}

