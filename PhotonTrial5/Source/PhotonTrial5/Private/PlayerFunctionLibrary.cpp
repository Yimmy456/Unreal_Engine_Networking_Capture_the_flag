// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerFunctionLibrary.h"

void UPlayerFunctionLibrary::RotateObject(USceneComponent* _comp, float _speed)
{
	FRotator _r;

	_r.Roll = 0.0f;

	_r.Pitch = 0.0f;

	_r.Yaw = _speed;

	_comp->AddRelativeRotation(_r);
}

void UPlayerFunctionLibrary::RotateObjectWithLimit(USceneComponent* _comp, float _speed, float _min, float _max)
{
	FRotator _r;

	_r.Roll = 0.0f;

	_r.Pitch = _speed;

	_r.Yaw = 0.0f;

	FRotator _cr = _comp->GetRelativeRotation();

	_cr.Pitch = _cr.Pitch + _r.Pitch;

	if (_min > _max)
	{
		float _f = _min;

		_min = _max;

		_max = _f;
	}

	if (_cr.Pitch > 180.0f)
	{
		_cr.Pitch = _cr.Pitch - 360.0f;
	}

	if (_cr.Pitch < _min)
	{
		_cr.Pitch = _min;
	}

	if (_cr.Pitch > _max)
	{
		_cr.Pitch = _max;
	}

	_comp->SetRelativeRotation(_cr);
}

FVector UPlayerFunctionLibrary::GetAddedLocation(USceneComponent* _comp, float _speed, float _angle)
{
	if (!(_angle >= 0.0f && _angle < 360.0f))
	{
		return FVector::Zero();
	}

	FVector _forwardDirection = _comp->GetForwardVector();

	_forwardDirection.Z = 0.0f;

	_forwardDirection = _forwardDirection.RotateAngleAxis(_angle, FVector::UpVector);

	_forwardDirection.X = _forwardDirection.X * _speed;

	_forwardDirection.Y = _forwardDirection.Y * _speed;

	return _forwardDirection;
}

void UPlayerFunctionLibrary::MovePlayer(APawn* _player, FVector _rot, float _speed, float _angle)
{
	if (!(_angle >= 0.0f && _angle < 360.0f))
	{
		return;
	}

	_rot.Z = 0.0f;

	_rot.X = _rot.X * _speed;

	_rot.Y = _rot.Y * _speed;

	FVector _finalPos = _player->GetActorLocation();

	_finalPos = _finalPos + _rot;

	_player->SetActorLocation(_finalPos);
	
}

FVector UPlayerFunctionLibrary::GetForwardRot(USceneComponent* _comp, float _angle)
{
	if (!(_angle >= 0.0f && _angle < 360.0f))
	{
		return FVector::Zero();
	}

	FVector _forwardDirection = _comp->GetForwardVector();

	_forwardDirection.Z = 0.0f;

	_forwardDirection = _forwardDirection.RotateAngleAxis(_angle, FVector::UpVector);

	return _forwardDirection;
}

void UPlayerFunctionLibrary::RotatePlayer(USceneComponent* _comp, FRotator _rot, float _angle)
{
	if (!(_angle >= 0.0f && _angle < 360.0f) || _angle == -181.0f)
	{
		return;
	}

	_comp->SetWorldRotation(_rot);
}

FRotator UPlayerFunctionLibrary::GetLookingDirection(USceneComponent* _comp, bool _strafe, float _angle)
{
	if (!(_angle >= 0.0f && _angle < 360.0f))
	{
		return FRotator::ZeroRotator;
	}

	FVector _forwardDirection = _comp->GetForwardVector();

	_forwardDirection.Z = 0.0f;

	if (!_strafe)
	{
		_forwardDirection = _forwardDirection.RotateAngleAxis(_angle, FVector::UpVector);
	}

	return _forwardDirection.Rotation();
}