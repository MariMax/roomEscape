// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "DoorOpenner.generated.h"

#define OUT

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);

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
    
    UPROPERTY(BlueprintAssignable)
    FDoorEvent OnDoorOpenRequest;

    UPROPERTY(BlueprintAssignable)
    FDoorEvent OnDoorCloseRequest;


private:
    const float getTotalMassOnThePlate() const;
    
    UPROPERTY(EditAnywhere)
    ATriggerVolume* pressurePlate = nullptr;
    
    AActor* owner;
    
    UPROPERTY(EditAnywhere)
    float triggerMass = 50.f;
    
    
};
