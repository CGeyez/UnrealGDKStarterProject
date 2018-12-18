// Fill out your copyright notice in the Description page of Project Settings.

#include "TestActor.h"

#include "SpatialNetDriver.h"
#include "SpatialWorkerConnection.h"
#include "TestActorComponent.h"
#include "TestSceneComponent.h"
#include "UnrealNetwork.h"


// Sets default values
ATestActor::ATestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetReplicates(true);

	MyRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(MyRootComponent);

	TestSceneComponent = CreateDefaultSubobject<UTestSceneComponent>(TEXT("TestSceneComponent"));
	TestSceneComponent->SetupAttachment(MyRootComponent);

	TestActorComponent = CreateDefaultSubobject<UTestActorComponent>(TEXT("TestActorComponent"));
}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();
	
	FString WorkerId;
	if (USpatialNetDriver* SpatialNetDriver = Cast<USpatialNetDriver>(GetNetDriver()))
	{
		if (SpatialNetDriver->Connection)
		{
			//WorkerId = SpatialNetDriver->Connection->GetWorkerId();
		}
	}
	UE_LOG(LogTemp, Log, TEXT("DAVEDEBUG %s ATestActor BeginPlay %s %d"), *WorkerId, *TestString, TestInt);

	if (HasAuthority())
	{
		OnRepTestString = TEXT("New string");
	}
}

void ATestActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ATestActor, OnRepTestString);
	DOREPLIFETIME(ATestActor, TestString);
	DOREPLIFETIME(ATestActor, TestInt);
}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!bHasRun)
	{
		bHasRun = true;
		FString WorkerId;
		if (USpatialNetDriver* SpatialNetDriver = Cast<USpatialNetDriver>(GetNetDriver()))
		{
			if (SpatialNetDriver->Connection)
			{
				//WorkerId = SpatialNetDriver->Connection->GetWorkerId();
			}
		}
		UE_LOG(LogTemp, Log, TEXT("DAVEDEBUG %s ATestActor first Tick %s %d"), *WorkerId, *TestString, TestInt);
	}
}

void ATestActor::OnRep_OnRepTestString()
{
	UE_LOG(LogTemp, Log, TEXT("REPLICATED DEBUG %s"), *OnRepTestString);
}
