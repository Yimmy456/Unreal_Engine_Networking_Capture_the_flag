// Fill out your copyright notice in the Description page of Project Settings.


#include "RotationComponent.h"

// Sets default values for this component's properties
URotationComponent::URotationComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	_constant = 1.0f;

	// ...
}


// Called when the game starts
void URotationComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void URotationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


bool URotationComponent::GetRotate()
{
	return _rotate;
}

FRotator URotationComponent::GetAxis()
{
	return _axis;
}

float URotationComponent::GetConstant()
{
	return _constant;
}

bool URotationComponent::GetDeltaTimeX()
{
	return _deltaTimeX;
}

bool URotationComponent::GetDeltaTimeY()
{
	return _deltaTimeY;
}

bool URotationComponent::GetDeltaTimeZ()
{
	return _deltaTimeZ;
}

USceneComponent* URotationComponent::GetComp()
{
	return _comp;
}

FRotator URotationComponent::GetFinalRotation()
{
	return _finalRotation;
}


void URotationComponent::SetRotate(bool _input)
{
	_rotate = _input;
}

void URotationComponent::SetAxis(FRotator _input)
{
	_axis = _input;
}

void URotationComponent::SetConstant(float _input)
{
	_constant = _input;
}

void URotationComponent::SetDeltaTimeX(bool _input)
{
	_deltaTimeX = _input;
}

void URotationComponent::SetDeltaTimeY(bool _input)
{
	_deltaTimeY = _input;
}

void URotationComponent::SetDeltaTimeZ(bool _input)
{
	_deltaTimeZ = _input;
}

void URotationComponent::SetComp(USceneComponent* _input)
{
	_comp = _input;
}

void URotationComponent::RotateComp(float _input)
{
	if (!_rotate)
	{
		_finalRotation = FRotator::ZeroRotator;
		return;
	}

	_finalRotation = _axis;

	_finalRotation.Roll = _finalRotation.Roll * _constant;

	if (_deltaTimeX)
	{
		_finalRotation.Roll = _finalRotation.Roll * _input;
	}

	_finalRotation.Pitch = _finalRotation.Pitch * _constant;

	if (_deltaTimeY)
	{
		_finalRotation.Pitch = _finalRotation.Pitch * _input;
	}

	_finalRotation.Yaw = _finalRotation.Yaw * _constant;

	if (_deltaTimeZ)
	{
		_finalRotation.Yaw = _finalRotation.Yaw * _input;
	}

	_comp->AddRelativeRotation(_finalRotation);
}