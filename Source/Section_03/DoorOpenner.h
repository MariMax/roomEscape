// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "DoorOpenner.generated.h"

#define OUT


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SECTION_03_API UDoorOpenner : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDoorOpenner();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
    void openTheDoor();
    void closeTheDoor();
    
    const float getTotalMassOnThePlate() const;
    
    UPROPERTY(VisibleAnywhere)
    float openAngle = 90.f;
	
    UPROPERTY(EditAnywhere)
    ATriggerVolume* pressurePlate = nullptr;
    
    UPROPERTY(EditAnywhere)
    float timeToCloseDoor = 1.f;
    
    float lastOpenTriggerTime;
    
    float initialDoorPosition = 0;
    
    AActor* owner;
    
    UPROPERTY(EditAnywhere)
    float triggerMass = 250.f;
    
    
};
