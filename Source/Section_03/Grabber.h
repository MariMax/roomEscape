// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <PhysicsEngine/PhysicsHandleComponent.h>
#include <Components/InputComponent.h>
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SECTION_03_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
    
private:
    UPROPERTY(EditAnywhere)
    float maximumReach = 100.f;

    UPhysicsHandleComponent* physicsHandle = nullptr;
    UInputComponent* inputComponent = nullptr;
    
    void grab();
    void release();
    void initPhysicsHandler();
    void initInputHandler();
    void getEndOfTheReach(FVector&, FVector&) const;
    
    //returns hit for first physics body in maximumReach
    const FHitResult lineTrace() const;
    
    AActor* owner = nullptr;
};
