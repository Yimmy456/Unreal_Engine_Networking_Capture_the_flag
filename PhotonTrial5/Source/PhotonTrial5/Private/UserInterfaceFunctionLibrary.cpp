// Fill out your copyright notice in the Description page of Project Settings.


#include "UserInterfaceFunctionLibrary.h"

void UUserInterfaceFunctionLibrary::SetUIElementPositionBasedOnScaleInXAxisFloat(FVector2D _sizeInput, float _sizeConstantInput, float _additionalMovementInput, float& _output)
{
	float _v = (_sizeInput.X / 2.0f) - ((_sizeInput.X * _sizeConstantInput) / 2.0f);

	_output = _v + _additionalMovementInput;
}

void UUserInterfaceFunctionLibrary::SetUIElementPositionBasedOnScaleInYAxisFloat(FVector2D _sizeInput, float _sizeConstantInput, float _additionalMovementInput, float& _output)
{
	float _v = (_sizeInput.Y / 2.0f) - ((_sizeInput.Y * _sizeConstantInput) / 2.0f);

	_output = _v + _additionalMovementInput;
}

void UUserInterfaceFunctionLibrary::SetUIElementPositionBasedOnScaleInXAxisVector2D(FVector2D _sizeInput, float _sizeConstantInput, float _additionalMovementInput, FVector2D& _output)
{
	float _v = (_sizeInput.X / 2.0f) - ((_sizeInput.X * _sizeConstantInput) / 2.0f);

	FVector2D _v2D;

	_v2D.X = _v + _additionalMovementInput;

	_v2D.Y = 0.0f;

	_output = _v2D;
}

void UUserInterfaceFunctionLibrary::SetUIElementPositionBasedOnScaleInYAxisVector2D(FVector2D _sizeInput, float _sizeConstantInput, float _additionalMovementInput, FVector2D& _output)
{
	float _v = (_sizeInput.Y / 2.0f) - ((_sizeInput.Y * _sizeConstantInput) / 2.0f);

	FVector2D _v2D;

	_v2D.X = 0.0f;

	_v2D.Y = _v + _additionalMovementInput;

	_output = _v2D;
}

void UUserInterfaceFunctionLibrary::SetUIElementPositionBasedOnScale(FVector2D _sizeInput, float _sizeConstantInput, FVector2D _additionalMovementsInput, FVector2D& _output)
{
	FVector2D _v;

	_v.X = (_sizeInput.X / 2.0f) - ((_sizeInput.X * _sizeConstantInput) / 2.0f);

	_v.Y = (_sizeInput.Y / 2.0f) - ((_sizeInput.Y * _sizeConstantInput) / 2.0f);

	_output = _v + _additionalMovementsInput;
}