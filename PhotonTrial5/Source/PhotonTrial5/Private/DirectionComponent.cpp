// Fill out your copyright notice in the Description page of Project Settings.


#include "DirectionComponent.h"
#include <cmath>

// Sets default values for this component's properties
UDirectionComponent::UDirectionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDirectionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

	_directionAngle = -181.0f;

	_coterminalDirectionAngle = -181.0f;

	_directionVector = FVector2D::Zero();
	
}


// Called every frame
void UDirectionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UDirectionComponent::CalculateDirectionAngle(FVector2D _input)
{
	if (_input.X == 0.0f && _input.Y == 0.0f)
	{
		_directionAngle = -181.0f;
		_coterminalDirectionAngle = -181.0f;
		_directionVector = FVector2D::Zero();
		return;
	}

	_directionAngle = atan2(_input.X, _input.Y);

	_directionAngle = (_directionAngle * 180.0f) / PI;

	_coterminalDirectionAngle = _directionAngle;

	if (_coterminalDirectionAngle < 0.0f)
	{
		_coterminalDirectionAngle = _coterminalDirectionAngle + 360.0f;
	}

	CalculateDirectionVector();
}

void UDirectionComponent::CalculateDirectionVector()
{
	if (_directionAngle >= -67.5f && _directionAngle <= 67.5f)
	{
		_directionVector.Y = 1.0f;
	}
	else if (_directionAngle <= -112.5f || _directionAngle >= 112.5f)
	{
		_directionVector.Y = -1.0f;
	}
	else {
		_directionVector.Y = 0.0f;
	}

	if (_directionAngle >= 22.5f && _directionAngle <= 157.5f)
	{
		_directionVector.X = 1.0f;
	}
	else if (_directionAngle <= -22.5f && _directionAngle >= -157.5f)
	{
		_directionVector.X = -1.0f;
	}
	else {
		_directionVector.X = 0.0f;
	}
}

float UDirectionComponent::GetDirectionAngle()
{
	return _directionAngle;
}

float UDirectionComponent::GetCoterminalDirectionAngle()
{
	return _coterminalDirectionAngle;
}

FVector2D UDirectionComponent::GetDirectionVector()
{
	return _directionVector;
}