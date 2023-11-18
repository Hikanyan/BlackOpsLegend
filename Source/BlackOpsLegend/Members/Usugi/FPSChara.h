// Fill out your copyright notice in the Description page of Project Settings.
// 編集者：薄衣　毅
//　編集日：2023/11/11

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "FPSChara.generated.h"

UCLASS()
class BLACKOPSLEGEND_API AFPSChara : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSChara();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UFUNCTION()
    void MoveForward(float Value);

    // Handles input for moving right and left.
    UFUNCTION()
    void MoveRight(float Value);

	UFUNCTION()
	void StartJump();

	// Clears jump flag when key is released.
	UFUNCTION()
	void StopJump();

	// FPS camera.
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* FPSCameraComponent;
};
