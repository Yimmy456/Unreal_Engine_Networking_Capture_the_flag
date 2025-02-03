// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlayerFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class PHOTONTRIAL5_API UPlayerFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
		static void RotateObject(USceneComponent* _comp, float _speed);

	UFUNCTION(BlueprintCallable)
		static void RotateObjectWithLimit(USceneComponent* _comp, float _speed, float _min, float _max);

	UFUNCTION(BlueprintCallable)
		static FVector GetAddedLocation(USceneComponent* _comp, float _speed, float _angle);

	UFUNCTION(BlueprintCallable)
		static void MovePlayer(APawn* _player, FVector _rot, float _speed, float _angle);
	
	UFUNCTION(BlueprintCallable)
		static FVector GetForwardRot(USceneComponent* _comp, float _angle);

	UFUNCTION(BlueprintCallable)
		static void RotatePlayer(USceneComponent* _comp, FRotator _rot, float _angle);

	UFUNCTION(BlueprintCallable)
		static FRotator GetLookingDirection(USceneComponent* _comp, bool _strafe, float _angle);

	UFUNCTION(BlueprintPure)
	static void SetColorValue(FLinearColor _colorInput, float _valueInput, bool _multiplayByCurrentValueInput, float _alphaInput, FLinearColor& _colorOutput);

};
