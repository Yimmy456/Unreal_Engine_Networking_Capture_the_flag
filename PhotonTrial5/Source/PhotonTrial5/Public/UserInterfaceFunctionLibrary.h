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

	UFUNCTION(BlueprintCallable, BlueprintPure)
		static void SetUIElementPositionBasedOnScaleInXAxis(FVector2D _sizeInput, float _sizeConstantInput, float _additionalMovements, float& _output);

	UFUNCTION(BlueprintCallable, BlueprintPure)
		static void SetUIElementPositionBasedOnScaleInYAxis(FVector2D _sizeInput, float _sizeConstantInput, float _additionalMovements, float& _output);

	UFUNCTION(BlueprintCallable, BlueprintPure)
		static void SetUIElementPositionBasedOnScale(FVector2D _sizeInput, float _sizeConstantInput, FVector2D _additionalMovements, FVector2D& _output);
};
