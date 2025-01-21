// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MeterComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PHOTONTRIAL5_API UMeterComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMeterComponent();

	UMeterComponent(float _input);

	UMeterComponent(float _v, float _mv);

private:

	void AdjustValues();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	//UPROPERTY(BlueprintType, EditAnywhere)
	float _meterValue;

	//UPROPERTY(BlueprintType, EditAnywhere)
	float _meterMaxValue;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintPure)
		float GetMeterValue();

	UFUNCTION(BlueprintPure)
		float GetMeterMaxValue();

	UFUNCTION(BlueprintCallable)
		void SetMeterValue(float _input);

	UFUNCTION(BlueprintCallable)
		void SetMeterMaxValue(float _input);

	UFUNCTION(BlueprintPure)
		float GetMeterRatio();

	UFUNCTION(BlueprintPure)
		float GetMeterPercentage();

	UFUNCTION(BlueprintCallable)
		void RefillMeter();

	UFUNCTION(BlueprintCallable)
		void SetNewValues(float _input);

	UFUNCTION(BlueprintCallable)
		void AddToMeterValue(float _input);
		
};
