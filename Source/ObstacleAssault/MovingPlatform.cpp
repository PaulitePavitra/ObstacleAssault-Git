// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void myTestFunction() {
	UE_LOG(LogTemp, Display, TEXT("My function which i made yay"));
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	myTestFunction();
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);

}


void AMovingPlatform::MovePlatform(float DeltaTime) {
	FVector CurrentLocation = GetActorLocation();
	CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
	SetActorLocation(CurrentLocation);
	DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);
	if (DistanceMoved >= MoveDistance) {
		//FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		//FVector NewStartLocation = StartLocation + MoveDirection * MoveDistance;
		//SetActorLocation(NewStartLocation);
		//StartLocation = NewStartLocation;
		PlatformVelocity = -PlatformVelocity;
		StartLocation = CurrentLocation;
		
	}
}


void AMovingPlatform::RotatePlatform(float DeltaTime) {
	AddActorLocalRotation(RotationVelocity * DeltaTime);
}