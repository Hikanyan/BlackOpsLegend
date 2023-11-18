// Fill out your copyright notice in the Description page of Project Settings.
// 編集者：薄衣　毅
//　編集日：2023/11/11

#include "BlackOpsLegend/Members/Usugi/FPSChara.h"
#include "Kismet/GameplayStatics.h"
#include "EnvironmentQuery/EnvQueryTypes.h"

// Sets default values
AFPSChara::AFPSChara()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a first person camera component.
	FPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	check(FPSCameraComponent != nullptr);

	// Attach the camera component to our capsule component.
	FPSCameraComponent->SetupAttachment(CastChecked<USceneComponent, UCapsuleComponent>(GetCapsuleComponent()));

	// Position the camera slightly above the eyes.
	FPSCameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f + BaseEyeHeight));

	// Enable the pawn to control camera rotation.
	FPSCameraComponent->bUsePawnControlRotation = true;

	// Create a first person mesh component for the owning player.
	FPSMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPersonMesh"));
	check(FPSMesh != nullptr);

	// Only the owning player sees this mesh.
	FPSMesh->SetOnlyOwnerSee(true);

	// Attach the FPS mesh to the FPS camera.
	FPSMesh->SetupAttachment(FPSCameraComponent);

	// Disable some environmental shadows to preserve the illusion of having a single mesh.
	FPSMesh->bCastDynamicShadow = false;
	FPSMesh->CastShadow = false;

	// The owning player doesn't see the regular (third-person) body mesh.
	GetMesh()->SetOwnerNoSee(true);
}

// Called when the game starts or when spawned
void AFPSChara::BeginPlay()
{
	Super::BeginPlay();

	check(GEngine != nullptr);

	// Display a debug message for five seconds. 
	// The -1 "Key" value argument prevents the message from being updated or refreshed.
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("We are using FPSCharacter."));
}

// Called every frame
void AFPSChara::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPSChara::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// Set up "movement" bindings.
	PlayerInputComponent->BindAxis("MoveForward", this, &AFPSChara::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFPSChara::MoveRight);
	// Set up "look" bindings.
	PlayerInputComponent->BindAxis("Turn", this, &AFPSChara::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AFPSChara::AddControllerPitchInput);
	// Set up "action" bindings.
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AFPSChara::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AFPSChara::StopJump);

	
}

void AFPSChara::StartJump()
{
	bPressedJump = true;
}

void AFPSChara::StopJump()
{
	bPressedJump = false;
}

void AFPSChara::MoveForward(float Value)
{
	// Find out which way is "forward" and record that the player wants to move that way.
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);
}

void AFPSChara::MoveRight(float Value)
{
	// Find out which way is "right" and record that the player wants to move that way.
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}
