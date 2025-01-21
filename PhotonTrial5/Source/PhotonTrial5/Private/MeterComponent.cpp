// Fill out your copyright notice in the Description page of Project Settings.


#include "MeterComponent.h"

// Sets default values for this component's properties
UMeterComponent::UMeterComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	_meterValue = 100.0f;

	_meterMaxValue = 100.0f;

	// ...
}

UMeterComponent::UMeterComponent(float _input)
{
	_meterMaxValue = _input;

	if (_meterMaxValue <= 0.0f)
	{
		_meterMaxValue = 1.0f;
	}

	_meterValue = _meterMaxValue;
}

UMeterComponent::UMeterComponent(float _v, float _mv)
{
	_meterMaxValue = _mv;

	if (_meterMaxValue <= 0.0f)
	{
		_meterMaxValue = 1.0f;
	}

	_meterValue = _v;

	if (_meterValue < 0.0f)
	{
		_meterValue = 0.0f;
	}

	if (_meterMaxValue > _meterMaxValue)
	{
		_meterValue = _meterMaxValue;
	}
}


// Called when the game starts
void UMeterComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMeterComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

float UMeterComponent::GetMeterValue()
{
	return _meterValue;
}

float UMeterComponent::GetMeterMaxValue()
{
	return _meterMaxValue;
}

void UMeterComponent::SetMeterValue(float _input)
{
	_meterValue = _input;

	AdjustValues();
}

void UMeterComponent::SetMeterMaxValue(float _input)
{
	_meterMaxValue = _input;

	AdjustValues();
}

float UMeterComponent::GetMeterRatio()
{
	if (_meterMaxValue <= 0.0f)
	{
		return -1.0f;
	}

	float _v = _meterValue / _meterMaxValue;

	return _v;
}

float UMeterComponent::GetMeterPercentage()
{
	if (_meterMaxValue <= 0.0f)
	{
		return -1.0f;
	}

	float _v = _meterValue / _meterMaxValue;

	_v = _v * 100.0f;

	return _v;
}

void UMeterComponent::RefillMeter()
{
	_meterValue = _meterMaxValue;
}

void UMeterComponent::SetNewValues(float _input)
{
	_meterMaxValue = _input;

	_meterValue = _input;

	AdjustValues();
}

void UMeterComponent::AddToMeterValue(float _input)
{
	_meterValue = _meterValue + _input;

	AdjustValues();
}

void UMeterComponent::AdjustValues()
{
	if (_meterMaxValue <= 0.0f)
	{
		_meterMaxValue = 1.0f;
	}

	if (_meterValue < 0.0f)
	{
		_meterValue = 0.0f;
	}

	if (_meterValue > _meterMaxValue)
	{
		_meterValue = _meterMaxValue;
	}
}