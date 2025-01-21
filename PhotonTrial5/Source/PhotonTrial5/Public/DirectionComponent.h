// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DirectionComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PHOTONTRIAL5_API UDirectionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDirectionComponent();

private:

	void CalculateDirectionVector();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	float _directionAngle;

	float _coterminalDirectionAngle;

	FVector2D _directionVector;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
		void CalculateDirectionAngle(FVector2D _input);

	UFUNCTION(BlueprintPure)
		float GetDirectionAngle();

	UFUNCTION(BlueprintPure)
		float GetCoterminalDirectionAngle();

	UFUNCTION(BlueprintPure)
		FVector2D GetDirectionVector();
};
