// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RotationComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PHOTONTRIAL5_API URotationComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URotationComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintType, EditAnywhere)
		bool _rotate;

	UPROPERTY(BlueprintType, EditAnywhere)
		FRotator _axis;

	UPROPERTY(BlueprintType, EditAnywhere)
		float _constant;

	UPROPERTY(BlueprintType, EditAnywhere)
		bool _deltaTimeX;

	UPROPERTY(BlueprintType, EditAnywhere)
		bool _deltaTimeY;

	UPROPERTY(BlueprintType, EditAnywhere)
		bool _deltaTimeZ;

	UPROPERTY(BlueprintType, EditAnywhere)
		USceneComponent* _comp;

	FRotator _finalRotation;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintPure)
		bool GetRotate();

	UFUNCTION(BlueprintPure)
		FRotator GetAxis();

	UFUNCTION(BlueprintPure)
		float GetConstant();

	UFUNCTION(BlueprintPure)
		bool GetDeltaTimeX();

	UFUNCTION(BlueprintPure)
		bool GetDeltaTimeY();

	UFUNCTION(BlueprintPure)
		bool GetDeltaTimeZ();

	UFUNCTION(BlueprintPure)
		USceneComponent* GetComp();

	UFUNCTION(BlueprintPure)
		FRotator GetFinalRotation();


	UFUNCTION(BlueprintCallable)
		void SetRotate(bool _input);

	UFUNCTION(BlueprintCallable)
		void SetAxis(FRotator _input);

	UFUNCTION(BlueprintCallable)
		void SetConstant(float _input);

	UFUNCTION(BlueprintCallable)
		void SetDeltaTimeX(bool _input);

	UFUNCTION(BlueprintCallable)
		void SetDeltaTimeY(bool _input);

	UFUNCTION(BlueprintCallable)
		void SetDeltaTimeZ(bool _input);

	UFUNCTION(BlueprintCallable)
		void SetComp(USceneComponent* _input);

	UFUNCTION(BlueprintCallable)
		void RotateComp(float _input);
		
};
