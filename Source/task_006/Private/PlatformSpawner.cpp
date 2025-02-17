#include "PlatformSpawner.h"
#include "TimerPlatform.h"
#include "RandomPlatform.h"

APlatformSpawner::APlatformSpawner()
{
	PrimaryActorTick.bCanEverTick = true;

	NumOfSpawn = 10;
	SpawnRange = 500.0f;

}


void APlatformSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	for (int i = 0; i < NumOfSpawn; i++)
	{
		if (PlatformsToSpawn.Num() > 0)
		{
			RandomValue.X = FMath::RandRange(-1.0f * SpawnRange, SpawnRange);
			RandomValue.Y = FMath::RandRange(-1.0f * SpawnRange, SpawnRange);
			RandomValue.Z = FMath::RandRange(50.0f, 300.0f); //임의로 숫자 지정	
			const int32 ClassIndex = FMath::RandRange(0, PlatformsToSpawn.Num() - 1);
			TSubclassOf<ARandomPlatform> Pick = PlatformsToSpawn[ClassIndex];

			FVector SpawnLocation(RandomValue);
			FRotator SpawnRotation = FRotator::ZeroRotator;

			FActorSpawnParameters SpawnParams;
			GetWorld()->SpawnActor<ARandomPlatform>(Pick, SpawnLocation, SpawnRotation, SpawnParams);
		}

		else
		{
			UE_LOG(LogTemp, Warning, TEXT("error"));
		}
	}
}

void APlatformSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

