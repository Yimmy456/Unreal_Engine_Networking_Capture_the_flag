// Fill out your copyright notice in the Description page of Project Settings.


#include "UserInterfaceFunctionLibrary.h"

void UUserInterfaceFunctionLibrary::SetUIElementPositionBasedOnScaleInXAxis(FVector2D _sizeInput, float _sizeConstantInput, float _additionalMovement, float& _output)
{
	float _v = (_sizeInput.X / 2.0f) - ((_sizeInput.X * _sizeConstantInput) / 2.0f);

	_output = _v + _additionalMovement;
}

void UUserInterfaceFunctionLibrary::SetUIElementPositionBasedOnScaleInYAxis(FVector2D _sizeInput, float _sizeConstantInput, float _additionalMovement, float& _output)
{
	float _v = (_sizeInput.Y / 2.0f) - ((_sizeInput.Y * _sizeConstantInput) / 2.0f);

	_output = _v + _additionalMovement;
}

void UUserInterfaceFunctionLibrary::SetUIElementPositionBasedOnScale(FVector2D _sizeInput, float _sizeConstantInput, FVector2D _additionalMovements, FVector2D& _output)
{
	FVector2D _v;

	_v.X = (_sizeInput.X / 2.0f) - ((_sizeInput.X * _sizeConstantInput) / 2.0f);

	_v.Y = (_sizeInput.Y / 2.0f) - ((_sizeInput.Y * _sizeConstantInput) / 2.0f);

	_output = _v + _additionalMovements;
}