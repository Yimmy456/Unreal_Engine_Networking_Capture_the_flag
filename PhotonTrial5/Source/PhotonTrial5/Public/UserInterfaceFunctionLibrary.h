// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UserInterfaceFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class PHOTONTRIAL5_API UUserInterfaceFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Set the UI Element Position Based On Scale In the X-Axis (Float)"))
		static void SetUIElementPositionBasedOnScaleInXAxisFloat(FVector2D _sizeInput, float _sizeConstantInput, float _additionalMovementInput, float& _output);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Set the UI Element Position Based On Scale In the Y-Axis (Float)"))
		static void SetUIElementPositionBasedOnScaleInYAxisFloat(FVector2D _sizeInput, float _sizeConstantInput, float _additionalMovementInput, float& _output);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Set the UI Element Position Based On Scale In the X-Axis (Vector2D)"))
		static void SetUIElementPositionBasedOnScaleInXAxisVector2D(FVector2D _sizeInput, float _sizeConstantInput, float _additionalMovementInput, FVector2D& _output);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Set the UI Element Position Based On Scale In the Y-Axis (Vector2D)"))
		static void SetUIElementPositionBasedOnScaleInYAxisVector2D(FVector2D _sizeInput, float _sizeConstantInput, float _additionalMovementInput, FVector2D& _output);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Set the UI Element Position Based On Scale"))
		static void SetUIElementPositionBasedOnScale(FVector2D _sizeInput, float _sizeConstantInput, FVector2D _additionalMovementsInput, FVector2D& _output);
};
